#define _CRT_SECURE_NO_WARNINGS

#include"11-29.h"

MOUSEMSG msg;

bool type = 1;// �ж��Ƿ���������
const wchar_t* symbol[8] = { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8" };// ������ʾ����

void init_board(char arr[ROWS][COLS], char set)
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] = set;
		}
	}
}

void random(char arr1[ROWS][COLS], int mine)
{
	int m = 0, j = 0, i = 0;
	for (m = 0; m < mine; m++)
	{
		i = rand() % ROW + 1;
		j = rand() % COL + 1;
		if ('1' != arr1[i][j])
		{
			arr1[i][j] = '1';
		}
		else
		{
			m--;
		}
	}
}

void Menu()// ����������
{
	BeginBatchDraw();//��ֹ��˸
	cleardevice();// ˢ�±���
	rectangle(SIZE * COL / 2 - 100, SIZE * ROW / 2 - 110,
		SIZE * COL / 2 + 100, SIZE * ROW / 2 - 30);// ����ѡ�
	rectangle(SIZE * COL / 2 - 100, SIZE * ROW / 2 + 30,
		SIZE * COL / 2 + 100, SIZE * ROW / 2 + 110);// ����ѡ�
	outtextxy((SIZE * COL - textwidth(L"��ʼ��Ϸ")) / 2,
		SIZE * ROW / 2 - 110 + (80 - textheight(L"��ʼ��Ϸ")) / 2, L"��ʼ��Ϸ");// ��ʼ��Ϸ
	outtextxy((SIZE * COL - textwidth(L"�˳���Ϸ")) / 2,
		SIZE * ROW / 2 + 30 + (80 - textheight(L"�˳���Ϸ")) / 2, L"�˳���Ϸ");// �˳���Ϸ
	EndBatchDraw();// �ر�˫�����ͼ
}

void BoardDraw(char arr1[ROWS][COLS], char arr2[ROWS][COLS])// ������Ϸ����
{
	BeginBatchDraw();//��ֹ��˸
	for (int i = 1; i < ROWS - 1; i++)
	{
		for (int j = 1; j < COLS - 1; j++)
		{
			if ('*' == arr2[i][j])// δ����
			{
				setfillcolor(COLOR);// ��ɫ
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
			}
			else if ('0' == arr2[i][j])// ������Ϊ0
			{
				setfillcolor(WHITE);// ��ɫ
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
			}
			else if ('1' == arr1[i][j])// ��
			{
				setfillcolor(RED);// ��ɫ
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
			}
			else// ��������
			{
				int number = arr2[i][j] - '0' - 1;
				setfillcolor(WHITE);// ��ɫ
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
				outtextxy((SIZE * (2 * i - 1) - textwidth(symbol[number])) / 2,
					(SIZE * (2 * j - 1) - textheight(symbol[number])) / 2,
					symbol[number]);
			}
		}
	}
	EndBatchDraw();// �ر�˫�����ͼ
}

int Judge(char arr2[ROWS][COLS])// ����arr2�е�δ����Ԫ������
{
	int num = 0;
	for (int i = 1; i < ROWS - 1; i++)
	{
		for (int j = 1; j < COLS - 1; j++)
		{
			if ('*' == arr2[i][j])
			{
				num++;
			}
		}
	}
	return num;
}

void Control(char arr1[ROWS][COLS], char arr2[ROWS][COLS], short m, short n)// ���ڿ���
{
	short x = m / SIZE + 1, y = n / SIZE + 1;
	if (7 == x)
	{
		x = 6;
	}
	if (7 == y)
	{
		y = 6;
	}
	arr2[x][y] = arr1[x - 1][y - 1] + arr1[x][y - 1] + arr1[x + 1][y - 1] + arr1[x - 1][y]
		+ arr1[x + 1][y] + arr1[x - 1][y + 1] + arr1[x][y + 1] + arr1[x + 1][y + 1] - 7 * '0';
		BoardDraw(arr1, arr2);
		if ('1' == arr1[x][y])// �ж��Ƿ����
		{
			Sleep(1500);
			FlushMouseMsgBuffer();// ��������Ϣ
			type = !type;// �л��������߼�
			Menu();// ����������
			outtextxy((getwidth() - textwidth(L"��������")) / 2,
				SIZE * ROW / 2 - 110 - textheight(L"��������") - 20, L"��������");// ������
		}
		if (MINE == Judge(arr2))// �ж��Ƿ�Ӯ
		{
			type = !type;// �л��������߼�
			Menu();// ����������
			outtextxy((getwidth() - textwidth(L"��ϲʤ��")) / 2,
				SIZE * ROW / 2 - 110 - textheight(L"��ϲʤ��") - 20, L"��ϲʤ��");// ����Ӯ
		}
}

void GameControl(char arr1[ROWS][COLS], char arr2[ROWS][COLS])//�����Ϣ����
{
	if (MouseHit())
	{
		msg = GetMouseMsg();
		if (WM_LBUTTONUP == msg.uMsg)
		{
			if (type)// �Ƿ�Ϊ���˵�
			{
				if (msg.x > SIZE * COL / 2 - 100 && msg.x < SIZE * COL / 2 + 100
					&& msg.y > SIZE * ROW / 2 - 110 && msg.y < SIZE * ROW / 2 - 30)// �Ƿ�ѡ������Ϸ
				{
					type = !type;// �л��������߼�
					init_board(arr1, '0');
					random(arr1, MINE);
					init_board(arr2, '*');
					BoardDraw(arr1, arr2);// ������Ϸ����
				}
				else if (msg.x > SIZE * COL / 2 - 100 && msg.x < SIZE * COL / 2 + 100
					&& msg.y > SIZE * ROW / 2 + 30 && msg.y < SIZE * ROW / 2 + 110)// �Ƿ�ѡ���˳�
				{
					exit(0);
				}
			}
			else// ����
			{
				Control(arr1, arr2, msg.x, msg.y);// ���ڿ���
			}
		}
	}
}

int main()
{
	initgraph(SIZE * COL, SIZE * ROW);
	setbkcolor(COLOR);// ���ñ���ɫ
	setlinecolor(BLACK);// ����������ɫ
	settextcolor(BLACK);// ����������ɫ
	settextstyle(35, 0, L"����");// ����������ʽ
	int i = 0, j = 0, m = 0, input = 0, round = 0, u = 0;
	char arr1[ROWS][COLS] = { 0 };
	char arr2[ROWS][COLS] = { 0 };
	srand((unsigned int)time(NULL));
	Menu();// ����������
	do
	{
		GameControl(arr1, arr2);//�����Ϣ����
	} while (1);
	return 0;
}