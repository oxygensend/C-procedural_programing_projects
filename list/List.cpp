#include"List.h"
#include"global.h"
#include<stdlib.h>
#include<stdio.h>

ListItem* CreateList()
{

	return ( ListItem * )calloc( 1, sizeof( ListItem ) );

}
int InsertFront( ListItem* pList, LISTINFO* pInfo ) 
{
	return Insert( pList, pInfo );
	
}
int Insert( ListItem* pAfter, LISTINFO* pInfo )
{
	if( !pAfter )
		return NULL;

	ListItem* pItem = ( ListItem* )calloc( 1, sizeof( ListItem ) );
	if( !pItem )
		return 0;
	pItem->pInfo = pInfo;
	pItem->pNext = pAfter->pNext;
	pAfter->pNext = pItem;
	
	return 1;
}

LISTINFO* RemoveFront( ListItem* pList )
{

	return Remove( pList);
}
LISTINFO* Remove( ListItem* pAfter )
{
	
	if( !pAfter || IsEmpty( pAfter ) )
		return NULL;
	

	ListItem* temp = pAfter->pNext;
	LISTINFO* out = temp->pInfo;
	
	pAfter->pNext = temp->pNext;
	free( temp );
	return out;
}
LISTINFO* Front( ListItem* pList )
{
	if( !pList || IsEmpty( pList ) )
		return NULL;
	return pList->pNext->pInfo;
}
int IsEmpty( ListItem* pList )
{
	return !pList || !pList->pNext;

}
void ClearList( ListItem* pList, void( __cdecl* freeInfo )(const void*) )
{
	if( !pList || freeInfo == NULL )
	{
		perror( "LISTA NIE ISTNIEJE LUB B£AD PRZEKZANIA FUNKCJI" );
		return;
	}
	while( !IsEmpty( pList ) )
		freeInfo( RemoveFront( pList) );
}
void RemoveList( ListItem** pList, void( __cdecl* freeInfo )(const void*) )
{
	if( !pList || !*pList )
	{
		perror( "LISTA NIE ISTNIEJE" );
		return;
	}
	ClearList( *pList, freeInfo );
	free( *pList );
	*pList = NULL;
}
void SortList( ListItem* pList, int( __cdecl* compare )(const void*, const void*))
{
	if( !pList || !compare )
	{
		perror( "BLAD W SORTLIST" );
		return;
	}

	ListItem* pFirst = pList;
	while( pFirst->pNext )
	{
		ListItem* pMin = pFirst;
		ListItem* pCurr = pFirst->pNext;
		while( pCurr->pNext )
		{
			if( compare( pCurr->pInfo, pMin->pInfo ) == -1 )
				pMin = pCurr;
			pCurr = pCurr->pNext;
		}
		if( pMin != pFirst )
		{

			pCurr = pMin->pNext;
			pMin->pNext = pFirst->pNext;
			pFirst->pNext = pMin->pNext;
			pMin->pNext = pCurr;
		}
		pFirst = pFirst->pNext;
	}
}
ListItem* Find( ListItem* pList, ListItem** pPrev, const void* searchinginfo, int( __cdecl* compare )(const void*, const void*) )
{
	if( !pList || !compare )
		return NULL;
	
	*pPrev = pList;
	
	while( (*pPrev)->pNext )
	{
		if( compare( searchinginfo, (*pPrev)->pNext->pInfo ) == 0 )
			return (*pPrev)->pNext;
		*pPrev = (*pPrev)->pNext;
		
	}
	return *pPrev=NULL;
}

