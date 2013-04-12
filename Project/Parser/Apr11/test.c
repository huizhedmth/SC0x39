#include<stdio.h>

int f();

int a = 1;
int b = 2;

int main(void)
{
	f();
	switch(a){
		{case 1:printf("test\n"); printf("test2\n");}
	}
	return 0;
}

int f()
{
	return 1;
}
