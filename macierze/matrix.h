#ifndef MATRIX_H_AB3433FD
#define MATRIX_H_AB3433FD

#include <iostream>
#include <stdlib.h>
#include<stdio.h>





int    CreateMatrix( double*** pMatrix, int nDim );
double Det( double** pTab, int nDim );
void   PrintMatrix( double** pMatrix, int nDim );
void   DelateMatrix( double*** pMatrix, int nDim );
void   TransMatrix( double** pTab, int nDim );
void   InverseMatrix( double** pInv, double** pTab, int nDim, double det );
void   LayoutEqu( double** pInv, double* pB, double* pRes, int nDim );

#endif