#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_TELE 20
#define MAX_ID 20
#define MAX_SEX 20
#define INIT 3
#define UP 2
#pragma once

//人的信息
typedef struct peo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char id[MAX_ID];
	char sex[MAX_SEX];
	int higt;
}peo;

//typedef struct cont
//{
//	peo S[MAX];
//	int count;
//}cont;
typedef struct cont
{
	peo* S;
	int count;
	int volume;
}cont;

//菜单
void menu(void);

//创建联系人
int add_cont(cont*parr);

//清空
void retur(cont*arr);

//初始化通讯录
int init_cont(cont*parr);

//展示通讯录
void show_cont(const cont*parr);

//删除联系人
void del_cont(cont*parr);

//搜索联系人
void search_cont(const cont*parr);

//更改信息
void rev_cont(cont* parr);

//排序
void sort_cont(cont* parr);
