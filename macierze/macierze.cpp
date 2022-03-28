// macierze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "matrix.h"




#define _DEBUG_ 

void   ReadData( FILE * fin, double** pMatrix, double* bTab, int nDim );
void   DelateVector( double** pVector, int nDim );
void   PrintVector( double* pVector, int nDim );
int    CreateVector( double** pVector, int nDim );

int main( int argc, char* argv[] )
{
	
	if( argc != 2 )
	{
		printf("Usage: %s <input_file>", argv[0]); 
		return 1;
		}


	FILE* fin= fopen( argv[1], "r" );

	if( !fin)
	{
		printf( "ERROR: COULD NOT OPEN %s", argv[1]);
		return 3;
	}
	int nDim;
	fscanf( fin, "%d", &nDim );
	
	double** pTab = NULL;
	double* bTab = NULL;  

	if( !CreateMatrix( &pTab, nDim ) || (!CreateVector( &bTab, nDim )) )
	{
		perror( "ERROR: COULD NOT CREATE MATRIX");
		return 4;
	}


	ReadData(fin, pTab, bTab, nDim );
	
	fclose( fin );
	
#ifdef _DEBUG_

	
	    printf( "Size of Matrix: %d\n", nDim );
	  	printf( "\current matrix:\n" );
		PrintMatrix( pTab, nDim );
		printf( "\ncurrent vector\n" );
		PrintVector( bTab, nDim );
#endif


		double det = Det( pTab, nDim );
		if( abs(det)<=1e-16 )
		{
			perror( "Macierz  jest osobliwa" );
			return 2;
		}
		double** inv = NULL;
		if( !CreateMatrix( &inv, nDim ) )
		{
			perror( "ERROR: COULD NOT CREATE INVERSED MATRIX" );
			return 6;
		}
		InverseMatrix( inv, pTab, nDim, det );
#ifdef _DEBUG_
		printf( "\n" );
		printf( "\n" );
		printf( "\n det= %f ", det );
		printf( "\n" );
		printf( "\ninversed matrix\n" );
		PrintMatrix( inv, nDim );
		printf( "\n" );
#endif
		double* pRes = NULL;
		if( !CreateVector( &pRes, nDim ) )
		{
			perror( "ERROR: COULD NOT CREATE VECTOR" );
			return 5;
		}
			LayoutEqu( inv, bTab, pRes, nDim );
		
		printf( "\nsolution:\n" );
		PrintVector( pRes, nDim );
		DelateMatrix( &pTab,nDim );
		DelateMatrix( &inv,nDim );
		DelateVector( &bTab,nDim );
		DelateVector( &pRes,nDim );
		PrintVector( pRes, nDim );

		return 0;
}

void ReadData( FILE* fin, double** pMatrix, double* bTab, int nDim )
{
	for( int i = 0;i < nDim;i++ )
	{
		double *p = *pMatrix++;
		for( int j = 0;j < nDim;j++ )
			fscanf( fin, "%lf", p++ );
		fscanf( fin, "%lf", bTab++ );
	}

}

void DelateVector( double** pVector, int nDim )
{
	free( *pVector );
	*pVector = NULL;

}
void   PrintVector( double* pVector, int nDim )
{
	for( int i = 0; i < nDim; i++ )

		printf( "%lf ", *pVector++ );
}
int CreateVector( double**pVector, int nDim )
{
	*pVector = ( double* )malloc( nDim * sizeof( double ) );
	if( !pVector )
	{
	
		return 0;
	}
	memset( *pVector, 0, nDim * sizeof( double ) );
	return 1;
}
