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
//删除员工
void delEmployee();
//根据下标删除员工
int delEmployeeByIndex(int indexOfDel);
//修改员工
void modEmployee();
//判断员工姓名是否重复
int getOneEmployeeName(char* name);
//员工查询
void findEmployee(int all);
//保存-覆盖写入员工信息
void writeEmployee();
//保存-读取已保存的员工信息
void readEmployee();



//主函数
int main()
{
	readEmployee();
	while (1)
	{
		int choice;
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			//添加员工
			addEmployee();
			break;
		case 2:
			//删除员工
			findEmployee(1);//all=1表示直接显示所有员工
			delEmployee();
			break;
		case 3:
			//修改员工
			findEmployee(1);
			modEmployee();
			break;
		case 4:
			//查询员工
			findEmployee(0);
			break;
		case 5:
		    printf("排序成功\n");
			break;
		case 6:
			//保存员工
			writeEmployee();
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
	printf("\n录入成功！员工数量：%d\n", employeeCount);
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
//删除员工
void delEmployee()
{
	printf("请输入需要删除的员工序号：");
	int indexOfDel;
	scanf("%d", &indexOfDel);
	int res = delEmployeeByIndex(indexOfDel);//调用删除函数(子函数)
	if (res)//1表示删除成功
	{
		printf("删除成功！\n");
	}
	else
	{
		printf("删除失败！\n");
	}
}
//根据下标删除员工
int delEmployeeByIndex(int indexOfDel)
{
	if (indexOfDel < 0 || indexOfDel >= employeeCount)
	{
		return 0;//删除失败
	}
	//开始删除
	for (int i = indexOfDel; i < employeeCount - 1; i++)
	{
		employeeList[i] = employeeList[i + 1];
	}
	employeeCount--;
	return 1;//删除成功
	
}
//修改员工
void modEmployee()
{
	printf("请输入要修改的员工的序号：");
	int indexOfMod = -1;
	scanf("%d", &indexOfMod);
	if (indexOfMod >= 0 && indexOfMod <employeeCount)
	{
		printf("请输入员工的新姓名：");
		char newName[20];
		scanf("%s", newName);
		while (strcmp(employeeList[indexOfMod].name, newName) != 0 &&
			getOneEmployeeName(newName) > -1)
		{
			printf("该员工姓名已存在！请重新输入：\n");
			scanf("%s", newName);
		}
		//跳出循环说明姓名不重复，可以修改
		strcpy(employeeList[indexOfMod].name, newName);	
		printf("\n请输入员工的性别：");
		scanf("%s", employeeList[employeeCount].gender);
		printf("\n请输入员工的电话：");
		scanf("%s", employeeList[employeeCount].tele);
		printf("\n请输入员工的年龄：");
		scanf("%d", &employeeList[employeeCount].age);
		printf("\n请输入员工的工资：");
		scanf("%lf", &employeeList[employeeCount].money);
		printf("修改成功！\n");
	}
	else
	{
		printf("输入的序号有误，修改失败！\n");
	}
}
//员工查询
void findEmployee(int all)
{
	//选择查询条件
	int select = 0;
	char conCharArr[40];//姓名和性别
	double conNum1, conNum2;//工资范围
	if (all == 0)//all为0表示需要选择查询条件
	{
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
		scanf("%lf", &conNum2); }
	
	}
	//打印表头
	printf("\n%-5s%-15s%-10s%-16s%-16s%-10s\n\n", "序号", "姓名", "性别", "电话", "工资", "年龄");
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
			printf("%-5d%-15s%-10s%-16s%-16lf%-10d\n\n"
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
//保存-覆盖写入员工信息
void writeEmployee()
{
	FILE* fp = NULL;
	fp = fopen("D:\\c\\EMS_Project_c\\EMS.txt", "w+");//覆盖写入
	for (int i = 0; i < employeeCount; i++)
	{
		fprintf(fp, "%s %s %s %lf %d\n",
			employeeList[i].name, employeeList[i].gender, employeeList[i].tele, employeeList[i].money, employeeList[i].age);
	} 
	fclose(fp);
} 
//保存-读取已保存的员工信息
void readEmployee()
{
	FILE* fp = NULL;
	if (NULL == (fp = fopen("D:\\c\\EMS_Project_c\\EMS.txt", "r")))
	{
				printf("文件打开失败，可能是文件不存在！\n");
				return;
	}
	int i = 0;
	while (
		fscanf(fp, "%s%s%s%lf%d\n",
			employeeList[i].name, employeeList[i].gender, employeeList[i].tele,&employeeList[i].money, &employeeList[i].age) != EOF)
	{
		i++;
	}
	employeeCount = i;
	fclose(fp);
}