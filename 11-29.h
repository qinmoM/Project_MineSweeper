#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 6//����(�ɸ�)
#define COL 6//����(�ɸ�)
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE 6//����(�ɸ�)

void init_board1(char arr[ROWS][COLS], int rows, int cols, char set);//��ʼ������Ϊ'set'�ַ�
void random(char arr1[ROWS][COLS], int rows, int cols, int mine);//�����������mine����
void show(char arr[ROWS][COLS], int rows, int cols);//��ӡ��������
char calculate(char arr[ROWS][COLS], int x, int y);//����x y������Χ�׵ĸ���