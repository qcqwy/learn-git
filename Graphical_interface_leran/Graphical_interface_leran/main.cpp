#include"game.h"
int main()
{
	mciSendString("open ./1.mp3 alias a ", NULL, 0, NULL);//音乐在当前目录下也可以写"open ./2.mp3"./这里可以省略
	mciSendString("play a", NULL, 0, NULL);
	system("pause");//这里没有暂停程序会直接停止听不到音乐
	initgraph(Row * Pic_Size, Col * Pic_Size+Pic_Size, NULL);
	game();
	closegraph();
	return 0;
}
/*#define _CRT_SECURE_NO_WARNINGS 1
#include<graphics.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#pragma warning(disable : 4996) 
#define ROW 10
#define COL 10
#define MINE 10
#define PIC_SIZE 40
int map[ROW + 2][COL + 2];
int i, j, flag;
IMAGE img[12];
void open(int r, int c);
void game();
void gameinit()
{
	flag = 0;
	srand((unsigned)time(NULL));
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			map[i][j] = 0;
		}
	}
	for (i = 0; i < MINE; )
	{
		int r = rand() % ROW + 1;
		int c = rand() % COL + 1;
		if (map[r][c] == 0)
		{
			map[r][c] = -1;
			i++;
		}
	}
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (map[i][j] == -1)
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] != -1)
						{
							map[m][n]++;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			map[i][j] += 20;
		}
	}
	char tmp[20] = { 0 };
	for (i = 0; i < 12; i++)
	{
		sprintf(tmp, "./image/%d.jpg", i);
		loadimage(&img[i], tmp, PIC_SIZE, PIC_SIZE);
	}
}
void gamedraw()
{
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (map[i][j] == -1)
			{
				putimage((j - 1) * PIC_SIZE, (i - 1) * PIC_SIZE, &img[9]);
			}
			else if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				putimage((j - 1) * PIC_SIZE, (i - 1) * PIC_SIZE, &img[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage((j - 1) * PIC_SIZE, (i - 1) * PIC_SIZE, &img[10]);
			}
			else if (map[i][j] > 30)
			{
				putimage((j - 1) * PIC_SIZE, (i - 1) * PIC_SIZE, &img[11]);
			}
		}
	}
}


int mouse()
{
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		int r = msg.y / PIC_SIZE + 1;
		int c = msg.x / PIC_SIZE + 1;
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (map[r][c] > 8 && map[r][c] < 29)
			{
				map[r][c] -= 20;
				flag++;
				open(r, c);
			}
			break;
		case WM_RBUTTONDOWN:
			if (map[r][c] > 8 && map[r][c] < 29)
			{
				map[r][c] += 20;
			}
			else if (map[r][c] > 30)
			{
				map[r][c] -= 20;
			}
			break;
		}
		return map[r][c];
	}
}



void open(int r, int c)
{
	if (map[r][c] == 0)
	{
		for (int m = r - 1; m <= r + 1; m++)
		{
			for (int n = c - 1; n <= c + 1; n++)
			{
				if (map[m][n] != 19 && map[m][n] > 8)
				{
					map[m][n] -= 20;
					flag++;
					open(m, n);
				}
			}
		}
	}
}
void judge()
{
	gamedraw();
	if (mouse() == -1)
	{
		gamedraw();//放置图片
		int isok = MessageBox(GetHWnd(), "You lose! Do you want to play again?", "notice", MB_OKCANCEL);
		if (isok == IDOK)
		{
			game();
		}
		else
		{
			exit(666);
		}
	}
	if (flag == ROW * COL - MINE)
	{
		gamedraw();//放置图片
		int isok = MessageBox(GetHWnd(), "You win! Do you want to play again?", "notice", MB_OKCANCEL);
		if (isok == IDOK)
		{
			game();
		}
		else
		{
			exit(666);
		}
	}

}

void game()
{
	gameinit();
	while (1)
	{
		judge();
	}
}
*/
