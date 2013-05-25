int main(void)
{
  int a = 100;
  double bb[10];

  bb[1+a] = 128.0;
  return 256;
}
void f(int param1, double param2[])
{
  param1 = 256;
  param2[10] = 15;
}
