#define _CRT_SECURE_NO_WARNINGS

#include"11-29.h"

void init_board(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void random(char arr[ROWS][COLS], int rows, int cols, int mine)
{
	int m = 0, j = 0, i = 0;
	for (m = 0; m < mine; m++)
	{
		i = rand() % ROW + 1;
		j = rand() % COL + 1;
		if ('1' != arr[i][j])
		{
			arr[i][j] = '1';
		}
		else
		{
			m--;
		}
	}
}

void show(char arr[ROWS][COLS], int rows, int cols)
{
	int i = 0, j = 0;
	printf("\n  ");
	for (i = 1; i < cols - 1; i++)
	{
		printf("^%d", i);
	}
	printf("\n");
	for (i = 1; i < rows - 1; i++)
	{
		printf("%2d", i);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%2c", arr[i][j]);
		}
		printf("\n");
	}
}

char calculate(char arr[ROWS][COLS], int x, int y)
{
	return arr[x - 1][y - 1] + arr[x][y - 1] + arr[x + 1][y - 1] + arr[x - 1][y] + arr[x + 1][y]
			+ arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1] - 7 * '0';
}

int main()
{
	int i = 0, j = 0, m = 0, input = 0, round = 0, u = 0;
	char arr1[ROWS][COLS] = { 0 };
	char arr2[ROWS][COLS] = { 0 };
	printf("**************欢迎来到扫雷游戏!**************\n");
	printf("*********************************************\n");
	printf("*****************1.开始游戏******************\n");
	printf("*****************0.退出游戏******************\n");
	printf("***********请输入数字进行下一步操作**********\n");
	srand((unsigned int)time(NULL));
	do
	{
		if (0 < m)
		{
			printf("\n*****************1.再来一局******************\n");
			printf("*****************0.退出游戏******************\n");
		}
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			return 0;
		case 1:
			u = 0;
			init_board(arr1, ROWS, COLS, '0');
			random(arr1, ROWS, COLS, MINE);
			init_board(arr2, ROWS, COLS, '*');
			for (round = 0; round < ROW * COL - MINE; round++)
			{
				show(arr2, ROWS, COLS);
				printf("\n请输入坐标(格式为：坐标>空格>含^坐标) :>\n");
				scanf("%d %d", &i, &j);
				if ('*' != arr2[i][j] || i < 1 || j < 1 || i > ROW || j > COL)
				{
					printf("坐标非法,请重新输入!");
					round--;
				}
				else if ('1' == arr1[i][j])
				{
					u++;
					break;
				}
				else
				{
					arr2[i][j] = calculate(arr1, i, j);
				}
			}
			if (0 == u)
			{
				printf("恭喜您，游戏胜利!");
				show(arr1, ROWS, COLS);
			}
			else
			{
				printf("您已死亡，游戏结束");
				show(arr1, ROWS, COLS);
			}
			break;
		default:
			printf("请输入正确数字\n");
		}
		m++;
	} while (1);
	return 0;
}