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

	//��ʼ������
	InitBoard(fact, ROWS, COLS, '0');
	InitBoard(mine, ROWS, COLS, '*');
	//չʾ
	DisplayBoard(mine, ROW, COL);
	//������
	Set_Board(fact, ROW, COL, Count);
	DisplayBoard(fact, ROW, COL);
	//����
	Find_Mine(mine, fact, ROW, COL, Count);
}
int main() {
	int input = 0;
	do {
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("ɨ����Ϸ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룺>\n");
			break;
		}		
	} while (input);
}
