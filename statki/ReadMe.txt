========================================================================
    CONSOLE APPLICATION : statki Project Overview
========================================================================

AppWizard has created this statki application for you.

This file contains a summary of what you will find in each of the files that
make up your statki application.


statki.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

statki.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

statki.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named statki.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////


// BACKTRACKING.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "functions.h"


// BACKTRACKING ALGORYTM
// OPIS Z WIKIPEDII

// statek plynie do portu
// zatoka 

// zdefiniowac stale N i M - wymiary ( na 10 ) // 10 x 10

#define DEPTH_MIN 10 // glebokosc zanurzenia okretu // zeby dalo sie przeplynac statkiem to glebokosc musi byc 11 // x > 10

// zdefiniowac typ wyliczeniowy: kierunki ruchu: UP RIGHT DOWN LEFT lub UP LEFT RIGHT DOWN, domyslne wartosci, 0 1 2 3 

int move( int** pTab, int nRow, int nCol, int nDepth, int move, int x, int y, int* px, int* py, int** pRoot );
// pTab to tablica o rozmirach nRow nCol

/*
pTab- tablica okreslajaca glebokosc w kazdym kwadracie
nRow, nCol - rozmiar pTab
nDepth- minimalna glebokosc aby statek przeplynal
move - kierunek ruchu
x, y- indeksy w tablicy skad wykonujemy kolejny ruch np. zaczynamy od 0,0
px, py- nowe wspolrzedne // kolejny ruch o ile jest ten ruch mozliwy
pRoot- tablica pamietajaca ruchy o rozmiarze nRow, nCol

funkcja zwraca
0 nie da sie wykonac ruchu
1 da sie wykonac ruch

w tej funkcji
switch 


x, y- wspolrzedne skad robimy nowy ruch
wykonac kolejny ruch w kieurnku move obliczajac nowe wspolrzedne *px *py
//switch
//sprawdzic czy nowe indeksy *px i *py sa w zakresie indeksow tablicy
//a nastepnie sprawdzic warunek czy nie jest za plytko ">nDepth+1 " oraz
// czy nie bylo sie juz w lokalizacji (*px, *py) - wg tablicy pRoot

// jesli wszystkie warunki poprawne to zwracamy 1
// else 0


//////////////////////////////////////////////

int root ( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest );

// funkcja znajdujaca droge
pTab - tablica glebokosci o rozmiarze nRow i nCol
nDepth - glebokosc znaurzenia statku
x, y- wspolrzedne skad robimy kolejny ruch
pRoot- tablica kolejnych ruchow
x_dest, y_dest - wspolrzedne portu ( wspolrzedne docelowe ) ( skrajny prawy rog ) ( prawy dolny rog ) ( n -1, n -1 )


//////////////////////////////////////////////////////////////////////////////////

int root 
{
	/// tablica pRoot pamieta droge - 1 pole przez ktore odwiedzono ( plynie statek ), 0 pole nie odwiedzone

	if ( dotarto do portu )
		return 1;

		else
		{
			zdefiniowac nowe wspolrzedne
				sprawdzic wszystkie mozliwosci ruchu
					jesli ruch jest mozliwy w zadanym kierunku
						jesli wykonanie kolejnego kroku sie powiodlo - rekurencyjnie root()4
							return 1;
		}
		// jesli wracamy to ustawiamy w pRoot ze ruch byl zly
		return 0;
	
return 0;
}

///////////////////////


void clearRoot ( int** pRoot, int nRow, int nCol )
// potrzebne gdy malloc, jesli calloc to nie potrzebna


////////////////////////////////////

void setTab ( char* sFile, int** pTab, int nRow, int nCol );
// wczytuje dane z pliku
// sFile - nazwa pliku wejsciowego - parametr main()
// pTab - tablica glebokosci morza
// nRow, nCol wymiary tej tablicy
// dobrac glebokosci tak zeby pokrazyl statek


/////////////////

int main ()
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

return 0;
}


// W KOLEJKACH FUNKCJA TWORZACA NIECH ZWRACA 0 1
// 1 POWIODLO SIE
// 0 NIE POWIODLO SIE
// int QFCreate ( QueueFIFO* q ) // 1 powiodlo sie, 0 nie powiodlo sie
// w glowie tez
// 


















*/