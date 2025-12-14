#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//员工结构体
struct Employee
{
	char name[15];//姓名
	char gender[8];//性别
	char tele[12];//电话
    double money;//工资
	int age;//年龄	
};
//员工结构体数组
struct Employee employeeList[100];
//记录当前员工的数量
int employeeCount = 0;
//菜单
void menu();
//添加员工
void addEmployee();
//判断员工姓名是否重复
int getOneEmployeeName(char* name);
//员工查询
void findEmployee();



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
			findEmployee();
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
//菜单
void menu()
{
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
		int index = getOneEmployeeName(employeeList[employeeCount].name);
		if (index != -1)
		{
			printf("该员工已存在！工号%d重复\n",index);
			break;
		}
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
//传入一个姓名，然后循环判断，重复就返回员工的下表，不重复就返回-1
int getOneEmployeeName(char* name)
{
	int res = -1;
	for (int i = 0; i < employeeCount; i++)
	{
		if (strcmp(name, employeeList[i].name) == 0)
		{
			//表示重复
			res = i;
			break;
		}
	}		
	return res;
	}
//员工查询
void findEmployee()
{
	//选择查询条件
	int select = 0;
	char conCharArr[40];//姓名和性别
	double conNum1, conNum2;//工资范围
	printf("0:全部\n");
	printf("1:按 姓名 查询\n");
	printf("2:按 性别 查询\n");
	printf("3:按 工资 查询\n");
	printf("请输入选择：\n");
	scanf("%d", &select);
	//录入筛选条件
	if (select == 1 || select == 2)
	{
		printf("请输入筛选条件：");
		scanf("%s", conCharArr);
	}
	else if (select == 3)
	{
		printf("请输入筛选范围m,n，用空格隔开（m <= 工资 <= n）");
		scanf("%lf", &conNum1);
		scanf("%lf", &conNum2);
	}
	//打印表头
	printf("\n%-5s%-15s%-10s%-16s%-12s%-10s\n\n", "序号", "姓名", "性别", "电话", "工资", "年龄");
	//输出符合条件的员工信息
	int count = 0;//符合条件的人数
	double sumMoney = 0.0;//符合条件的员工工资总和
	int sumAge = 0;//符合条件的员工年龄总和
	for (int i = 0; i < employeeCount; i++)
	{
		//select conCharArr
		if (
			select == 0
			||
			select == 1 && strstr(employeeList[i].name, conCharArr)
			||
			select == 2 && strstr(employeeList[i].gender, conCharArr)
			||
			select == 3 && employeeList[i].money >= conNum1 && employeeList[i].money <= conNum2
			)
		{
			printf("%-5d%-15s%-10s%-16s%-12lf%-10d\n\n"
				, i
				, employeeList[i].name
				, employeeList[i].gender
				, employeeList[i].tele
				, employeeList[i].money
				, employeeList[i].age
			);
			count++;
			sumMoney += employeeList[i].money;
			sumAge += employeeList[i].age;
		}
	}
	printf("\n符合条件的员工数量：%d\n", count);
	printf("\n符合条件的员工的平均工资：%.2lf\n", count == 0 ? 0.0 : (sumMoney / count));
	printf("\n符合条件的员工的平均年龄：%.2lf\n", count == 0 ? 0.0 : (sumAge * 1.0 / count));
}