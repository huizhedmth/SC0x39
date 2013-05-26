void g(int []);

void f(int a[], int b){
  a[10] = 1;
  b = 1;
  g(a);
}
void g(int a[]){
  a[10] = 10;
}
void main(void)
{
  double c[3];
  int a;
  f(c, a);
}






