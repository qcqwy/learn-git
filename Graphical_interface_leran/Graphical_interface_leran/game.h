#define  _CRT_SECURE_NO_WARNINGS 1
//所需库
#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<mmsystem.h> //用来包含多媒体设备接口头文件
#pragma warning(disable : 4996)
#pragma comment (lib,"winmm.lib")//用来加载静态库
//所需变量
#define Row 10  //行数
#define Col 10  //列数
#define MINE 10  //雷数
#define Pic_Size 40  //图片大小

extern int map[Row+2][Col+2];  
extern int i, y, flag; //flag 为排雷个数
extern IMAGE img[12]; //存放图片

//所需函数
void initgame();  //布雷数据形成
void game();  //封装主体
void judge();  //判断结果
void gamedraw(); //呈现图形
int mouse(); //执行鼠标操作
void open(int x, int y);//展开非雷区域