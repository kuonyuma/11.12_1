#include "func.h"
int main()
{
	menu();
	int input = 0;
	cont arr;

	if (init_cont(&arr))
	{
		printf("初始化失败\n");
		return 1;
	}

	do
	{
		printf("选择功能>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			if (add_cont(&arr))
			{
				printf("添加联系人失败\n");
			}
			

			break;
		case 2:
			del_cont(&arr);
			break;
		case 3:
			show_cont(&arr);
			break;
		case 4:
			search_cont(&arr);
			break;
		case 5:
			rev_cont(&arr);
			break;
		case 6:
			sort_cont(&arr);
			break;
		case 0:
			retur(&arr);
			printf("*******************************\n");
			printf("********* !!程序退出!! ********\n");
			printf("*******************************\n");
			break;
		default:
				printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}