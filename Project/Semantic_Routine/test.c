void f(int, const double);

int main()
{
  int a1, a2[10];
  double b1, b2[10];

  f();
  f(1);
  f(a1);
  f(b1);
  f(a1, a2);
  f(a1, b2);
  f(a1, b1);
  f(a1, a2, a2);
}

int f(int a, const double b)
{	
  
}


