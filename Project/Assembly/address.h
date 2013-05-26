/* address.h
 *
 * Compute variable address after type checking
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#ifndef ADDRESS_H
#define ADDRESS_H

#include "symtab.h"
#include "ast.h"

/* Determine local and global var addresses */
void comp_addr(flat_symtab var_table, func_table function_table, ast_node root);






#endif // ADDRESS_H
