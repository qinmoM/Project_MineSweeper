#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 6//行数(可改)
#define COL 6//列数(可改)
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE 6//雷数(可改)

void init_board1(char arr[ROWS][COLS], int rows, int cols, char set);//初始化棋盘为'set'字符
void random(char arr1[ROWS][COLS], int rows, int cols, int mine);//对棋盘随机下mine个雷
void show(char arr[ROWS][COLS], int rows, int cols);//打印数组棋盘
char calculate(char arr[ROWS][COLS], int x, int y);//返回x y坐标周围雷的个数