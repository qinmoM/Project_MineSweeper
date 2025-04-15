#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <graphics.h>

#define ROW 6//行数(可改)
#define COL 6//列数(可改)
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE 6//雷数(可改)
#define SIZE 100// 格子大小
#define COLOR RGB(210, 210, 210)// 背景颜色

void init_board(char arr[ROWS][COLS], char set);//初始化棋盘为'set'字符
void random(char arr1[ROWS][COLS], int mine);//对棋盘随机下mine个雷
void Menu();// 绘制主界面
void BoardDraw(char arr1[ROWS][COLS], char arr2[ROWS][COLS]);// 绘制游戏内容
int Judge(char arr2[ROWS][COLS]);// 遍历arr2中的未翻起元素数量
void Control(char arr1[ROWS][COLS], char arr2[ROWS][COLS], short m, short n);// 局内控制
void GameControl(char arr1[ROWS][COLS], char arr2[ROWS][COLS]);//鼠标信息控制