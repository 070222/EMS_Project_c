#include<stdio.h>
void menu();

int main()
{
	menu();
	return 0;
}
void menu()
{
	//菜单
	printf("-----------------员工管理系统----------------\n");
	printf("1.添加员工\n");
	printf("2.删除员工\n");
	printf("3.修改员工\n");
	printf("4.查询员工\n");
	printf("5.排序员工\n");
	printf("6.保存\n");
	printf("0.退出\n");
	printf("---------------------------------------------\n");

}