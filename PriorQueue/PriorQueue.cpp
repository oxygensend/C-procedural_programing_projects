// PriorQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "PQueue.h"


int PQCompare( const void* info, const void* info1 );
void print( const void* info );
void freeInfo( const void* x );


int main()
{

	int nSize = 20; // rozmiar kolejki
	PQueue* pQueue = PQInit( nSize );

	

	
	PQINFO* info1 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info1 )
		return NULL;
	info1->nKey = 2;
	info1->pTab = ( int* )calloc( 2, sizeof( int ) );
	
	PQINFO* info2 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info2 )
		return NULL;
	info2->nKey = 8;
	info2->pTab = ( int* )calloc( 2, sizeof( int ) );
	PQINFO* info3 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info3 )
		return NULL;
	info3->nKey = 5;
	info3->pTab = ( int* )calloc( 2, sizeof( int ) );
	PQINFO* info4 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info4 )
		return NULL;
	info4->nKey = 7;
	info4->pTab = ( int* )calloc( 2, sizeof( int ) );
	PQINFO* info5 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info5 )
		return NULL;
	info5->nKey = 3;
	info5->pTab = ( int* )calloc( 2, sizeof( int ) );
	PQINFO* info6 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info6 )
		return NULL;
	info6->nKey = 1;
	info6->pTab = ( int* )calloc( 2, sizeof( int ) );
	PQINFO* info7 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info7 )
		return NULL;
	info7->nKey = 6;
	info7->pTab = ( int* )calloc( 2, sizeof( int ) );
	PQINFO* info8 = ( PQINFO* )calloc( 1, sizeof( PQINFO ) );
	if( !info8 )
		return NULL;
	info8->nKey = 9;
	info8->pTab = ( int* )calloc( 2, sizeof( int ) );
	
	
	PQEnqueue( pQueue, 1 ,info1 );
	PQEnqueue( pQueue, 10 ,info2 );
	PQEnqueue( pQueue, 9 ,info3 );
	PQEnqueue( pQueue, 2 ,info4 );
	PQEnqueue( pQueue, 4 ,info5 );
	PQEnqueue( pQueue, 7 ,info6 );
		PQPrint( pQueue, 0, print );
		printf( "\n" );

		PQDequeue( pQueue );

		PQPrint( pQueue, 0, print );
		printf( "\n" );

		PQEnqueue( pQueue, 6, info7 );
		PQEnqueue( pQueue, 5,info8 );

		PQPrint( pQueue, 0, print );
		printf( "\n" );

		printf( "\nszukana info znajduje sie na: %d\n", PQFind( pQueue, info6, PQCompare ) );
		PQSetPrior( pQueue, 3, info6, PQCompare );
	    PQSetPrior( pQueue, 10, info7, PQCompare );

		PQPrint( pQueue, 0, print );
		printf( "\n" );
		
		PQClear( pQueue, freeInfo );
		PQRelease( &pQueue, freeInfo );
	
		
		PQPrint( pQueue, 0, print );
		
	
	return 0;

}

int PQCompare( const void* info, const void* info1 )
{
	PQINFO*  pInfo = ( PQINFO* )info;
	PQINFO*  pInfo1 = ( PQINFO* )info1;


	if( pInfo == NULL && pInfo1 == NULL )
		return 0;
	if( pInfo == NULL && pInfo1 != NULL )
		return -1;
	if( pInfo1 == NULL && pInfo != NULL )
		return 1;

	if( pInfo < pInfo1 )
		return -1;
	if( pInfo > pInfo1 )
		return 1;
	else return 0;


}

void print( const void* info )
{

	//PQINFO* pInfo = ( PQINFO* )info;
	printf( "%d", *(PQINFO*)info );

}
void freeInfo( const void* x )
{
	free( (( PQINFO* )x)->pTab );
	free( ( PQINFO* )x );


}
