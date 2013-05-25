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

/* Determine local and global var addresses */
void comp_addr(flat_symtab var_table, func_table function_table, ast_node root)
{
  char* name;
  int sn;
  symtab_entry entry;
  ast_node temp;

  switch(root->node_type){
  case FUNC_DECL:
    local_addr = -8;
    break;

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

  default:
    break;
  }

  for(root = root->left_child; root != NULL; root = root->right_sibling)
    comp_addr(var_table, function_table, root);
    
  
}
