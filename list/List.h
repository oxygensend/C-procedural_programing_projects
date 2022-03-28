#pragma once
#include "global.h"
typedef struct tagListItem
{
	LISTINFO* pInfo;
	tagListItem* pNext;
} ListItem;

ListItem* CreateList();
int InsertFront( ListItem* pList, LISTINFO* pInfo );
int Insert( ListItem* pAfter, LISTINFO* pInfo );
LISTINFO* RemoveFront(ListItem* pList);
LISTINFO* Remove( ListItem* pAfter );
LISTINFO* Front( ListItem* pList );
int IsEmpty( ListItem* pList );
void ClearList( ListItem* pList, void( __cdecl* freeInfo )(const void*) );
void RemoveList( ListItem** pList, void( __cdecl* freeInfo )(const void*) );
void SortList( ListItem* pList, int( __cdecl* compare )(const void*, const void*) );
ListItem* Find( ListItem* pList, ListItem** pPrev,const void* searchinginfo, int( __cdecl* compare )(const void*, const void*) );