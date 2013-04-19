/*
 * input1.c
 *
 * This program covers all the features currently supported, which
 * are the minimum requirements for graduate students, and aims at
 * verifying that a legal program does not cause parsing error.
 *
 * More extensive tests for specific features can be found in other 
 * "input*.c" files
 *
 *
 * By Huizhe Li, Master Student, Dartmouth College
 */


/* global declaration */
int g_id1;
const double g_id2;
double const g_id3;

/* function prototype */
int func1(int param1, double param2, double param3);

/* function definition */
int main(void){	/* compound statement */
	/* var declaration, local declaration */
	const int id1;
	double id2;	/* loop statements */
	int i=0, j=id1+id2, k;

	while(1){
		do{
			/* nothing */
		}while(id1-id2);
		for (i = 0; i < 10; i++){
			id1++;
			break;	/* break-stmt */
		}
		continue; 	/* continue-stmt */
	}

	/* switch statements */
	switch(id1=0){
	case 1:		/* case */
		id1 = 2;
		break;
	case 2:
		id1 = 1;
		break;
	case 3:
		print sizeof(id1);	/* op_sizeof */
		print sizeof(int);
	default:	/* default */
		id1 = 0;
	}

	/* function call */
	print func1(id1, id2, k);

	/* if-stmt and if-else-stmt */
	if (id1 > 0)
		if (id2 > 0)
			print "they are all positive!"; /* print-stmt */
	else{
		print id1;
		read id2; /* read-stmt */
	}

	/* return-stmt */
	return 0;
}

/* function definition 
 * along with operators 
 */
int func1(int a, double b, double c)
{
	/* binary operators */
	int id1 = (1+100)%((1+2)*3), id2 = 1+100%1+2*3; /* precedence */
	int id3 = 1*1, id4 = 1/1, id5 = 1%1;
	int id6 = 1==2, id7 = 1!=1, id8 = 1>2, id9 = 1<=0, id10 = 0&&1, id11 = 1||0;

	/* unary operators */
	int id12 = -1, id13 = !0, id14 = id1++, id15 = --id1;
	
	/* FNUM */
	double pi = -3.14;
	return a+b+c;
}
	
	

	
	
