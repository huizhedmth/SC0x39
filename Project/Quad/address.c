/* address.c
 *
 * Implementation of address computation function
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#include "address.h"
#include "symtab.h"
#include "typecheck.h"
#include "ast.h"
#include <stdlib.h>
#include <stdio.h>

static int local_addr = 0;
static int global_addr = 2000;
static cur_fun = -1;

/* Determine local and global var addresses */
void comp_addr(flat_symtab var_table, func_table function_table, ast_node root)
{
  char* name;
  int sn;
  symtab_entry entry;
  func_entry fEntry;
  ast_node temp;
  int i;
  int flag_param;

  switch(root->node_type){
  case VAR_DECL:
    temp = root->left_child->right_sibling->right_sibling; // ID node
    sn = temp->sn;
    entry = lookup_in_flat_table(var_table, sn);

    if (root->scope > 0){	// not global
      if ((entry->dtype == TYPE_INT) || (entry->dtype == TYPE_DOUBLE)){
	local_addr -= 8;
      }else if  ((entry->dtype == TYPE_INT_ARRAY) || (entry->dtype == TYPE_DOUBLE_ARRAY)){
	if(temp->left_child->expr.int_value !=0)
	  local_addr -= 8 * (temp->left_child->expr.int_value);
	else
	  local_addr -= 8;
      }
      entry->addr = local_addr;
    }else{	// global
      if ((entry->dtype == TYPE_INT) || (entry->dtype == TYPE_DOUBLE)){
	global_addr -= 8;
      }else if  ((entry->dtype == TYPE_INT_ARRAY) || (entry->dtype == TYPE_DOUBLE_ARRAY)){
	if (temp->left_child->expr.int_value)
	  global_addr -= 8 * (temp->left_child->expr.int_value);
	else
	  global_addr -= 8;
      }
      entry->addr = global_addr;
    }
    break;

  case IDENTIFIER:	// for each id that is an array (but not a param), re-write its address 
    entry = lookup_in_flat_table(var_table, root->sn);
    if ((entry->dtype == TYPE_INT_ARRAY) || (entry->dtype == TYPE_DOUBLE_ARRAY)){
      fEntry = retrieve_current_func(function_table, cur_fun);
      // check if this id is a param
      flag_param = 0;
      for (i = 0; i < fEntry->argc; i++){
	if (strcmp(root->value.string, fEntry->args[i])==0){
	  flag_param = 1;
	  break;
	}
      }
      if(flag_param == 0)
	entry->addr = entry->parent->addr;
    }
    break;

  case FUNC_DECL:
    local_addr = -8;
     cur_fun = root->left_child->left_child->right_sibling->sn;
  default:
    break;
  }

  for(root = root->left_child; root != NULL; root = root->right_sibling)
    comp_addr(var_table, function_table, root);
}
