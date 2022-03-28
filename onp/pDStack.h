#ifndef STACK_H_A23B34
#define STACK_H_A23B34
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include<float.h>

typedef struct tagDStackItem
{

	double          value;
	tagDStackItem* pNext;
} DStackItem;


void pDpush( double x );
double pDpop();
double pDtop();
void pDdel();
double pDisEmpty();
void pDemptyStack();
#endif