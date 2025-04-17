#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <graphics.h>

#define BKCOLOR 4// ������ɫ����
#define ROW 6//����(�ɸ�)
#define COL 6//����(�ɸ�)
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE 6//����(�ɸ�)
#define SIZE 100// ���Ӵ�С
#define COLOR RGB(210, 210, 210)// ������ɫ
#define FONT_SIZE 35// �����С
#define IFONT_SIZE 30// �����������С

void SetBkColor();// ��������ɫ
void SetFillColor();// �������ɫ
void init_board(char arr[ROWS][COLS], char set);//��ʼ������Ϊ'set'�ַ�
void random(char arr1[ROWS][COLS], int mine);//�����������mine����
void Menu();// ����������
void BoardDraw(char arr1[ROWS][COLS], char arr2[ROWS][COLS]);// ������Ϸ����
char Calculate(char arr1[ROWS][COLS], short x, short y);// ������Χ������
void Recursion(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y);// ������Χ
int Judge(char arr2[ROWS][COLS]);// ����arr2�е�δ����Ԫ������
void Control(char arr1[ROWS][COLS], char arr2[ROWS][COLS], short m, short n);// ���ڿ���
void GameControl(char arr1[ROWS][COLS], char arr2[ROWS][COLS]);//�����Ϣ����