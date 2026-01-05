#include "studentManagerSystem.h"
#include "modifystudent.h"
#include "sortstudent.h"
#include "chartstudent.h"

int main()
{
	// 创建链表头节点
	List* head = (List*)malloc(sizeof(List));
	head->next = NULL;
	loadstudent(head);
	// 主循环
	while (1)
	{
		welcome();
		char c = _getch();
		switch (c)
		{
		case '1':// 录入学生信息
			inputstudent(head);
			break;
		case '2':// 打印学生信息
			printstudent(head);
			break;
		case '3':// 统计学生信息
			countstudent(head);
			break;
		case '4':// 查找学生信息
			findstudent(head);
			break;
		case '5':// 修改学生信息
			modifystudent(head);
			break;
		case '6':// 删除学生信息
			deletestudent(head);
			break;
		case '7':// 按成绩排序
			sortstudent(head);
			break;
		case '8':// 学生成绩报表
			ClassOrAllService(head);
			break;
		case '9':// 退出系统
			printf("感谢使用学生成绩管理系统，再见！\n");
			free(head); // 释放链表头节点内存
			head = NULL;
			system("pause");
			return 0;
		default:
			printf("无效的选择，请重新输入！\n");
			break;
		}
	}
	return 0;
}																																														

void welcome()
{
	printf("*********************************\n");
	printf("*    欢迎使用学生成绩管理系统   *\n");
	printf("*********************************\n");
	printf("*\t请选择功能列表:\t\t*\n");
	printf("*********************************\n");
	printf("*\t1. 录入学生信息\t\t*\n");
	printf("*\t2. 打印学生信息\t\t*\n");
	printf("*\t3. 统计学生信息\t\t*\n");
	printf("*\t4. 查找学生信息\t\t*\n");
	printf("*\t5. 修改学生信息\t\t*\n");
	printf("*\t6. 删除学生信息\t\t*\n");
	printf("*\t7. 按成绩排序\t\t*\n");
	printf("*\t8. 学生成绩报表及个性化\t*\n");
	printf("*\t9. 退出系统\t\t*\n");
	printf("*********************************\n");

}

void reportwelcome()
{
	printf("*********************************\n");
	printf("*    欢迎使用学生成绩报表系统   *\n");
	printf("*********************************\n");
	printf("*\t请选择功能列表:\t\t*\n");
	printf("*********************************\n");
	printf("*\t1. 生成成绩分布表\t*\n");
	printf("*\t2. 生成成绩分析表\t*\n");
	printf("*\t3. 返回主菜单\t\t*\n");
	printf("*********************************\n");
}

void inputstudent(List* head)
{
	List* fresh = malloc(sizeof(List));
	fresh->next = NULL;
	printf("请输入学生的学号, 姓名, 成绩, 班级：\n");
	scanf("%d%s%d%d", &fresh->student.stuNum, fresh->student.name, &fresh->student.score, &fresh->student.class);

	List* move = head;
	while (move->next != NULL)
	{
		move = move->next;
	}
	// 将新节点添加到链表末尾
	move->next = fresh;
	// 保存学生信息到文件
	savestudent(head);

	//暂停程序
	system("pause");
	//返回主菜单
	system("cls");
}

void printstudent(List* head)
{
	int class;
	printf("请输入要打印学生的班级\n");
	printf("如需全部打印请按0\n");
	scanf("%d", &class);
	List* move = head->next;
	while (move != NULL)
	{
		if (class == move->student.class)
		{
			printf("学号：%d 姓名：%s 成绩: %d 班级：%d\n", move->student.stuNum, move->student.name, move->student.score, move->student.class);
			move = move->next;
		}
		else if (class == 0)
		{
			printf("学号：%d 姓名：%s 成绩: %d 班级：%d\n", move->student.stuNum, move->student.name, move->student.score, move->student.class);
			move = move->next;
		}
		else
		{
			move = move->next;
		}
	}
	//暂停程序
	system("pause");
	//返回主菜单
	system("cls");
}

void countstudent(List * head)
{
	int count = 0;
	List* move = head->next;
	while (move != NULL)
	{
		count++;
		move = move->next;
	}
	printf("学生总数为：%d\n", count);
	//暂停程序
	system("pause");
	//返回主菜单
	system("cls");
}

void findstudent(List* head)
{
	printf("请输入要查找的学生的学号\n");
	int studentNum1;
	scanf("%d", &studentNum1);
	List* move = head->next;
	while (move != NULL)
	{
		if (move->student.stuNum == studentNum1)
		{
			printf("找到学生信息：学号：%d 姓名：%s 成绩: %d\n", move->student.stuNum, move->student.name, move->student.score);
			//暂停程序
			system("pause");
			//返回主菜单
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到该学生信息！\n");
	//暂停程序
	system("pause");
	//返回主菜单
	system("cls");
}

void savestudent(List* head)
{
	// 打开文件进行写入
	FILE* file = fopen("./student.info", "w");
	List* move = head->next;
	if (file == NULL)
	{
		printf("无法打开文件进行保存！\n");
		return;
	}

	while (move != NULL)
	{
		// 将学生信息写入文件
		if (fwrite(&move->student, sizeof(student), 1, file) != 1)
		{
			printf("写入文件时出错！\n");
			return;
		}
		move = move->next;
	}
	// 关闭文件
	fclose(file);
}

void loadstudent(List* head)
{
	// 打开文件进行读取
	FILE* file = fopen("./student.info", "r");
	if (file == NULL)
	{
		printf("无法打开文件进行读取！\n");
		return;
	}
	List* fresh = malloc(sizeof(List));
	fresh->next = NULL;
	List* move = head;
	while (fread(&fresh->student, sizeof(student), 1,file ) == 1)
	{
		move->next = fresh;
		move = fresh;
		fresh = malloc(sizeof(List));
		fresh->next = NULL;
	}
	free(fresh);
	// 关闭文件
	fclose(file);
	printf("学生信息加载完成！\n");
}



