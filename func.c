#include "func.h"
//菜单函数
void menu(void)
{
	printf("*******************************\n");
	printf("*******************************\n");
	printf("*******   1.add   2.del    ****\n");
	printf("*******   3.show  4.search ****\n");
	printf("*******   5.Rev   6. sort  ****\n");
	printf("*******   0.exit           ****\n");
	printf("*******************************\n");
	printf("*******************************\n");

}

//初始化通讯录函数
//void init_cont(cont* parr)
//{
//	memset(parr->S,0,sizeof(parr->S));//parr->S等价于sizeof(peo)*MAX
//	parr->count = 0;
//}

int init_cont(cont* parr)
{
	parr->S = (peo*)malloc(INIT*sizeof(peo));
	if (parr->S==NULL)
	{
		printf("错误来源 init_cont:%s",strerror(errno));
		return 1;
	}
	parr->volume = INIT;
	memset(parr->S, 0, sizeof(peo)*INIT);
	parr->count = 0;
	return 0;
}

//添加联系人函数
//void add_cont(cont*parr)
//{
//	if (parr->count==MAX)printf("通讯录已满\n");
//	else 
//	{
//		
//		printf("请输入名字：\n");
//		scanf("%s", parr->S[parr->count].name);
//
//		printf("请输入电话号码：\n");
//		scanf("%s", parr->S[parr->count].tele);
//		
//		printf("请输入身份证号码：\n");
//		scanf("%s", parr->S[parr->count].id);
//		
//		printf("请输入性别：\n");
//		scanf("%s", parr->S[parr->count].sex);
//		
//		printf("请输入身高：\n");
//		scanf("%20d", &parr->S[parr->count].higt);
//		
//		parr->count++;
//		printf("输入成功\n");
//	}
//}

int add_cont(cont* parr)
{
	if (parr->count == parr->volume)
	{
		peo* ptr = realloc(parr->S, (parr->volume + UP) * sizeof(peo));
		if (ptr == NULL)
		{
			printf("容量扩容失败，错误来源add_cont %s\n",strerror(errno));
			return 1;
		}
		parr->S = ptr;
		parr->volume = parr->volume + UP;
		printf("扩容成功\n");
	}
	{

		printf("请输入名字：\n");
		scanf("%s", parr->S[parr->count].name);

		printf("请输入电话号码：\n");
		scanf("%s", parr->S[parr->count].tele);

		printf("请输入身份证号码：\n");
		scanf("%s", parr->S[parr->count].id);

		printf("请输入性别：\n");
		scanf("%s", parr->S[parr->count].sex);

		printf("请输入身高：\n");
		scanf("%20d", &parr->S[parr->count].higt);

		parr->count++;
		printf("输入成功\n");
	}
	return 0;
}

//展示通讯录
void show_cont(const cont* parr)
{
	printf("%s\t%s\t%s\t%s\t%s\n", "姓名", "电话号码", "ID", "性别", "身高");
	for (int i = 0; i < parr->count; i++)
	{
		printf("%s\t%s\t%s\t%s\t%d\n",
			parr->S[i].name,
			parr->S[i].tele,
			parr->S[i].id,
			parr->S[i].sex,
			parr->S[i].higt);
	}
}
//删除
void del_cont(cont* parr)
{
	if (parr->count == 0)
	{
		printf("联系人为空\n");
		return;
	}
	else
	{
		printf("请输入要删除的联系人姓名:\n");
		char name[MAX_NAME];
		scanf("%19s",name);
		int buff = 0;
		for (int i = 0; i < parr->count;i++)
		{
			int ret = strcmp(parr->S[i].name, name);
			if (ret==0)
			{
				 buff = i;
				 for (buff; buff < parr->count - 1; buff++)
				 {
					 parr->S[buff] = parr->S[buff+1];
				 }
				 parr->count--;
				 printf("删除成功\n");
				 return;
			}
		}
		printf("未找到该联系人\n");
	}
}
void search_cont(const cont* parr)
{
	printf("请输入要查找的联系人姓名:\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int buff = 0;
	for (int i = 0; i < parr->count; i++)
	{
		int ret = strcmp(parr->S[i].name, name);
		if (ret == 0)
		{
			buff = i;
			printf("!!!成功找到!!!\n");
			printf("%s\t%s\t%s\t%s\t%s\n", "姓名", "电话号码", "ID", "性别", "身高");
			printf("%s\t%s\t%s\t%s\t%d\n",
					parr->S[buff].name,
					parr->S[buff].tele,
					parr->S[buff].id,
					parr->S[buff].sex,
					parr->S[buff].higt);
			return;
		}
	}
	printf("未找到该联系人\n");
}
void rev_cont(cont*parr)
{
	printf("请输入要更改的联系人姓名:\n");
	char name[MAX_NAME];
	scanf("%19s", name);
	int buff = 0;
	for (int i = 0; i < parr->count; i++)
	{
		int ret = strcmp(parr->S[i].name, name);
		if (ret == 0)
		{
			buff = i;
			printf("请更改\n");
			printf("请输入名字：\n");
			scanf("%s", parr->S[buff].name);

			printf("请输入电话号码：\n");
			scanf("%s", parr->S[buff].tele);

			printf("请输入身份证号码：\n");
			scanf("%s", parr->S[buff].id);

			printf("请输入性别：\n");
			scanf("%s", parr->S[buff].sex);

			printf("请输入身高：\n");
			scanf("%20d", &parr->S[buff].higt);
			printf("已经更改\n");
			return;
		}
	}
	printf("未找到该联系人\n");

}
int my_cmp(const void*e1,const void*e2)
{
	
	return strcmp(((peo*)e1)->name, ((peo*)e2)->name);
}

void sort_cont(cont* parr)
{
	if (parr->count > 0)
	{
		qsort(parr->S, parr->count, sizeof(peo), my_cmp);
	}
	else
		printf("通讯录为空无法排序\n");
}

void retur(cont* parr)
{
	free(parr->S);
	parr->S = NULL;
	parr->volume = 0; 
	parr->count = 0;
}