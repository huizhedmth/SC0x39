/* typecheck.h
 *
 * Declaration of the type checking function
 * 
 * by Huizhe Li, Master Student, Dartmouth College.
 */

#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "ast.h"
#include "symtab.h"

/* Perform type checking on the given syntax tree "root".
 * Must be provided with the two corresponding symboltables generated beforehand 
 * Return zero if no error found, non-zero otherwise.
 */
int type_check(flat_symtab var_table, func_table function_table, ast_node root);

#endif // TYPECHECK_H
