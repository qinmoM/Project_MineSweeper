#define _CRT_SECURE_NO_WARNINGS

#include"11-29.h"

MOUSEMSG msg;

bool type = 1;// 判断是否在主界面
int bk = 0;// 默认白色主题
const wchar_t* symbol[8] = { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8" };// 用于提示数字

void SetBkColor()// 设置主题色
{
	switch (bk)
	{
	case 0:
		setbkcolor(WHITE);
		break;
	case 1:
		setbkcolor(COLOR);
		break;
	case 2:
		setbkcolor(RGB(204, 213, 240));
		break;
	case 3:
		setbkcolor(RGB(220, 200, 160));
		break;
	case 4:
		setbkcolor(RGB(250, 200, 250));
		break;
	case 5:
		setbkcolor(RGB(200, 255, 255));
		break;
	case 6:
		setbkcolor(RGB(255, 255, 200));
		break;
	case 7:
		setbkcolor(RGB(200, 255, 200));
		break;
	}
}

void SetFillColor()// 设置填充色
{
	switch (bk)
	{
	case 0:
	case 1:
		setfillcolor(COLOR);
		break;
	case 2:
		setfillcolor(RGB(204, 213, 240));
		break;
	case 3:
		setfillcolor(RGB(220, 200, 160));
		break;
	case 4:
		setfillcolor(RGB(240, 200, 240));
		break;
	case 5:
		setfillcolor(RGB(200, 255, 255));
		break;
	case 6:
		setfillcolor(RGB(255, 255, 200));
		break;
	case 7:
		setfillcolor(RGB(200, 255, 200));
		break;
	}
}

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

void Menu()// 绘制主界面
{
	BeginBatchDraw();//防止闪烁
	SetBkColor();// 设置背景色
	cleardevice();// 刷新背景
	settextstyle(IFONT_SIZE, 0, L"宋体");// 设置字体样式
	rectangle(10, 10, 11 + textwidth(L"切换主题颜色"), 11 + textheight(L"切换主题颜色"));// 主题色选项卡
	outtextxy(11, 11, L"切换主题颜色");// 切换主题颜色
	settextstyle(FONT_SIZE, 0, L"宋体");// 设置字体样式
	rectangle(SIZE * COL / 2 - 100, SIZE * ROW / 2 - 110,
		SIZE * COL / 2 + 100, SIZE * ROW / 2 - 30);// 绘制选项卡
	rectangle(SIZE * COL / 2 - 100, SIZE * ROW / 2 + 30,
		SIZE * COL / 2 + 100, SIZE * ROW / 2 + 110);// 绘制选项卡
	outtextxy((SIZE * COL - textwidth(L"开始游戏")) / 2,
		SIZE * ROW / 2 - 110 + (80 - textheight(L"开始游戏")) / 2, L"开始游戏");// 开始游戏
	outtextxy((SIZE * COL - textwidth(L"退出游戏")) / 2,
		SIZE * ROW / 2 + 30 + (80 - textheight(L"退出游戏")) / 2, L"退出游戏");// 退出游戏
	EndBatchDraw();// 关闭双缓冲绘图
}

void BoardDraw(char arr1[ROWS][COLS], char arr2[ROWS][COLS])// 绘制游戏内容
{
	BeginBatchDraw();//防止闪烁
	for (int i = 1; i < ROWS - 1; i++)
	{
		for (int j = 1; j < COLS - 1; j++)
		{
			if ('*' == arr2[i][j])// 未翻起
			{
				SetFillColor();// 主题填充色
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
			}
			else if ('1' == arr1[i][j])// 雷
			{
				setfillcolor(RED);// 红色
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
			}
			else if ('0' == arr2[i][j])// 翻起但是为0
			{
				setfillcolor(WHITE);// 白色
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
			}
			else// 其他数字
			{
				int number = arr2[i][j] - '0' - 1;
				setfillcolor(WHITE);// 白色
				fillrectangle(SIZE * (i - 1), SIZE * (j - 1), SIZE * i, SIZE * j);
				setbkcolor(WHITE);// 背景白色
				outtextxy((SIZE * (2 * i - 1) - textwidth(symbol[number])) / 2,
					(SIZE * (2 * j - 1) - textheight(symbol[number])) / 2, symbol[number]);
			}
		}
	}
	EndBatchDraw();// 关闭双缓冲绘图
}

char Calculate(char arr1[ROWS][COLS], short x, short y)// 计算周围雷数量
{
	return arr1[x - 1][y - 1] + arr1[x][y - 1] + arr1[x + 1][y - 1] + arr1[x - 1][y]
		+ arr1[x + 1][y] + arr1[x - 1][y + 1] + arr1[x][y + 1] + arr1[x + 1][y + 1] - 7 * '0';
}

void Recursion(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)// 迭代周围
{
	// 检测每个角落是否需要迭代
	if ('0' == arr2[x][y] && !(arr1[x][y] - '0'))// 为0才迭代周围
	{
		if (x < 6 && y < 6)// 右下
		{
			if ('*' == arr2[x + 1][y])// 如果未翻起
			{
				arr2[x + 1][y] = Calculate(arr1, x + 1, y);
				Recursion(arr1, arr2, x + 1, y);// 迭代周围
			}
			if ('*' == arr2[x][y + 1])// 如果未翻起
			{
				arr2[x][y + 1] = Calculate(arr1, x, y + 1);
				Recursion(arr1, arr2, x, y + 1);// 迭代周围
			}
			if ('*' == arr2[x + 1][y + 1])// 如果未翻起
			{
				arr2[x + 1][y + 1] = Calculate(arr1, x + 1, y + 1);
				Recursion(arr1, arr2, x + 1, y + 1);// 迭代周围
			}
		}
		if (x > 1 && y < 6)// 左下
		{
			if ('*' == arr2[x - 1][y])// 如果未翻起
			{
				arr2[x - 1][y] = Calculate(arr1, x - 1, y);
				Recursion(arr1, arr2, x - 1, y);// 迭代周围
			}
			if ('*' == arr2[x][y + 1])// 如果未翻起
			{
				arr2[x][y + 1] = Calculate(arr1, x, y + 1);
				Recursion(arr1, arr2, x, y + 1);// 迭代周围
			}
			if ('*' == arr2[x - 1][y + 1])// 如果未翻起
			{
				arr2[x - 1][y + 1] = Calculate(arr1, x - 1, y + 1);
				Recursion(arr1, arr2, x - 1, y + 1);// 迭代周围
			}
		}
		if (x < 6 && y > 1)// 右上
		{
			if ('*' == arr2[x + 1][y])// 如果未翻起
			{
				arr2[x + 1][y] = Calculate(arr1, x + 1, y);
				Recursion(arr1, arr2, x + 1, y);// 迭代周围
			}
			if ('*' == arr2[x][y - 1])// 如果未翻起
			{
				arr2[x][y - 1] = Calculate(arr1, x, y - 1);
				Recursion(arr1, arr2, x, y - 1);// 迭代周围
			}
			if ('*' == arr2[x + 1][y - 1])// 如果未翻起
			{
				arr2[x + 1][y - 1] = Calculate(arr1, x + 1, y - 1);
				Recursion(arr1, arr2, x + 1, y - 1);// 迭代周围
			}
		}
		if (x > 1 && y > 1)// 左上
		{
			if ('*' == arr2[x - 1][y])// 如果未翻起
			{
				arr2[x - 1][y] = Calculate(arr1, x - 1, y);
				Recursion(arr1, arr2, x - 1, y);// 迭代周围
			}
			if ('*' == arr2[x][y - 1])// 如果未翻起
			{
				arr2[x][y - 1] = Calculate(arr1, x, y - 1);
				Recursion(arr1, arr2, x, y - 1);// 迭代周围
			}
			if ('*' == arr2[x - 1][y - 1])// 如果未翻起
			{
				arr2[x - 1][y - 1] = Calculate(arr1, x - 1, y - 1);
				Recursion(arr1, arr2, x - 1, y - 1);// 迭代周围
			}
		}
	}
}

int Judge(char arr2[ROWS][COLS])// 遍历arr2中的未翻起元素数量
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

void Control(char arr1[ROWS][COLS], char arr2[ROWS][COLS], short m, short n)// 局内控制
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
	arr2[x][y] = Calculate(arr1, x, y);
	Recursion(arr1, arr2, x, y);// 连续空坐标周围全部显示
	BoardDraw(arr1, arr2);// 绘制游戏内
	if ('1' == arr1[x][y])// 判断是否踩雷
	{
		Sleep(1500);
		FlushMouseMsgBuffer();// 清空鼠标信息
		type = !type;// 切换鼠标控制逻辑
		Menu();// 绘制主界面
		outtextxy((getwidth() - textwidth(L"您已阵亡")) / 2,
			SIZE * ROW / 2 - 110 - textheight(L"您已阵亡") - 20, L"您已阵亡");// 绘制输
	}
	if (MINE == Judge(arr2))// 判断是否赢
	{
		type = !type;// 切换鼠标控制逻辑
		Menu();// 绘制主界面
		outtextxy((getwidth() - textwidth(L"恭喜胜利")) / 2,
			SIZE * ROW / 2 - 110 - textheight(L"恭喜胜利") - 20, L"恭喜胜利");// 绘制赢
	}
}

void GameControl(char arr1[ROWS][COLS], char arr2[ROWS][COLS])//鼠标信息控制
{
	if (MouseHit())
	{
		msg = GetMouseMsg();
		if (WM_LBUTTONUP == msg.uMsg)
		{
			if (type)// 是否为主菜单
			{
				if (msg.x > SIZE * COL / 2 - 100 && msg.x < SIZE * COL / 2 + 100
					&& msg.y > SIZE * ROW / 2 - 110 && msg.y < SIZE * ROW / 2 - 30)// 是否选中新游戏
				{
					type = !type;// 切换鼠标控制逻辑
					init_board(arr1, '0');
					random(arr1, MINE);
					init_board(arr2, '*');
					BoardDraw(arr1, arr2);// 绘制游戏内容
				}
				else if (msg.x > SIZE * COL / 2 - 100 && msg.x < SIZE * COL / 2 + 100
					&& msg.y > SIZE * ROW / 2 + 30 && msg.y < SIZE * ROW / 2 + 110)// 是否选中退出
				{
					exit(0);
				}
				else if (msg.x > 10 && msg.y > 10 &&
					msg.x < 11 + IFONT_SIZE * 6 && msg.y < 11 + IFONT_SIZE * 1)
				{
					bk = (bk + 1) % BKCOLOR;
					Menu();
				}
			}
			else// 局内
			{
				Control(arr1, arr2, msg.x, msg.y);// 局内控制
			}
		}
	}
}

int main()
{
	initgraph(SIZE * COL, SIZE * ROW);
	SetBkColor();// 设置主题色
	setlinecolor(BLACK);// 设置线条颜色
	settextcolor(BLACK);// 设置字体颜色
	settextstyle(FONT_SIZE, 0, L"宋体");// 设置字体样式
	int i = 0, j = 0, m = 0, input = 0, round = 0, u = 0;
	char arr1[ROWS][COLS] = { 0 };
	char arr2[ROWS][COLS] = { 0 };
	srand((unsigned int)time(NULL));
	Menu();// 绘制主界面
	do
	{
		GameControl(arr1, arr2);//鼠标信息控制
	} while (1);
	return 0;
}