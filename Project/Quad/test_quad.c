#include "quad.h"


int main(){
  oprand op1, op2, op3;
  quad qd;

  op1 = create_oprand(OP_TYPE_INT, 1);  
  op2 = create_oprand(OP_TYPE_NA, 1);  
  op3 = create_oprand(OP_TYPE_DOUBLE, 1.5);

  qd = create_quad(FUNC_BODY, op1, op2, op3);
  insert_quad(qd);
  insert_quad(qd);
  insert_quad(qd);

  print_code();
  return 0;
}
