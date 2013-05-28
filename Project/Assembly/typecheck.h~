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

/* Determine date type of the given expression */
data_type det_expr_type(flat_symtab var_table, func_table function_table, ast_node root);

/* get data type of the given ID */
data_type get_dtype_from_symtab(flat_symtab var_table, int sn);
#endif // TYPECHECK_H
