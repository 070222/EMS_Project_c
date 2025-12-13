#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//员工结构体
struct Employee
{
	char name[15];//姓名
	char gender[8];//性别
	char tele[12];//电话
	int age;//年龄
	double money;//工资
};
//员工结构体数组
struct Employee employeeList[100];
//记录当前员工的数量
int employeeCount = 0;
//菜单
void menu();
//添加员工
void addEmployee();

int main()
{
	while (1)
	{
		int choice;
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			addEmployee();
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
//添加员工
void addEmployee()
{
	char selectYNFlag = 'y';
	while (selectYNFlag == 'y' || selectYNFlag == 'Y')
	{
		printf("\n请输入员工的姓名：");
		scanf("%s", employeeList[employeeCount].name);
		printf("\n请输入员工的性别：");
		scanf("%s", employeeList[employeeCount].gender);
		printf("\n请输入员工的电话：");
		scanf("%s", employeeList[employeeCount].tele);
		printf("\n请输入员工的年龄：");
		scanf("%d", &employeeList[employeeCount].age);
		printf("\n请输入员工的工资：");
		scanf("%lf",&employeeList[employeeCount].money);
		employeeCount++;
		printf("\n是否继续添加：");
		 int ch = getchar();
		 (void)ch;//防止getchar()警告
		scanf("%c", &selectYNFlag);
	}
	printf("员工数量：%d\n", employeeCount);
}