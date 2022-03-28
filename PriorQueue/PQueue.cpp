#include"PQueue.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void UpdateDown( PQItem** tab, int left, int right ); // update heap down between index l and p <--- modified Update() from HeapSort

void UpdateUp(PQItem** tab, int left, int right ); // update heap up between index l and p 

PQueue* PQInit( int nSize )
{
	if( nSize < 1 )
		return NULL;
	PQueue* q = ( PQueue* )calloc( nSize, sizeof( PQueue* ) );
	if( !q )
		return NULL;

	q->nPQSize = nSize;
	
	q->pPQueue = ( PQItem** )calloc( nSize, sizeof( PQItem* ) );
	if( !q->pPQueue )
		return NULL;
	
	return q;
}

int PQisEmpty( PQueue* q )
{
	
	return !q || !q->nPQCurrsize;

}

int PQSize( PQueue* q )
{
	
	return (q) ? q->nPQCurrsize : PRIOR_ERROR;
}
int PGMaxPrior( PQueue* q )
{
	///if(q)
	return ( q && !PQisEmpty( q ) ) ? q->pPQueue[0]->nPrior : PRIOR_ERROR;
}

int PQEnqueue(PQueue* q, int prior, PQINFO* info)
{
	if( !q )
		return 0;

	if( PQSize( q ) == q->nPQSize )
		return 0;
	
	PQItem* item = ( PQItem* )calloc( 1, sizeof( PQItem ) );
	if( !item )
		return NULL;
	item->nPrior = prior;
	item->pInfo = info;
	
    int ix = PQSize( q );
	
	q->pPQueue[ix] = item;
    q->nPQCurrsize++;
  
   if( ix > 0 )
  UpdateUp( q->pPQueue, 0, ix );
 
	return 1;

}
PQINFO* PQDequeue(PQueue* q)
{
	if( !q )
		return NULL;
	if( PQisEmpty( q ) )
		return NULL;

	PQINFO* out = q->pPQueue[0]->pInfo;
	 
	
	free( q->pPQueue[0] );
	int ix = --q->nPQCurrsize;
	if(ix)
	q->pPQueue[0] = q->pPQueue[ix];
	

	q->pPQueue[ix] = NULL;
	
	if( ix > 1 )
	UpdateDown( q->pPQueue, 0, ix-1);

	return out;
	
}
void  PQClear( PQueue* q, void( __cdecl* freeInfo )(const void*) )
{
    
	if( !q && freeInfo==NULL )
	{
		perror( "KOLEJKA NIE ISTNIEJE LUB B£AD PRZEKZANIA FUNKCJI" );
		return;
	}
	
	    while( !PQisEmpty( q ) )
		{
			freeInfo( PQDequeue(q) );
		}
		
}


void PQRelease( PQueue** q, void( __cdecl* freeInfo )(const void*) )
{
	
	if( !q && !*q )
	{
		perror( "KOLEJKA NIE ISTNIEJE" );
		return;
	}
		PQClear( *q, freeInfo );
		free( (*q)->pPQueue );
		free( *q );
		*q = NULL;
		

	
}
int PQGetPrior( PQueue* q, PQINFO* info, int( __cdecl* compare )(const void*, const void*) )
{ 

	return PQgetPrior( q, PQFind( q, info, compare ) );

}
int PQgetPrior( PQueue* q, int position )
{
	if( !q && PQisEmpty( q ) )
		return PRIOR_ERROR;
	if(  position>=0 && position<PQSize(q))
	    return q->pPQueue[position]->nPrior;
	return POS_ERROR;
}

int PQSetPrior( PQueue* q, int new_prior,PQINFO* info, int( __cdecl* compare )(const void*, const void*) )
{ 

	return PQsetPrior( q, new_prior, PQFind( q, info, compare ) );

}
int PQsetPrior( PQueue* q, int new_prior, int position )
{ 
	
	int t_prior = PQgetPrior(q, position);
	
	if( t_prior != PRIOR_ERROR && t_prior != POS_ERROR  )
	{
		q->pPQueue[position]->nPrior = new_prior;
		( t_prior < new_prior ) ? UpdateUp( q->pPQueue, 0, position ) : UpdateDown( q->pPQueue, position, PQSize(q)-1 );
	}
	return t_prior;

}
int PQFind( PQueue* q, PQINFO* info, int( __cdecl* compare )(const void*, const void*) )
{ 
	if( !q )
		return PRIOR_ERROR;

		if( !compare )
		   return POS_ERROR;
	
		for( int i = 0;i < (PQSize(q));i++ )
			if( compare( info, q->pPQueue[i]->pInfo ) == 0 )
				return i;

		return PRIOR_ERROR;
	
}
void PQPrint( PQueue* q, int position, void( __cdecl* print )(const void*) )
{
	if( !q && PQisEmpty(q) )
	{
		perror( "Kolejka nie istnieje lub kolejka jest pusta\n" );
		return;
	}
	
	if( position < 0 )
	{
		perror( "Nie ma takiej pozycji" );
		return;
	}



	if( position   >= PQSize(q) )
		return;

	if( print )
		print( q->pPQueue[position]->pInfo );

		printf( " (%d), [%d]\n", q->pPQueue[position]->nPrior, position );

		    
			PQPrint( q, 2 * position + 1, print );

			
			PQPrint( q, 2 * position +2, print );
	
}
void UpdateDown( PQItem** tab, int left, int right )
{
  
	if( left >= right )
		return;
	int i = left;
		PQItem* pItem =tab[i];
		
		int j = 2*i+1;
		while( j <= right )
		{
			if( j+1 <= right && tab[j + 1]->nPrior > tab[j]->nPrior )
				j++;

			if( pItem->nPrior > tab[j]->nPrior ) break;
		    
			tab[i]= tab[j];
			
			i = j;
			j = 2 * i + 1;
		}
	
		tab[i] = pItem;
	  

		
	
}
void UpdateUp( PQItem** tab, int left, int right )
{
	
	if( left >= right )
		return;
	int i = right;
	int j = (i - 1) / 2 ;
	PQItem* pItem = tab[i];

	while( j >= left && tab[j]->nPrior < pItem->nPrior)
	{
		tab[i] = tab[j];
		i = j;
		j = (i + 1) / 2-1;
	}
	tab[i] = pItem;
	
}