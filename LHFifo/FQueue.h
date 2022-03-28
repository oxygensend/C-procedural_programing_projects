#ifndef FQUEUE_H_AB3433FC
#define FQUEUE_H_AB3433FC


#include <stdlib.h>
#include<stdio.h>
typedef struct QInfo
{

	int n_Key;

} QInfo;

typedef struct QFItem
{
	QFItem* pNext;
	QInfo* info;

} QFItem;

typedef struct QFIFO
{
	QFItem*  pHead;//g³owa-pusty element
	QFItem*  pTail;//indeks pierwszego wolnego elementu w kolejce

} QFIFO;



QFIFO* QFCreate();
// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q );

// wstawienie elementu do kolejki i zwrocenie 1 gdy OK i 0 gduy blad alokacji
int QFEnqueue( QFIFO* q, QInfo* pInfo );

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QInfo* QFDequeue( QFIFO* q );  // ma wywolac QFDel()

// czyszczenie kolejki, kolejke mozna uzywac dalej
void  QFClear( QFIFO* q );

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void  QFRemove( QFIFO** q );





#endif