// Listazglowa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"List.h"
#include <iostream>

void print( ListItem* pList )
{
	if( !pList )
	{
		perror( "KOLEJKA NIE ISTNIEJE" );
		return;
	 }
	if( !IsEmpty( pList ) )
	{
		ListItem* temp = pList->pNext->pNext;
		int i = 1;
		while( temp != NULL )
		{
			printf( "pozycja: %d , informacja: %d\n", i, *temp->pInfo );
			temp = temp->pNext;
			i++;
		}
		printf( "\n" );
	}
	else
		perror( "KOLEJKA JEST PUSTA" );

}

LISTINFO* create( int val )
{
	LISTINFO* info = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
	if( !info )
		return NULL;
	info->nKey = val;
	info->pTab = ( int* )calloc( 1, sizeof( int ) );


}
int compare( const void* info, const void* info1 )
{
	LISTINFO*  pInfo = ( LISTINFO* )info;
	LISTINFO*  pInfo1 = ( LISTINFO* )info1;
	
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
void freeInfo( const void* x )
{
	free( (( LISTINFO* )x)->pTab );
	free( ( LISTINFO* )x );


}

int main()
{
 
	
	

	ListItem* list = CreateList();

	/*LISTINFO* info1 = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
	if( !info1 )
		return NULL;
	info1->nKey = 2000;
	info1->pTab = ( int* )calloc( 1, sizeof( int ) );
	InsertFront( list, info1 );
	*/
	for( int i = 1; i <=20;i++ )
	{

		LISTINFO* info = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
		if( !info )
			return NULL;
		info->pTab = ( int* )calloc( 1, sizeof( int ) );
		if( i == 9 )
		{
			info->nKey = 2000;
			InsertFront( list, info );
		}
		else
		{
			info->nKey = rand() % 50 + 1;
			InsertFront( list, info );
		}
	}
	LISTINFO* info = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
	if( !info )
		return NULL;
	info->nKey = 2000;
	info->pTab = ( int* )calloc( 1, sizeof( int ) );

	LISTINFO* info1 = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
	if( !info1 )
		return NULL;
	info1->nKey = 3000;
	info1->pTab = ( int* )calloc( 1, sizeof( int ) );

	LISTINFO* info2 = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
	if( !info2 )
		return NULL;
	info2->nKey = 80;
	info2->pTab = ( int* )calloc( 1, sizeof( int ) );

	LISTINFO* info3 = ( LISTINFO* )calloc( 1, sizeof( LISTINFO ) );
	if( !info3 )
		return NULL;
	info3->nKey = 300;
	info3->pTab = ( int* )calloc( 1, sizeof( int ) );
	
	print( list );
	
	SortList( list, compare );

	print( list );

	ListItem* prev = NULL;
	

	//Insert( Find( list, &prev, info, compare ), info1 );

	print( list );

	RemoveFront( list );

	print( list );

	ClearList( list, freeInfo );

	print( list );

	InsertFront(list, info2 );
	InsertFront(list, info3 );

	print( list );
	RemoveList( &list, freeInfo );
	
	print( list );
	

}

