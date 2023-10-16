#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//变量声明
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Count 7
//函数声明
void InitBoard(char board[ROWS][COLS], int row, int col, char fuzhi);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Set_Board(char board[ROWS][COLS], int row, int col);
int Find_Lei(char board[ROWS][COLS], int x, int y);
void Find_Mine(char board[ROWS][COLS],char fact[ROWS][COLS], int row, int col, int count);
int Is_Open(char fact[ROWS][COLS], char board[ROWS][COLS], int x, int y, int win);