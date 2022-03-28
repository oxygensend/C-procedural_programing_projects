
#pragma once
#include "global.h"

#define PRIOR_ERROR INT_MIN
#define POS_ERROR  -1



typedef struct PQItem
{
	PQINFO* pInfo;
	int nPrior;

}PQItem;

typedef struct PQueue
{
	PQItem** pPQueue;
    int nPQSize;
	int nPQCurrsize;

}PQueue;

PQueue* PQInit(int nSize); // kreuje kolejke o zadanym rozmiarze i zwraca wskaznik do niej lub NULL gdy blad

int PQisEmpty( PQueue* q ); // zwraca 0 lub 1 - kolejka pusta/nie pusta

int PQSize( PQueue* q ); // zwraca ilosc elementow w kolejce

int PGMaxPrior( PQueue* q ); // zwraca najwiekszy priorytet w kolejce (z zerowej pozycji) lub PRIOR_ERROR

int PQEnqueue( PQueue* q,int prior, PQINFO* info ); // wstawia do kolejki informacje o zadanym priorytecie, zwraca 0( niepowodzenie )lub 1 ( powodzenie )

PQINFO* PQDequeue( PQueue* q ); // zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie

void  PQClear( PQueue* q, void( __cdecl* freeInfo )(const void*) ); // czysci cala kolejke zwalniajac pamiec alokowana przez uzytkownika (nainfo), nie znana struktura do zwolnienia
// dlatego przekazac trzeba funkcje uzytkownika do zwolnienia pamieci przezparametr

void PQRelease( PQueue** q, void( __cdecl* freeInfo )(const void*) ); // zwraca w parametrze we-wy NULL (kolejka) usuwaj¹c wszyskto wczesniej(czyszczenie kolejki)

void PQPrint( PQueue* q, int position, void( __cdecl* print )(const void*) ); // drukuje w porzadku preorder (rekurencyjnie) od zadanej pozycji, abywydrukowaæ info uzytkownika przekazac
// trzeba funkcje drukujaca ta informacje. Dodatkowo, drukuje priorytet wokraglych nawiasach oraz pozycje w
// kolejce w kwadratowych nawiasach

int PQSetPrior( PQueue* q, int new_prior, PQINFO* info, int( __cdecl* compare )(const void*, const void*) ); // ustawia nowy priorytet dla zadanej ixnformacji uzytkownika, nie znanastruktura informacji, która trzeba wyszukac
// dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika.Funkcja zwraca poprzedni priorytet lub PRIOR_ERROR

int PQsetPrior( PQueue* q, int new_prior, int position ); // ustawia nowy priorytet dla informacji uzytkownika bedacej na zadanejpozycji w kolejce( indeks w tablicy ),
// Funkcja zwraca poprzedni priorytet. W przypadku bledu zwraca PRIOR_ERROR

int PQGetPrior( PQueue* q, PQINFO* info, int( __cdecl* compare )(const void*, const void*) ); // zwraca priorytet informacji uzytkownika w kolejce lub PRIOR_ERROR, nieznana struktura informacji, która trzeba wyszukac
// dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika

int PQgetPrior( PQueue* q, int position ); // zwraca priorytet informacji uzytkownika z zadanej pozycji w kolejce lub PRIOR_ERROR

int PQFind( PQueue* q, PQINFO* info, int( __cdecl* compare )(const void*, const void*) ); // zwraca indeks wyszukiwanej informacji uzytkownika, nie znana strukturainformacji uzytkownika dlatego
// przekazac trzeba funkjce porownujaca informacje uzytkownika
// Zwaraca POS_ERROR jesli nie ma info w kolejce
//-----------------------------------------
// pomocnicze w implementacji 2 funkcje !!!!


