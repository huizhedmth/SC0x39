/*
 * input3.c
 *
 * This program tests var/func definitions/prototypes 
 *
 * By Huizhe Li, Master Student, Dartmouth College
 */

int g_a;
const double g_b;

int func1(int, int b);	/* omitted param identifier */
double func2(void);
void func3(double dbl[], int[]);	/* array params */

int main(void){
	int a = 1, b = 2, c = func1(a,b);	/* assignment at declaration */
	double d = (a+b)%c - 3.14;

	/* arrays */
	int array[1+2+a];
	double dbl_array[3];

	array[a] = array[1] + array[2] * array[3];

	func3(dbl_array, array);

	return 0;
}


