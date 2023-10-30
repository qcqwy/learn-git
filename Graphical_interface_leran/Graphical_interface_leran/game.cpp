#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int map[Row+2][Col+2];
int i = 0, j = 0, flag = 0;
IMAGE img[12];
void game() {
	initgame();
	while (1) 
	{
		judge();
	}
}
//初始化游戏
void initgame() {
	srand((unsigned)time(NULL));
	flag = 0;
	for (i = 1; i <= Col; i++) {
		for (j = 1; j <= Row; j++) {
			map[i][j] = 0;
		}
	}
	for (i = 0; i < MINE;)
	{
		int x = rand() % Col + 1;
		int y = rand() % Row + 1;
		if (map[x][y] == 0)
		{
			map[x][y] = -1;
			i++;
		}
	}
	for (i = 1; i <= Col; i++) {
		for (j = 1; j <= Row; j++) {
			if (map[i][j] == -1) {
				for (int n = i - 1; n <= i + 1; n++) {
					for (int m = j - 1; m <= j + 1; m++) {
						if (map[n][m] != -1)
						{
							map[n][m]++;
						}
					}
				}
			}
		}
	}
	for (i = 1; i <= Col; i++) {
		for (j = 1; j <= Row; j++) {
			map[i][j] += 20;
		}
	}

	char tmp[20] = { 0 };
	for (i = 0; i < 12; i++)
	{
		sprintf(tmp, "./image/%d.jpg", i);
		loadimage(&img[i], tmp, Pic_Size, Pic_Size);
	}
}
//判断
void judge() {
	gamedraw();
	if (mouse() == -1) {
		gamedraw();
		int choice = MessageBox(GetHWnd(), "你输了，要重开一局吗？", "注意", MB_OKCANCEL);
		if (choice == IDOK)
			game();
		else
			exit(666);
	}
	if (flag == Row * Col - MINE) {
		gamedraw();
		int choice = MessageBox(GetHWnd(), "你赢了，要再来一把吗？", "注意", MB_OKCANCEL);
		if (choice == IDOK)
			game();
		else
			exit(666);
	}

}
//呈现图形
void gamedraw() {
	for (i = 1; i <= Col; i++) {
		for (j = 1; j <= Row; j++) {
			if (map[i][j] == -1)//雷
				putimage((j - 1) * Pic_Size, (i - 1) * Pic_Size, &img[9]);
			else if (map[i][j] >= 19 && map[i][j] <= 28)//空白
				putimage((j - 1) * Pic_Size, (i - 1) * Pic_Size, &img[10]);
			else if (map[i][j] <= 8 && map[i][j] >= 0)//数字
				putimage((j - 1) * Pic_Size, (i - 1) * Pic_Size, &img[map[i][j]]);
			else if (map[i][j] > 30)//标记
				putimage((j - 1) * Pic_Size, (i - 1) * Pic_Size, &img[11]);
		}
	}
	char grade[10];
	sprintf(grade, "%d", flag);
	settextcolor(0xFF5555);
	settextstyle(32, 32, grade);
	outtextxy(Col * Pic_Size / 2 - 28, Row * Pic_Size, grade);

	char illustrate[]= "已排个数：";
	settextcolor(0xFFFFFF);
	settextstyle(26, 16, illustrate);
	outtextxy(Col * Pic_Size / 2 - 184, Row * Pic_Size, illustrate);

	
}
 
int mouse() {
	if (MouseHit()) {
		MOUSEMSG msg = GetMouseMsg();
		int x = msg.y / Pic_Size + 1;
		int y = msg.x / Pic_Size + 1;
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (map[x][y] <= 28 && map[x][y] >8)
			{
				map[x][y] -= 20;
				flag++;
				open(x, y);
			}
			break;
		case WM_RBUTTONUP:
			if (map[x][y] <= 28 && map[x][y] > 8)
				map[x][y] += 20;
			else if (map[x][y] > 30)
				map[x][y] -= 20;
			break;
		}
		return map[x][y];
	}
}
void open(int x, int y) {
	if (map[x][y]==0)
	{
		for (int m = x - 1; m <= x + 1; m++)
		{
			for (int n = y - 1; n <= y + 1; n++)
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
