#include "modifystudent.h"
#include "studentManagerSystem.h"

void modifystudent(List* head)
{
	printf("请输入要修改的学生的学号\n");
	int stuNum;
	scanf("%d", &stuNum);
	List* move = head->next;
	while (move != NULL)
	{
		if (move->student.stuNum == stuNum)
		{
			printf("输入学生学号>");
			scanf("%llu", &move->student.stuNum);

			printf("输入学生姓名>");
			scanf("%s", move->student.name);

			printf("输入学生性别>");
			scanf("%s", &move->student.gender);

			printf("输入学生班级>");
			scanf("%s", &move->student.class);

			printf("输入学生出生日期>");
			scanf("%s", &move->student.birth);

			printf("输入学生联系方式>");
			scanf("%s", &move->student.phone);

			printf("输入学生地址>");
			scanf("%s", &move->student.address);
			savestudent(head); // 保存修改后的学生信息到文件
			printf("修改成功！\n");
			//暂停程序
			system("pause");
			//返回主菜但单
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到该学生信息，修改失败！\n");
	//暂停程序
	system("pause");
}

void deletestudent(List* head)
{
	printf("请输入要删除的学生的学号\n");
	int studentNum;
	scanf("%d", &studentNum);
	List* move = head;
	while (move->next != NULL)
	{
		if (move->next->student.stuNum == studentNum)
		{
			List* temp = move->next;
			move->next = move->next->next;
			free(temp);
			temp = NULL;
			savestudent(head); // 保存修改后的学生信息到文件
			printf("删除成功！\n");
			//暂停程序
			system("pause");
			//返回主菜单
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到该学生信息，删除失败！\n");
	//暂停程序
	system("pause");
	//返回主菜单
	system("cls");
	return;
}
