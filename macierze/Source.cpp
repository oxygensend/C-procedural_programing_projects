double CreateMatrix( double*** pMatrix, int nDim )
{


	*pMatrix = (double**)malloc( nDim * sizeof( double* ) ); //alokacja pamieci dla  wskaznika g³ownego
	if(!pMatrix)
	{
		perror( "1Memory allocation error\n" );
		return 0; // niepowodzenie
	}


	double **ptr = *pMatrix;

	for(int i = 0;i < nDim;i++)
	{
		*ptr = (double*)malloc( nDim * sizeof( double* ) ); //alokacja dla poszczegolnych wierszy

		if(!ptr[i])
		{
			perror( "2Memory allocation error\n" );
			return 0;// niepowodzenie

		}
	}

	memset( *pMatrix, 0, nDim * sizeof( double* ) );
	return 1; //powodzenie
}

void FreeMatrix( double*** pMatrix, int nDim )
{
	for(int i = 0;i < nDim;i++)
	{
		free( (*pMatrix)[i] );
	}
	free( *pMatrix );
}