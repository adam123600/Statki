#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef enum { UP, RIGHT, DOWN, LEFT } kierunek; // typ wyliczeniowy: kierunki

#define N 10 // x
#define M 10 // y
#define DEPTH_MIN 10 // glebokosc zanurzenia okretu

int move( int** pTab, int nRow, int nCol, int nDepth, int move, int x, int y, int* px, int* py, int** pRoot );

int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest );

void SetTab( char* sFile, int** pTab, int nRow, int nCol );

int CreateMatrix( int*** pTab, int nRow, int nCol );
void DeleteMatrix( int*** pTab, int nRow );
void PrintMatrix( int** pTab, int nRow, int nCol );
