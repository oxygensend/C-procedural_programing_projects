#include "ONPF.H"
#include "pStack.h"

#define DOT '.'

void skipSpaces() 
{
	char c;
	while(( c = getchar()) == ' ' );
	ungetc( c, stdin ); //przywraca przeczytany znak na wejscie bufora
	

}
double getNum() 
{
	char   c;
	double num = 0;
	int    sign = 0;

	skipSpaces();

	if(( c = getchar()) == '-' ) sign = 1;
	else if( c != '+ ') ungetc( c, stdin );

	while(isDigit( c = getchar() ))
		num = num * 10 + c - '0';


	if( c == DOT )
	{
		double coef = 0.1;
		while(isDigit( c = getchar() ))
		{
			num += ( c - '0' )*coef;
			coef *= 0.1;

		}

	}
	ungetc( c, stdin );
	if( sign ) num = -num;
	return ( num );
}
int isDigit( char c ) 
{
	return (c >= '0') && (c <= '9');
}
int prior( char cOper ) 
{
	switch( cOper )
	{
	  case '+':
	  case'-': return 1;
	  case '*':
	  case '/': return 2;
	  case '^': return 3;
	}
	return 0;
}
int isOper( char cOper ) 
{
	switch( cOper )
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

void onp()
{
	emptyStack();
	skipSpaces();


	char c;

	printf( "%lf", getNum() );



	while( isOper( c = getOper() ) )
	{

		while( prior( c ) <= prior( top() ) )

			putchar( pop() );
		    push( c );
		    printf( " %lf", getNum() );
	}

	//get rest operators from the stack
	while(!isEmpty())
		
		putchar( pop() );
	


}