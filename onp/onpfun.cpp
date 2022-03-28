#include "onpfun.h"
#include "stack.h"
#include "Dstack.h"
#include "math.h"

#define DOT '.'

void skipSpaces() {
	char c;
	while ((c = getchar()) == ' ');
	ungetc(c, stdin); //przywraca przeczytany znak na wejscie bufora
	//while(ispace(c=getchar())) pomija wszystkie znaki, funckja biblioteczna!~!

}
double getNum() {
	char   c;
	double num = 0;
	int    sign = 0;
	
	skipSpaces();

	if (( c = getchar()) == '-' ) sign = 1;
	else if ( c != '+' ) ungetc( c, stdin );
	
	while ( isDigit(c = getchar()) )
		num = num * 10 + c - '0';
	
	
	if (c == DOT)
	{
		double coef = 0.1;
		while ( isDigit( c = getchar() ) )
		{
			num += (c - '0')*coef;
			coef *= 0.1;
			
		}

	}
	ungetc(c, stdin);
	if (sign) num = -num;
	return (num);
}
int isDigit(char c) {
return (c >= '0') && (c <= '9');
}
int prior( char cOper ) {
	switch(cOper)
	{
	case '+':
	case'-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3;
	}
	return 0;
}
int isOper( char cOper ) {
	switch(cOper)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':return 1;
	}
	return 0;
}


char getOper() {
	skipSpaces();
	return getchar();
}
double ONP()
{
	emptyStack();
	skipSpaces();
	
	char c;

	printf( "%lf", getNum() );





	while(isOper( c = getOper() ))
	{

		while(prior( c ) <= prior( top() ))


			putchar( pop() );
		push( c );

		printf( " %lf", getNum() );

		//printf(" %lf", Eval(pop(), Dtop(), Dpop()));


	}

	//get rest operators from the stack
	while(!isEmpty())
		//printf(" %c", pop());
		putchar( pop() );
	//printf("%lf", Dpop());


	return DBL_MIN;
}





double Eval( char cOper, double arg1, double arg2 )
{
	switch(cOper)
	{
	case '+': return arg1 + arg2;
	case'-':  return arg1 - arg2;
	case '*': return arg1 * arg2;
	case '/': if(fabs( arg2 ) > 1e-15) return arg1 / arg2;
		perror( "ERROR: Devision by0!!!\n" );
		return DBL_MIN;
	case '^': return pow( arg1, arg2 );
	}
	return 0;
}

double onpkalkulator()
{
	
	

		char c;
		while((c = getchar()) != '\n')
		{

			ungetc( c, stdin );
			while(isOper( c = getOper() )) 
			{

				while(prior( top() ) >= prior( c ))
				{
					double d = Dpop();
					Dpush( Eval( pop(), Dpop(), d ) );
					
				}
				push( c );
			}
			ungetc( c, stdin );

			Dpush( getNum() );



		}
		while(!isEmpty())
		{
			double d = Dpop();
			Dpush( Eval( pop(), Dpop(), d ) );

		}

		return Dpop();

	

}

/*double ONP()//calculator
double ONP()
{
	emptyStack();
	skipSpaces();
	//double x=getNum();

	char c;

	printf("%lf", getNum());



		while (isOper(c = getOper()))
		{

			while (prior(c) <= prior(top()))

				putchar(pop());
				push(c);


		//printf(" %lf", Eval(pop(), Dpop(), Dtop()));
			   printf("%lf", getNum());
		}

	//get rest operators from the stack
	while (!isEmpty())
		//printf(" %c", pop());
		putchar(pop());
	//printf("%lf", Dpop());


	return DBL_MIN;
}
*/
//wartosc liczenia w dwoch linijkach sciagniecie ze stosu, sciagam operator, sciagam drgui argument ze stosu liczbowego, obliczam funcje eval i dpushem sciagam funckje