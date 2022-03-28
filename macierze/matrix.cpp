#include "matrix.h"
#include <math.h>

void  Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim );
void  ComplMatrix( double** pTabD, double** pTab, int nDim );

void PrintMatrix( double** pMatrix, int nDim )
{
		for(int i = 0; i < nDim; i++ )
		{
			double *p = *pMatrix++;
			for(int j = 0; j < nDim; j++)
			{
				printf( "%lf " , *p++ );

			}
			printf( "\n" );
			
		}
}
void DelateMatrix( double*** pMatrix, int nDim )
{
	double** p = *pMatrix;
	for( int i = 0; i < nDim; i++ )
		free( *p++ );
	free( *pMatrix );
	*pMatrix = NULL;
}


int CreateMatrix( double*** pMatrix, int nDim ) // kreowanie macierzy
{
	*pMatrix = ( double** )malloc( sizeof( double* ) * nDim );
	if( !pMatrix )
	{
		return 0;
	}
	memset( *pMatrix, 0, sizeof( double * ) * nDim );

	double** p = *pMatrix;  // pomocniczy wsaknik do alokacji
	for( int i = 0; i < nDim; i++ )
	{
		*p = (double*)malloc( sizeof(double) * nDim );
		if( !*pMatrix )
		{
			
			return 0;
		}
		memset( *p++, 0, sizeof( double ) * nDim );
	}
}



void TransMatrix( double** pTab, int nDim )
{
	double**t = pTab;
	for( int i = 0; i < nDim-1; i++ )
	{
		double* p = *t++ + i+1;
		for( int j = i+1 ; j < nDim; j++ )
		{
			double temp = *p;
			*p++ = pTab[j][i];
			pTab[j][i] = temp;
		}
	}
}
void Complement( double** pTabO, double **pTabI, int nRow, int nCol, int nDim )
{	
	for( int i = 0;i < nDim;i++ )
	{
		double* pI = *pTabI++;

		if( i == nRow ) 
			continue;
		
		double* pO = *pTabO++;
		
		for( int j = 0;j < nDim;j++, pI++)
		{
			if( j == nCol ) 
				continue;
		
			*pO++ = *pI;
		}
		
	}
	
}	


void ComplMatrix( double** pTabD, double** pTab, int nDim )
{  
	double** Tab = NULL;   //tablica pom
	
	if( !CreateMatrix( &Tab, nDim - 1 ) )
	{
		perror( "ERROR: COULD NOT CREATE MATRIX" );

	}
	
		for( int i = 0;i < nDim;i++ )
	    {
			double*pD = *pTabD++;
			int sign = ( i % 2 ) ? -1 : 1;

		for( int j = 0;j < nDim;j++)
		  {
			Complement( Tab, pTab, i, j, nDim);
			
			*pD++ =sign* Det( Tab, nDim -1 );
			sign = -sign;
		  }
	    }
		DelateMatrix( &Tab, nDim-1 );

}

double Det( double** pTab, int nDim )
{    
	if( nDim == 1 )
		return **pTab;

	if( nDim ==2 )
	{
		return **pTab * pTab[1][1] - pTab[1][0] * pTab[0][1];
	}

	double* p = *pTab;
	double det = 0;
	double** Tab = NULL;//pomocnicza
	if(!CreateMatrix( &Tab, nDim ))
    {
	perror( "ERROR: COULD NOT CREATE MATRIX" );
			return DBL_MIN;
    }

	int sign = 1;
    
	for( int i = 0;i < nDim;i++,p++ )
    {
	      Complement(Tab, pTab, 0, i, nDim);	
		  det +=sign *  *p * Det( Tab, nDim - 1 ) ;
		  sign = -sign;
	}

	return det;

}


void LayoutEqu( double** pInv, double* pB, double* pRes, int nDim )
{
	for( int i = 0; i < nDim;i++,pRes++)
	{
		
		double* t = *pInv++;
		double *p = pB;
		for( int j = 0; j < nDim;j++ )
		{
			*pRes += *t++ * *p++;
	
		}
	}
	
}
void InverseMatrix( double** pInv, double** pTab, int nDim, double det )
{
	ComplMatrix( pInv, pTab, nDim );
	TransMatrix( pInv, nDim );


	for( int i = 0;i < nDim;i++)
	{
		double*pT = *pInv++;
		
		for( int j = 0;j < nDim;j++)
		{

			*pT++=*pT / det;

		}
	}
	
}
