// statki.cpp : Defines the entry point for the console application.
//

#include "BackTracking.h"
//#include <stdio.h>

int main(int argc, char** argv)
{

	// !!argc
	// wykreowac dynamicznie dwie tablice dwuwymiarowe ( ogolnie moga byc rozne wymiary )
	// wykorzystac funkcje z matrixa ale dodac parametr z drugim wymiarem

	// wyzerowac obie tablice // chyba ze calloc w kreowaniu
	// wczytac dane ( sprawdzic argc )

	// jezeli nie znaleziono drogi od (0, 0) - funkcja rekur root - wypisac 
	// "** Nie ma mozliwosci doplynac do portu!!\n\n";

	//jesli ok to wypisac trase
	//zwolnic pamiec!!

	if( argc != 2 )
	{
		printf( "Aby wlaczyc wpisz: statki.exe <nazwa pliku txt>\n" );
		return 0;
	}

	int** pTab = NULL;
	if( !CreateMatrix( &pTab, N, M ) )
	{
		perror( "ERROR, MEMORY ALLOCATION, pTab statki.cpp" );
		return 0;
	}

	int** pRoot = NULL;
	if( !CreateMatrix( &pRoot, N, M ) )
	{
		perror( "ERROR, MEMORY ALLOCATION, pRoot statki.cpp" );
		return 0;
	}
	

	SetTab( argv[1], pTab, N, M );

	if( root( pTab, N, M, DEPTH_MIN, 0, 0, pRoot, N - 1 , M - 1 ) )
		printf( "\n\nDOPLYNIETO DO PORTU\n\n" );

	
	else
		printf( "** Nie ma mozliwosci doplynac do portu!!\n\n" );
	

	PrintMatrix( pRoot, N, M );
	
	DeleteMatrix( &pTab, N );
	DeleteMatrix( &pRoot, N );

	system("pause");
	return 0;
}


