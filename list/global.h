#pragma once

#define LISTINFO ListInfo
typedef struct
{

	int nKey;
	int* pTab;
} ListInfo;

int compare( const void* info, const void* info1 );
void freeInfo( const void* x );
