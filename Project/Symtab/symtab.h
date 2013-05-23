/* symtab.h
 * Declarations for the symbol table.
 * Written by THC for CS 57.
 * You should extend the structs and functions as appropriate.
 */

#ifndef SYMTAB_H_
#define SYMTAB_H_

#define MAXTABLEN 1024	/* maximum number of symbols in a program */
#define MAXFUNCNUM 100	/* maximum number of functions in a program */
#define MAXARGS	10	/* maximum number of arguments for a function */

#include "ast.h"
/* Node in a linked list within the symbol table. */

typedef struct symnode *symnode;
struct symnode {
  char *name;	    /* name in this symnode */
  symnode next;	    /* next symnode in list */
  /* Other attributes go here. */
  int sn;	    /* identifier for this id throughout the program */
};

/* Set the name in this node. */
void set_node_name(symnode node, char *name);

/* Does the identifier in this node equal name? */
int name_is_equal(symnode node, char *name);


/* Hash table for a given scope in a symbol table. */

typedef struct symhashtable *symhashtable;
struct symhashtable {
  int size;			/* size of hash table */
  symnode *table;		/* hash table */
  symhashtable outer_scope;	/* ptr to symhashtable in next outer scope */
  int level;			/* level of scope, 0 is outermost */
};

/* Symbol table for all levels of scope. */

typedef struct symboltable *symboltable;
struct symboltable {
  symhashtable inner_scope;	/* pointer to symhashtable of innermost scope */
};

/* Create an empty symbol table. */
symboltable create_symboltable();

/* Destroy a symbol table. */
void destroy_symboltable(symboltable symtab);

/* Insert an entry into the innermost scope of symbol table.  First
   make sure it's not already in that scope.  Return a pointer to the
   entry. */
symnode insert_into_symboltable(symboltable symtab, char *name, int sn);

/* Lookup an entry in a symbol table.  If found return a pointer to it
   and fill in level.  Otherwise, return NULL and level is
   undefined. */
symnode lookup_in_symboltable(symboltable symtab, char *name, int *level);

/* Enter a new scope. */
void enter_scope(symboltable symtab);

/* Leave a scope. */
void leave_scope(symboltable symtab);

/* ---------------------- created by Huizhe Li ------------------------*/
/* --------------------------------------------------------------------*/

/* ---------------------- data structure definition -------------------*/

/* Definition of data type */

typedef enum {
  TYPE_INT,
  TYPE_INT_ARRAY,
  TYPE_DOUBLE,
  TYPE_DOUBLE_ARRAY,
  TYPE_VOID
} data_type;

/* Definition of storage class */

typedef enum{
  STORAGE_NORMAL,
  STORAGE_CONST
} storage_class;

/* Definition of an entry in the flat symbol table, which is built as 
 * the result of traversing the ast while keeping track of all ID's 
 * using the temporary symtab. (Thanks to THC, Dartmouth College
 */ 

struct symtab_entry {
  char* id;	
  int lineNumber;	/* the line number at which it appears in the program */
  data_type dtype;	/* its data type */
  storage_class sclass;	/* its storage class */
  int addr;		/* assigned address in memory.
			   may be absolute or offset from fp, depending on var type */	
  int sn;	       	/* "serial number" for this id, that uniquely identifies it */
};

typedef struct symtab_entry *symtab_entry;

/* Definition of the flat symbol table */

struct flat_symtab {
  int size;	/* current size of the table */
  symtab_entry entries[MAXTABLEN];
};

typedef struct flat_symtab *flat_symtab;

/* Definition of function table entry */

struct func_entry {
  char* id;		/* name of the function */
  data_type dtype;	/* type of return value */
  int argc;		/* number of args it has */
  char* args[MAXARGS];	/* id's of its args */
  data_type types[MAXARGS];	/* type of its args */
  storage_class sclasses[MAXARGS];	/* similar */
  int addr[MAXARGS];		/* assigned address in memory */
  int sn;		/* "serial number" of this function */
  int func_addr;	/* its entrance address */
  int def;		/* zero for declaration, non-zero for definition */
};

typedef struct func_entry *func_entry;  

/* Definition of the function table.
 * Contains entries for each function defined in the program
 */

struct func_table {
  int size;
  func_entry entries[MAXTABLEN];
};

typedef struct func_table *func_table;

/* ------------------------function definition -------------------------*/

/* Create an empty flat symbol table */
flat_symtab create_flat_symtab();

/* Build the flat symbol table, where all id's are mangled into a flat table, 
 * each "indexed" by (id, lineNumber) pairs.
 * Later passes will only refer to this table for information.
 */
void build_symtab(symboltable tracking_table, flat_symtab var_table, func_table function_table, ast_node root);

/* Insert an entry into the flat symbol table, return 0 on success */
static int insert_flat_table_entry(flat_symtab table, symtab_entry entry);

/* Create an entry */
static symtab_entry create_symtab_entry(char* id, int lineNumber, data_type dtype, storage_class sclass, int addr, int sn);

/* Change current scope of the tracking symbol table */
static void change_current_scope(symboltable tracking_table, ast_node root);

/* Convert from string literal to storage_class */
static storage_class convert_to_sclass(char* str);

/* Convert from string literal to data_type */
static data_type convert_to_dtype(char* str);

/* Print the flat table, for debug mode only */
void print_flat_table(flat_symtab var_table);

/* Create an empty function table */
func_table create_functable();

/* Look up a function id in the given function table.
 * Return NULL if not found, otherwise return the pointer to the entry
 */
static func_entry lookup_in_functable(func_table function_table, char* name);

/* Create a func_entry */
static func_entry create_func_entry(char* name, data_type dtype, int argc, char* args[], 
				    data_type types[], storage_class sclasses[], int addr[], int sn, int f_addr, int def);

/* Insert a function entry into function table */
static int insert_func_table(func_table function_table, func_entry entry);

/* Print the function table */
void print_func_table(func_table function_table);

/* Fetch info for the id as a param of the current function
 * return pointer to the entry, or NULL if not found
 */
static symtab_entry retrieve_param(func_table function_table, int sn, char* name);

/* Check compatibility between two fun declarations */
int check_func_comp(func_entry entry, ast_node decl);
#endif
