#include "BackTracking.h"


int CreateMatrix( int*** pTab, int nRow, int nCol )
{
	*pTab = (int**)calloc( nRow, sizeof( int* ) );
	if( !*pTab )
	{
		perror( "ERROR, MEMORY ALLOCATION, CreateMatrix BackTracking.cpp pTab" );
		return 0;
	}

	int** ppTab = *pTab;

	for( int i = 0; i < nRow; i++, ppTab++ )
	{
		*ppTab = (int*)calloc( nCol, sizeof( int ) );
		if( !*ppTab )
		{
			perror( "ERROR, MEMORY ALLOCATION, CreateMatrix BackTracking.cpp ppTab" );
			return 0;
		}
	}
	
	return 1;
}

void DeleteMatrix( int*** pTab, int nRow )
{
	int** ppTab = *pTab;

	for( int i = 0; i < nRow; i++, ppTab++ )
		free( *ppTab );

	free( *pTab );
	*pTab = NULL;
}


int move( int** pTab, int nRow, int nCol, int nDepth, int move, int x, int y, int* px, int* py, int** pRoot )
{
	// pTab to tablica o rozmiarach nRow nCol

	// pTab - tablica okreslajaca glebokosc w kazdym punkcie
	// nRow, nCol - rozmiar pTab
	// nDepth- minimalna glebokosc aby statek przeplynal
	// move- kierunek ruchu
	// x, y- indeksy w tablicy skad wykonujemy kolejny ruch np. zaczynamy od 0,0
	// px, py- nowe wspolrzedne // kolejny ruch o ile jest ten ruch mozliwy
	// pRoot - tablica pamietajaca ruchy o rozmiarze nRow, nCol

	//funkcja zwraca
	//	0 nie da sie wykonac ruchu
	//	1 da sie wykonac ruch

	//	w tej funkcji
	//	switch


	//		x, y - wspolrzedne skad robimy nowy ruch
	//		wykonac kolejny ruch w kieurnku move obliczajac nowe wspolrzedne *px *py
			//switch
			//sprawdzic czy nowe indeksy *px i *py sa w zakresie indeksow tablicy
			//a nastepnie sprawdzic warunek czy nie jest za plytko ">nDepth+1 " oraz
			// czy nie bylo sie juz w lokalizacji (*px, *py) - wg tablicy pRoot

			// jesli wszystkie warunki poprawne to zwracamy 1
			// else 0


	switch( move )
	{
	case UP:
		*px = x;
		*py = y + 1;
		break;

	case RIGHT:
		*px = x + 1;
		*py = y;
		break;

	case DOWN:
		*px = x;
		*py = y - 1;
		break;

	case LEFT:
		*px = x - 1;
		*py = y;
		break;
	}

	if( *px >= 0  && *px < N && *py >= 0 && *py < M )
		if( pTab[*px][*py] > nDepth && pRoot[*px][*py] == 0 )
			return 1;
	return 0;
}

int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest )
{
	// funkcja znajdujaca droge
//	pTab - tablica glebokosci o rozmiarze nRow i nCol
//		nDepth - glebokosc znaurzenia statku
//		x, y - wspolrzedne skad robimy kolejny ruch
//		pRoot - tablica kolejnych ruchow
//		x_dest, y_dest - wspolrzedne portu( wspolrzedne docelowe ) ( skrajny prawy rog ) ( prawy dolny rog ) ( n - 1, n - 1 )


	pRoot[x][y] = 1; // poczatkowy punkt odwiedzony 

	// dotarto do portu
	if( x == x_dest && y == y_dest )
	{
		printf( "(9, 9) <- " );
		return 1;
	}

	int new_x = x;
	int new_y = y;

	for( int i = UP; i <= LEFT; i++ )
	{
		if( move( pTab, nRow, nCol, nDepth, i, x, y, &new_x, &new_y, pRoot ) )
			if( root( pTab, nRow, nCol, nDepth, new_x, new_y, pRoot, x_dest, y_dest ) )
			{
				printf( "(%d, %d) <- ", y, x );
				return 1;
			}
	}
	pRoot[x][y] = -1; // powrot- zly ruch
	return 0;


}


void SetTab( char* sFile, int** pTab, int nRow, int nCol )
{
	// wczytuje dane z pliku
	// sFile - nazwa pliku wejsciowego - parametr main()
	// pTab - tablica glebokosci morza
	// nRow, nCol wymiary tej tablicy
	// dobrac glebokosci tak zeby pokrazyl statek

	FILE* pFile = NULL;

	if( ( pFile = ( fopen( sFile, "r" ) ) ) == NULL )
	{
		perror( "ERROR, OPEN FILE, SetTab" );
		return;
	}

	///////////////
	for( int i = 0; i < nRow; i++ )
	{
		int* pTemp = *pTab++;

		for( int j = 0; j < nCol; j++ )
			fscanf( pFile, "%d", pTemp++ );
	}

	fclose( pFile );
	
}


void PrintMatrix( int** pTab, int nRow, int nCol )
{
	for( int i = 0; i < nRow; i++ )
	{
		int* pTemp = *pTab++;

		for( int j = 0; j < nCol; j++ )
			printf( "  %d  ", *pTemp++ );

		printf( "\n" );
	}
}