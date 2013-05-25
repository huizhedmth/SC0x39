void f(int, double[], double);
int g(){
  return 1024;
}

int main(void)
{
  int a = 100;
  double bb[10];

  bb[1+a] = 128.0 + 1.0;
  f(a+1, bb, 1.0);
  a = g();
  return 256;
}

void f(int param1, double param2[], double param3)
{
  param1 = 256;
  param2[10] = 15;
}

