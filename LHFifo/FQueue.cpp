#include "FQueue.h"
void  QFDel( QFIFO* q );


QFIFO* QFCreate()
{
	QFIFO* q = ( QFIFO* )calloc( 1, sizeof( QFIFO ) );
	if( !q )
		return NULL;
	q->pHead = q->pTail = ( QFItem* )calloc( 1, sizeof( QFItem ) );
	if( !q->pHead )
			return NULL;
	
	return q; 
}

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q )
{
	//if( !q )
		//return NULL;
	return !q|| !q->pHead->pNext;
}

// wstawienie elementu do kolejki i zwrocenie 1 gdy OK i 0 gduy blad alokacji
int QFEnqueue( QFIFO* q, QInfo* pInfo )
{
	if( !q)
		return NULL;

	QFItem* pItem = ( QFItem* )calloc( 1, sizeof QFItem );
	if( !pItem )
		return NULL;
	pItem->info = pInfo;
   
		q->pTail->pNext = pItem;
        q->pTail = pItem;

	return 1;
}

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)

QInfo* QFDequeue( QFIFO* q )
{
	if( !q )
		return NULL;
	
	if( !QFEmpty( q ) )
	{
		QInfo* out = q->pHead->pNext->info;
		
		QFDel( q );
		return out;
	}
	
		return NULL;



}// ma wywolac QFDel()
// czyszczenie kolejki, kolejke mozna uzywac dalej
void  QFClear( QFIFO* q )
{
	
	if( !q )
	{
		perror( "KOLEJKA NIE ISTNIEJE" );
		return;
	}

	while( !QFEmpty( q ) )
		free( QFDequeue( q ) );
		
}

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void  QFRemove( QFIFO** q )
{
	if( q && *q )
	{
		QFClear( *q );
		free( (*q)->pHead );
		free( *q );
		
		*q = NULL;

	}
	else
		perror( "KOLEJKA NIE ISTNIEJE" );
}

// funkcja prywatna modulu  - tylko usuniecie elemenu z listy (nie info)
void  QFDel( QFIFO* q )
{
	if( !q )
	{
		perror( "KOLEJKA NIE ISTNIEJE" );
		return;

	}
	if( QFEmpty )
	{
		perror( "KOLEJKA JEST PUSTA" );
		return;
	}
		
			QFItem* x = q->pHead->pNext;
			q->pHead->pNext = x->pNext;

			free( x );
			if( QFEmpty( q ) )
				q->pTail = q->pHead;
	
	
}
