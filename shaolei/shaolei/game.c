#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化
void InitBoard(char board[ROWS][COLS], int row, int col, char fuzhi) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) {
			board[i][j] = fuzhi;
		}
	}
}
//打印
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("-------------------------------------\n");
	printf("0  ");
	for (i = 1; i <= row; i++)
		printf("%d ", i);
	printf("\n");
	printf("\n");

	for (i = 1; i <= row; i++) {
		printf("%d  ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}
//布雷
void Set_Board(char board[ROWS][COLS], int row, int col, int count) {
	srand((int unsigned)time(NULL));
	int set = 0;
	while (set < count) {
		int x = rand()%row + 1;
		int y = rand()%col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			set++;
		}
	}
}
//排雷
void Find_Mine(char board[ROWS][COLS],char fact[ROWS][COLS], int row, int col, int count) {
	int win = 0;
	int x = 0;
	int y = 0;
	while (win < (row * col - count)) {
		printf("请输入排查坐标：\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && y > 0 && x <= row && y <= col)
		{
			if (fact[x][y] == '1') {
				printf("排到雷了，游戏失败！\n");
				DisplayBoard(fact, ROW, COL);
				break;
			}
			else if (board[x][y] == '*') {
				board[x][y] = Find_Lei(fact, x, y) + '0';
				win++;
				win += Is_Open(fact, board, x, y, win);
				printf("还剩%d格未排查！\n", row * col - win - count);
				if (win == (row * col - count)) {
					board[x][y] = 'W';
					printf("恭喜排雷成功！\n");
				}
				DisplayBoard(board, row, col);
			}
			else {
				printf("该坐标已经排查过，请重新输入：\n");
				continue;
			}
			printf("请继续：\n");
		}
		else
			printf("该坐标不存在，请重新输入：\n");
	}
}
//找雷个数
int Find_Lei(char fact[ROWS][COLS], int x, int y) {
	int i = 0, j = 0, sum = 0;
	for(int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++) {
			sum += (fact[x + i][y + j] - '0');
		}
	return sum;
}
//扩展区
int noagain[ROWS][COLS] = { 0 };
int Is_Open(char fact[ROWS][COLS],char board[ROWS][COLS], int x, int y, int win) {
	int sum = 0;
	if (board[x][y] == '0') {
		noagain[x][y] = 1;
		
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++) {
				if ((i != 0 || j != 0) && board[x + i][y + j] == '*' && (x + i <= ROW) && (y + j <= COL) && (x + i >=1) && (y + j >= 1)) {
					board[x + i][y + j] = Find_Lei(fact, x + i, y + j) + '0';
					sum += 1;
					if (noagain[x + i][y + j] == 0 && board[x + i][y + j] == '0') {
						int m = x + i, n = y + j;
						sum += Is_Open(fact, board, m, n, win);
					}
				}
			}
		}
	}
	return sum;
}
//void open_mine(int x, int y)//坐标周围展开函数
//{
//	if (real_mine[x - 1][y - 1] == '0')
//	{
//		show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x - 1][y] == '0')
//	{
//		show_mine[x - 1][y] = count_mine(x - 1, y) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x - 1][y + 1] == '0')
//	{
//		show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x][y - 1] == '0')
//	{
//		show_mine[x][y - 1] = count_mine(x, y - 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x][y + 1] == '0')
//	{
//		show_mine[x][y + 1] = count_mine(x, y + 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x + 1][y - 1] == '0')
//	{
//		show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x + 1][y] == '0')
//	{
//		show_mine[x + 1][y] = count_mine(x + 1, y) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x + 1][y + 1] == '0')
//	{
//		show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0';//显示该坐标周围雷数
//	}
//}

