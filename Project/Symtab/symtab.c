/* symtab.c
 * Functions for the symbol table.
 * Written by THC for CS 57.
 * You should extend the functions as appropriate.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symtab.h"

#define NOHASHSLOT -1

static int g_var_sn = 0;	/* current "serial number" for id's */
static int g_func_sn = 0;	/* number of functions */
static int g_addr = 100;	/* temp var */
static int g_func_addr = 1000;	/* temp var */
extern int hzDEBUG;
static int g_cur_sn = 0;	/* cur function scope */

int sym_error = 0;		/* non-zero means sym_error errors detected */
/*
 * Functions for symnodes.
 */

/* Create a symnode and return a pointer to it. */
static symnode create_symnode(char *name) {
  symnode node = malloc(sizeof(struct symnode));
  node->name = strdup(name);
  node->next = NULL;
  return node;
}

/* Destroy a symnode. */
static void destroy_symnode(symnode node) {
  free(node->name);
  free(node);
}

/* Set the name in this node. */
void set_node_name(symnode node, char *name) {
  if (node->name != NULL)
    free(node->name);
  node->name = strdup(name);
}

/* Does the identifier in this node equal name? */
int name_is_equal(symnode node, char *name) {
  return !strcmp(node->name, name);
}


/*
 * Functions for symhashtables.
 */

/* Create an empty symhashtable and return a pointer to it.  The
   parameter entries gives the initial size of the table. */
static symhashtable create_symhashtable(int entries) {
  symhashtable hashtable = malloc(sizeof(struct symhashtable));
  hashtable->size = entries;
  hashtable->table = calloc(entries, sizeof(struct symnode));
  int i;
  for (i = 0; i < entries; i++)
    hashtable->table[i] = NULL;
  hashtable->outer_scope = NULL;
  hashtable->level = -1;
  return hashtable;
}

/* Destroy a symhashtable. */
static void destroy_symhashtable(symhashtable hashtable) {
  int i;
  for (i = 0; i < hashtable->size; i++) {
    symnode node, next;

    for (node = hashtable->table[i]; node != NULL; node = next) {
      next = node->next;
      destroy_symnode(node);
    }
  }
}

/* Peter Weinberger's hash function, from Aho, Sethi, & Ullman
   p. 436. */
static int hashPJW(char *s, int size) {
  unsigned h = 0, g;
  char *p;

  for (p = s; *p != '\0'; p++) {
      h = (h << 4) + *p;
      if ((g = (h & 0xf0000000)) != 0)
	h ^= (g >> 24) ^ g;
    }

  return h % size;
}

/* Look up an entry in a symhashtable, returning either a pointer to
   the symnode for the entry or NULL.  slot is where to look; if slot
   == NOHASHSLOT, then apply the hash function to figure it out. */
static symnode lookup_symhashtable(symhashtable hashtable, char *name,
				   int slot) {
  symnode node;

  if (slot == NOHASHSLOT)
    slot = hashPJW(name, hashtable->size);

  for (node = hashtable->table[slot];
       node != NULL && !name_is_equal(node, name);
       node = node->next)
    ;

  return node;
}

/* Insert a new entry into a symhashtable, but only if it is not
   already present. */
static symnode insert_into_symhashtable(symhashtable hashtable, char *name, int sn) {
  int slot = hashPJW(name, hashtable->size);
  symnode node = lookup_symhashtable(hashtable, name, slot);

  if (node == NULL) {
    node = create_symnode(name);
    node->next = hashtable->table[slot];
    // add by Huizhe Li
    node->sn = sn;
    hashtable->table[slot] = node;
  }

  return node;
}


/*
 * Functions for symboltables.
 */

static const int HASHSIZE = 211;

/* Create an empty symbol table. */
symboltable create_symboltable() {
  symboltable symtab = malloc(sizeof(struct symboltable));
  symtab->inner_scope = create_symhashtable(HASHSIZE);
  symtab->inner_scope->outer_scope = NULL;
  symtab->inner_scope->level = 0;
  return symtab;
}

/* Destroy a symbol table. */
void destroy_symboltable(symboltable symtab) {
  symhashtable table, outer;

  for (table = symtab->inner_scope; table != NULL; table = outer) {
    outer = table->outer_scope;
    destroy_symhashtable(table);
  }
}

/* Insert an entry into the innermost scope of symbol table.  First
   make sure it's not already in that scope.  Return a pointer to the
   entry. */
symnode insert_into_symboltable(symboltable symtab, char *name, int sn) {
  if (symtab->inner_scope == NULL) {
    fprintf(stderr, "Error: inserting into an empty symbol table\n");
    exit(1);
  }

  symnode node = lookup_symhashtable(symtab->inner_scope, name, NOHASHSLOT);

  if (node == NULL)
    node = insert_into_symhashtable(symtab->inner_scope, name, sn);

  return node;
}

/* Lookup an entry in a symbol table.  If found return a pointer to it
   and fill in level.  Otherwise, return NULL and level is
   undefined. */
symnode lookup_in_symboltable(symboltable symtab, char *name, int *level) {
  symnode node;
  symhashtable hashtable;

  for (node = NULL, hashtable = symtab->inner_scope;
       node == NULL && hashtable != NULL;
       hashtable = hashtable->outer_scope) {
    node = lookup_symhashtable(hashtable, name, NOHASHSLOT);
    *level = hashtable->level;
  }

  return node;
}

/* Enter a new scope. */
void enter_scope(symboltable symtab) {
  symhashtable hashtable = create_symhashtable(HASHSIZE);
  hashtable->outer_scope = symtab->inner_scope;
  hashtable->level = symtab->inner_scope->level + 1;
  symtab->inner_scope = hashtable;
}

/* Leave a scope. */
void leave_scope(symboltable symtab) {
  symhashtable hashtable = symtab->inner_scope;
  symtab->inner_scope = hashtable->outer_scope;
  destroy_symhashtable(hashtable);
}

/* ------------------------------ by Huizhe Li -----------------------------*/

/* Create an empty flat table */
flat_symtab create_flat_symtab()
{
  flat_symtab var_table = (flat_symtab)malloc(sizeof(struct flat_symtab));
  var_table->size = 0;
  return var_table;
}

/* Change current scope of the tracking symbol table */
static void change_current_scope(symboltable tracking_table, ast_node root)
{
  while (tracking_table->inner_scope->level != root->scope){
    if (tracking_table->inner_scope->level < root->scope)
      enter_scope(tracking_table);
    else
      leave_scope(tracking_table);
  }
  
  if(root->node_type == CMPD_STMT 
     //&& root->scope > 0
     ){
    leave_scope(tracking_table);
    enter_scope(tracking_table);
    }
}

/* Convert from string literal to storage_class */
static storage_class convert_to_sclass(char* str)
{
  if (strcmp(str, "CONST") == 0)
    return STORAGE_CONST;
  else
    return STORAGE_NORMAL;
}

/* Convert from string literal to data_type */
static data_type convert_to_dtype(char* str)
{
  if (strcmp(str, "INT") == 0)
    return TYPE_INT;
  else if (strcmp(str, "INT ARRAY") == 0)
    return TYPE_INT_ARRAY;
  else if (strcmp(str, "DOUBLE") == 0)
    return TYPE_DOUBLE;
  else if (strcmp(str, "DOUBLE ARRAY") == 0)
    return TYPE_DOUBLE_ARRAY;
  else
    return TYPE_VOID;
}

/* Create an entry */
static symtab_entry create_symtab_entry(char* id, int lineNumber, data_type dtype, storage_class sclass, int addr, int sn)
{
  symtab_entry entry = (symtab_entry)malloc(sizeof(struct symtab_entry));
  entry->id = strdup(id);
  entry->lineNumber = lineNumber;
  entry->dtype = dtype;
  entry->sclass = sclass;
  entry->addr = addr;
  entry->sn = sn;
  return entry;
}

/* Insert an entry into the flat symbol table, return 0 on success */
static int insert_flat_table_entry(flat_symtab table, symtab_entry entry)
{
  if (table->size == MAXTABLEN)
    return -1;
  table->entries[table->size++] = entry;
  return 0;
}

/* retrieve an entry pointer from the flat symbol table */
static symtab_entry retrieve_entry(flat_symtab var_table, int sn)
{
  return var_table->entries[sn];
}

/* Look up a function id in the given function table.
 * Return NULL if not found, otherwise return the pointer to the entry
 */
static func_entry lookup_in_functable(func_table function_table, char* name)
{
  int i;
  func_entry* entries = function_table->entries;
  for (i = 0; i < function_table->size; i++){
    if (strcmp(name, entries[i]->id) == 0)
      return entries[i];
  }
  return NULL;
}

/* Create an empty function table */
func_table create_functable()
{
  func_table table = (func_table)malloc(sizeof(struct func_table));
  table->size = 0;
  return table;
}

/* Create a func_entry */
static func_entry create_func_entry(char* name, data_type dtype, int argc, char* args[], 
				    data_type types[], storage_class sclasses[], int addr[], int sn, int f_addr, int def)
{
  func_entry entry = (func_entry)malloc(sizeof(struct func_entry));
  int i;
  
  entry->id = strdup(name);
  entry->dtype = dtype;
  entry->argc = argc;
  for(i = 0; i < argc; i++){
    entry->args[i] = strdup(args[i]);
    entry->types[i] = types[i];
    entry->sclasses[i] = sclasses[i];
    entry->addr[i] = addr[i];
  }
  entry->sn = sn;
  entry->func_addr = f_addr;
  entry->def = def;
  return entry;
}

/* Insert a function entry into function table */
static int insert_func_table(func_table function_table, func_entry entry)
{
  if(function_table->size == MAXTABLEN){
    printf(" --- error --- function table full.\n");
    sym_error++;
    return -1;
  }

  function_table->entries[function_table->size++] = entry;
  return 0;
}

/* Fetch info for the id as a param of the current function
 * return pointer to the entry, or NULL if not found
 * The third param indicates the index for the param found,
 * or undefined if NULL returnd.
 */
symtab_entry retrieve_param(func_table function_table, int sn, char* name)
{
  func_entry entry = function_table->entries[sn];	// entry containing current function
  int i;
  for(i = 0; i < entry->argc; i++){
    if (strcmp(entry->args[i], name)==0){	
      return create_symtab_entry("", 0, entry->types[i], entry->sclasses[i], entry->addr[i], -1);
    }
  }
  return NULL;
}
  
/* Check compatibility between two fun declarations */
int check_func_comp(func_entry entry, ast_node decl)
{
  int argc;
  ast_node temp;
  data_type dtype;     
  storage_class sclass;

  // check return type
  dtype = convert_to_dtype(decl->left_child->left_child->value.string);
  if (dtype != entry->dtype)
    return -1;

  // check  params
  temp = decl->left_child->right_sibling;
  if (temp->left_child->node_type == TYPE){
    if (entry->argc != 0)
      return -1;
    else
      return 0;
  }else{
    argc = 0;
    for(temp = temp->left_child; temp != NULL; temp = temp->right_sibling){
      if (convert_to_sclass(temp->left_child->value.string) != entry->sclasses[argc])
	return -1;
      if (convert_to_dtype(temp->left_child->right_sibling->value.string)
	  != entry->types[argc])
	return -1;
      argc++;
    }
    if(argc != entry->argc)
      return -1;
    else
      return 0;
  }
}
	
  
/* Build the flat symbol table */
void build_symtab(symboltable tracking_table, flat_symtab var_table, func_table function_table, ast_node root)
{
  char* name;
  symnode sym_node;

  // for flat table entry
  storage_class sclass;
  data_type dtype;
  int addr;
  int lineNumber;
  symtab_entry entry;
  int rc;

  // for lookup_in_symboltable
  int scope_level;

  // for function tables
  func_entry fEntry;
  
  // recursively build symtab
  ast_node child;
  ast_node temp, temp2;
  int argc;
  char* args[MAXARGS];
  data_type types[MAXARGS];
  storage_class sclasses[MAXARGS];
  int f_addr[MAXARGS];

  // Change current scope 
  change_current_scope(tracking_table, root);

  // Act according to node type 
  switch(root->node_type){
  case VAR_DECL:
    name = root->left_child->right_sibling->right_sibling->value.string;	// get the id's name

    // first look-up in the closest function's symtab, see whether the id is an argument
    if(retrieve_param(function_table, g_cur_sn, name)!= NULL){	
      printf("--- error --- var decl conflicts with function param at line %d.\n", 
	     root->left_child->right_sibling->right_sibling->lineNumber);
    }

    // look up the id in var_table. insert on NULL, report duplicate definition error otherwise
    sym_node = lookup_symhashtable(tracking_table->inner_scope, name, NOHASHSLOT);    
    if (sym_node == NULL){ // id not found in the current level
      /* assign sn for this id and mark it visited */
      root->left_child->right_sibling->right_sibling->sn = g_var_sn;
      root->left_child->right_sibling->right_sibling->flag_visited = 1;

      // insert a new entry into the tracking table
      sym_node = insert_into_symboltable(tracking_table, name, g_var_sn);

      // insert a new entry into the flat table
      sclass = convert_to_sclass(root->left_child->value.string);
      dtype = convert_to_dtype(root->left_child->right_sibling->value.string);
      addr = g_addr++; // mark: put it here for now;
      lineNumber = root->left_child->right_sibling->right_sibling->lineNumber;

      entry = create_symtab_entry(name, lineNumber, dtype, sclass, addr, g_var_sn);	// create entry

      rc =  insert_flat_table_entry(var_table, entry);	// insert the entry into flat table

      if (rc != 0){
	printf(" --- error --- var_table full. Abort.\n");
	sym_error++;
	return;
      }
      g_var_sn++;	/* since new id */
    }else{	// redefinition error
      printf(" --- error --- duplicate var definition at line %d. Symtab may behave abnormally.\n", 
	     root->left_child->right_sibling->right_sibling->lineNumber);
      sym_error++;
    }
    break;
    
  case IDENTIFIER:
    if (root->flag_visited == 1)  break;	// do what it says
    name = root->value.string;	// get the id's name
    
    // first lookup in func_tab, see whether it's an argument
    entry = retrieve_param(function_table, g_cur_sn, name);	// fetch info for the id as a param of the current function
    if (entry != NULL){	// the name is an argument in current function scope
      root->sn = g_var_sn;
      // build the entry
      entry->id = strdup(name);
      entry->lineNumber = root->lineNumber;
      entry->sn = g_var_sn;
      
      // insert the entry
      rc = insert_flat_table_entry(var_table, entry);
      if (rc != 0){		
	printf("--- error --- var_table full. Abort.\n");
	sym_error++;
	return;
      }
      g_var_sn++;
      break;
    }
    // look up the id in the tracking table, report use without definition error on NULL
    // otherwise insert a new entry into var_table
    sym_node = lookup_in_symboltable(tracking_table, name, &scope_level);
    
    if (sym_node == NULL){
      printf("--- error --- variable used without definition at line %d.\n", root->lineNumber);
      sym_error++;
    }else{
      // look up this id and retrieve info from var_table
      root->sn = g_var_sn;
      entry = retrieve_entry(var_table, sym_node->sn);
      sclass = entry->sclass;
      dtype = entry->dtype;
      addr = entry->addr;
      lineNumber = root->lineNumber;

      // build entry and insert
      entry = create_symtab_entry(name, lineNumber, dtype, sclass, addr, g_var_sn);

      // insert the entry
      rc = insert_flat_table_entry(var_table, entry);
      if (rc != 0){		
	printf("--- error --- var_table full. Abort.\n");
	sym_error++;
	return;
      }
      g_var_sn++;	// since new id 
    }
    break;

  case FUNC_DECL:
    temp = root->left_child->left_child->right_sibling;	// point to IDENTIFER node
    temp->flag_visited = 1;
    name = temp->value.string;	// get func id
    // look up the id in func_table
    fEntry = lookup_in_functable(function_table, name);
    if (fEntry != NULL){	// declaration may exist, check
      if (fEntry->def == 1){
	printf("--- error --- duplicate function definition at line %d.\n",
	       root->lineNumber);
	sym_error++;
      }
      else{
	rc = check_func_comp(fEntry, root);
	if (rc != 0){
	  printf("--- error --- incompatible function definition at line %d.\n", temp->lineNumber);
	  sym_error++;
	}

	// now re-write root node with formal definition info
	// ONLY need to write arg names, their addr and func addr
	temp = root->left_child->right_sibling;	// point to the PARAMS node
	if (temp != NULL) { 
	  argc = 0;
	  if (temp->left_child->node_type != TYPE){	// param-list not empty
	    for(temp = temp->left_child; temp != NULL; temp = temp->right_sibling){
	      fEntry->args[argc] = temp->left_child->right_sibling->right_sibling->value.string;
	      fEntry->addr[argc] = g_addr++;
	      argc++;
	    }
	  }
	}
	fEntry->func_addr = g_func_addr;
	fEntry->def = 1;
	g_func_addr++;
	// use the reserved sn
	root->left_child->left_child->right_sibling->sn = fEntry->sn;
	g_cur_sn = fEntry->sn;
      }
    }else{	// insert this function into function table
      // set sn
      temp->sn = g_func_sn;
      g_cur_sn = g_func_sn;

      // build and insert entry if necessary
      dtype = convert_to_dtype(root->left_child->left_child->value.string);
      temp = root->left_child->right_sibling;	// point to the PARAMS node
      if (temp != NULL) { 
	argc = 0;
	if (temp->left_child->node_type != TYPE){	// param-list not empty
	  for(temp = temp->left_child; temp != NULL; temp = temp->right_sibling){
	    args[argc] = temp->left_child->right_sibling->right_sibling->value.string;
	    types[argc] = convert_to_dtype(temp->left_child->right_sibling->value.string);
	    sclasses[argc] = convert_to_sclass(temp->left_child->value.string);
	    f_addr[argc] = g_addr++;
	    argc++;
	  }
	}
	fEntry = create_func_entry(name, dtype, argc, args, types, sclasses, f_addr, g_func_sn, g_func_addr, 1);

	// insert entry
	rc = insert_func_table(function_table, fEntry);
	if (rc != 0){		
	  printf(" --- error --- var_table full. Abort.\n");
	  sym_error++;	
	  return;
	} 
      }
      g_func_sn++;
      g_func_addr++;
    }
    break;
      
  case CALL:
    root->left_child->flag_visited = 1;
    name = root->left_child->value.string;
    fEntry = lookup_in_functable(function_table, name);
    if (fEntry == NULL){
      printf("--- error --- function %s cannot be resolved.\n", name);
      sym_error++;
    }else{	// insert id into flat table
      root->left_child->sn = g_var_sn;
      addr = fEntry->func_addr;
      dtype = fEntry->dtype;
      lineNumber = root->left_child->lineNumber;

      // build entry and insert
      entry = create_symtab_entry(name, lineNumber, dtype, -1, addr, g_var_sn);

      // insert the entry
      rc = insert_flat_table_entry(var_table, entry);
      if (rc != 0){		
	printf("--- error --- var_table full. Abort.\n");
	sym_error++;
	return;
      }
      g_var_sn++;	// since new id 
    }
    break;

  case FUNC_PROTO:
    temp = root->left_child->left_child->right_sibling;	// ID node
    temp->flag_visited = 1;
    name = temp->value.string;
    fEntry = lookup_in_functable(function_table, name);
    if (fEntry == NULL){	// insert 
      dtype = convert_to_dtype(root->left_child->left_child->value.string);
      temp = root->left_child->right_sibling;	// PARAMS NODE
      if (temp != NULL){
	argc = 0;
	if (temp->left_child->node_type != TYPE){	// param-list not empty
	  for(temp = temp->left_child; temp != NULL; temp = temp->right_sibling){
	    types[argc] = convert_to_dtype(temp->left_child->right_sibling->value.string);
	    sclasses[argc] = convert_to_sclass(temp->left_child->value.string);
	    args[argc] = "trivial";
	    argc++;
	    // do not need id and addr
	  }
	}
	fEntry = create_func_entry(name, dtype, argc, args, types, sclasses, f_addr, g_func_sn, -1, 0);	// 0 for proto
	
	// insert entry
	rc = insert_func_table(function_table, fEntry);
	if (rc != 0){		
	  printf("--- error --- var_table full. Abort.\n");
	  sym_error++;	
	  return;
	} 
      }
    }else{	// previous def/decl exist. check compatibility
      rc = check_func_comp(fEntry, root);      
      if (rc != 0){
	printf("--- error --- incompatible function declaration at line %d.\n", temp->lineNumber);
	sym_error++;
      }
    }

    // mark all argument nodes as visited, ignoring them 
    temp = root->left_child->right_sibling;	// PARAMS NODE
    if (temp != NULL){
      if (temp->left_child->node_type != TYPE){
	for(temp = temp->left_child; temp != NULL; temp = temp->right_sibling){
	  temp2 = temp->left_child->right_sibling->right_sibling;	// ID node or NULL
	  if (temp2 != NULL)
	    temp2->flag_visited = 1;
	}
      }
    }
    // don't increment g_func_sn and g_func_addr for a prototype
    g_func_sn++;
    break;
  default:
    break;
  }

  // Pre-order traverse the subtree
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    build_symtab(tracking_table, var_table, function_table, child);
}

/* Print the flat table, for debug mode only */
void print_flat_table(flat_symtab var_table)
{
  int i;
  for (i = 0; i < var_table->size; i++){
    printf("-- entry -- id: %s\tline number: %d  \tdata type: %d\taddress: %d\tsn: %d\n",
	   var_table->entries[i]->id, var_table->entries[i]->lineNumber, 
	   var_table->entries[i]->dtype, var_table->entries[i]->addr, var_table->entries[i]->sn);
  }
  printf("\n");
}

/* Print the function table */
void print_func_table(func_table function_table)
{
  int i;
  int j;
  func_entry entry;
  for (i = 0; i < function_table->size; i++){
    entry = function_table->entries[i];
    printf("-- func_entry -- id: %s\tret type: %d\tsn: %d\tfunc_addr: %d\n", entry->id, entry->dtype, entry->sn, entry->func_addr);
    for (j = 0; j < entry->argc; j++){
      printf("     param%d:  id: %s\ttype: %d\tsclass: %d\taddr: %d\n", j, 
	     entry->args[j], entry->types[j], entry->sclasses[j], entry->addr[j]);
    }
    printf("\n");
  }
  printf("\n");
}
