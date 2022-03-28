
#include "Dstack.h"
#include <memory.h>// biblioteka mset
#include< float.h>
#include "stack.h"



#define MAXSTACK 20

double DStack[MAXSTACK] = { 0 };
int DnHead = 0;


void Dpush( double x )
{
	if ( DnHead < MAXSTACK )
		DStack[DnHead++] = x;
	else
		perror( "Stack overflow\n" );
}

double Dpop()
{
	
	if ( !DisEmpty )
	{
		double x = Dtop();
		Ddel();
		return x;
	}
		perror( ".Stack overflow\n" );
	return DBL_MIN;
}


double Dtop()
{
	if ( !DisEmpty() )
		return DStack[DnHead - 1];
	
	perror( "!Stack overflow\n" );
	return DBL_MIN;
}

void Ddel()
{
	if ( !DisEmpty() )
		DnHead--;
	//Stack[nHead]=0;
	else
		perror ( "Stack underflow\n" );
}

double DisEmpty()
{
	return !DnHead;
}
void DemptyStack()
{
	//while (!isEmpty()) del();
	memset( DStack, 0, MAXSTACK * sizeof( double ) );
    DnHead = 0;
}
