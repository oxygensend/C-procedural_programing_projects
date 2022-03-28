// LHFifo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>

void print( QFIFO* q );

QInfo* value( int val );


int main()
{ 
	
	QFIFO* queue = QFCreate();
	QInfo* a = value( 1 );
	QInfo* b = value( 2 );
	QInfo* c = value( 3 );
	QInfo* d = value( 4 );
	QInfo* f = value( 5 );
	QInfo* g = value( 6 );
	QInfo* h = value( 7 );
	QInfo* i = value( 8 );
	QInfo* j = value( 9 );
	QInfo* k = value( 10 );

	QFEnqueue( queue, a );
	QFEnqueue( queue, b );
	QFEnqueue( queue, c );
	QFEnqueue( queue, d );

	print( queue );
	
	QFDequeue( queue );
	QFDequeue( queue );
	QFDequeue( queue );

	printf( "\n" );
	print( queue );
	
	QFEnqueue( queue, f );
	QFEnqueue( queue, g);
	QFClear( queue );
	
	printf( "\n" );
	print( queue );


	QFEnqueue( queue, h );
	QFEnqueue( queue, a );
	QFEnqueue( queue, j );
	
	QFDequeue( queue );
	
	printf( "\n" );
	print( queue );

	QFRemove( &queue );
	

	
	}
QInfo* value( int val )
{

	QInfo* x = ( QInfo* )calloc( 1, sizeof QInfo );
	if( !x )
		return NULL;
	x->n_Key = val;

	return x;
}
void print( QFIFO* q )
{
	if( !q->pHead->pNext )
		printf( "kolejka jest pusta" );
	else
	{
		QFItem* n = q->pHead->pNext;
		while( n->pNext )
		{
			printf( "%d  ", *n->info );
			n = n->pNext;
		}
		printf( "%d  ", *n->info );
	}



}