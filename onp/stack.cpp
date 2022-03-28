 
#include "stack.h"
#include <memory.h>// biblioteka mset



#define MAXSTACK 20



char Stack[MAXSTACK] = { 0 };
int nHead = 0; //index of the first empty element on the stack

void push( char c )
{
	if ( nHead < MAXSTACK )
		Stack[nHead++] = c;
	else
		perror( "Stack overflow\n" );
}

char pop()
{
	char c = top();  // char c;
	if ( c )         // if(c=top());    
		del();
	else
		perror( "Stack overflow\n" );
	return c;
}


char top()
{
	if ( !isEmpty() )
		return Stack[nHead - 1];
	
		return 0;
}

void del()
{
	if ( !isEmpty() )
		nHead--;
	//Stack[nHead]=0;
	else
		perror( "Stack underflow\n" );
}

int isEmpty()
{
	return !nHead;
}
void emptyStack()
{
	//while (!isEmpty()) del();
    memset( Stack, 0, MAXSTACK * sizeof (char ) );  
	nHead = 0;
}
