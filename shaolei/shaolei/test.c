#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu() {
	printf("***************************************\n");
	printf("*********       1.play        *********\n");
	printf("*********       0.exit        *********\n");
	printf("***************************************\n");
}
void game() {
	char fact[ROWS][COLS] = { '0' };
	char mine[ROWS][COLS] = { '*' };

	//初始化棋盘
	InitBoard(fact, ROWS, COLS, '0');
	InitBoard(mine, ROWS, COLS, '*');
	//展示
	DisplayBoard(mine, ROW, COL);
	//布置雷
	Set_Board(fact, ROW, COL, Count);
	DisplayBoard(fact, ROW, COL);
	//排雷
	Find_Mine(mine, fact, ROW, COL, Count);
}
int main() {
	int input = 0;
	do {
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("扫雷游戏！\n");
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入：>\n");
			break;
		}		
	} while (input);
}
