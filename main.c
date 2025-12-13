#include<stdio.h>
void menu();

int main()
{
	while (1)
	{
		int choice;
		menu();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("添加成功\n");
			break;
		case 2:
			printf("删除成功\n");
			break;
		case 3:
			printf("修改成功\n");
			break;
		case 4:
			printf("查询成功\n");
			break;
		case 5:
		    printf("排序成功\n");
			break;
		case 6:
			printf("保存成功\n");
			break;
		case 0:
			printf("\n\n感谢您的使用\n\n");
			exit(0);
		default:
			printf("输入有误，请重新输入\n");
			system("pause");
			break;
		}
	}
	
	return 0;
}
void menu()
{
	//菜单
	printf("-----------------员工管理系统菜单----------------\n");
	printf("1.添加员工\n");
	printf("2.删除员工\n");
	printf("3.修改员工\n");
	printf("4.查询员工\n");
	printf("5.排序员工\n");
	printf("6.保存\n");
	printf("0.退出\n");
	printf("---------------------------------------------\n");

}