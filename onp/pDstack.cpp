#include "pDStack.h"



#include "dStack.h"
#include <stdio.h>

#include <float.h>



DStackItem* pDHead = NULL;

void pDemptyStack() {
	while( !pDisEmpty() ) pDdel();
	//memset( DStack, 0, MAXSTACK * sizeof( DStackItem ) );// ogarnij memset, dziala tylko do wypelniania zerami
	//nDHead = 0;

}

void pDpush( double d )
{
	DStackItem* ptr = (DStackItem*)malloc( sizeof(DStackItem ) );
	if(!ptr)
	{
		perror( "ERROR: Allocation" );
		return;
	}

	ptr->value = d;
	ptr->pNext = pDHead;
	pDHead = ptr;


}

double pDpop()
{

	double x = DBL_MIN;

	if(!pDisEmpty()) {
		double x = pDtop();
		pDdel();
		return x;
	}
	perror( "ERROR: Stack underflow!\n" );
	return DBL_MIN;
}

double pDtop() {

	if(!pDisEmpty())
    return pDHead->value;

	return 0;
}

void pDdel() {

	if(!pDisEmpty())
		pDHead--;
	//Stack[nHead]=0;
	else
		perror( "Stack underflow\n" );
}

double pDisEmpty() {

	return!pDHead;
}