#define  _CRT_SECURE_NO_WARNINGS 1
//�����
#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<mmsystem.h> //����������ý���豸�ӿ�ͷ�ļ�
#pragma warning(disable : 4996)
#pragma comment (lib,"winmm.lib")//�������ؾ�̬��
//�������
#define Row 10  //����
#define Col 10  //����
#define MINE 10  //����
#define Pic_Size 40  //ͼƬ��С

extern int map[Row+2][Col+2];  
extern int i, y, flag; //flag Ϊ���׸���
extern IMAGE img[12]; //���ͼƬ

//���躯��
void initgame();  //���������γ�
void game();  //��װ����
void judge();  //�жϽ��
void gamedraw(); //����ͼ��
int mouse(); //ִ��������
void open(int x, int y);//չ����������