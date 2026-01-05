#include "chartstudent.h"


void chartstudent(List* head)
{
	while (1)
	{
		reportwelcome();
		char c = getch();
		switch (c)
		{
		case '1':// 生成成绩分布表
			distributionstudent(head);
			break;
		case '2':// 生成成绩分析表
			analysisstudent(head);
			break;
		case '3':// 返回主菜单
			return;
		default:
			printf("无效的选择，请重新输入！\n");
			break;
		}
		//暂停程序
		system("pause");
		//返回主菜单
		system("cls");
	}
}

void distributionstudent(List* head)
{
	int score0_60 = 0;
	int score61_70 = 0;
	int score71_80 = 0;
	int score81_90 = 0;
	int score91_100 = 0;
	List* move = head->next;
	while (move != NULL)
	{
		if (move->student.score >= 0 && move->student.score < 60)
		{
			score0_60 += 1;
		}
		else if (move->student.score >= 60 && move->student.score <= 70)
		{
			score61_70 += 1;
		}
		else if (move->student.score >= 71 && move->student.score <= 80)
		{
			score71_80 += 1;
		}
		else if (move->student.score >= 81 && move->student.score <= 90)
		{
			score81_90 += 1;
		}
		else if (move->student.score >= 91 && move->student.score <= 100)
		{
			score91_100 += 1;
		}
		move = move->next;
	}
	printf("成绩分布表如下：\n");
	printf("0-60分人数：%d\n", score0_60);
	printf("61-70分人数：%d\n", score61_70);
	printf("71-80分人数：%d\n", score71_80);
	printf("81-90分人数：%d\n", score81_90);
	printf("91-100分人数：%d\n", score91_100);
}

void anaiysisReportWelcome()
{
	printf("*********************************\n");
	printf("*    欢迎使用学生成绩分析系统   *\n");
	printf("*********************************\n");
	printf("*\t请选择功能列表:\t\t*\n");
	printf("*********************************\n");
	printf("*\t1. 平均分分析\t\t*\n");
	printf("*\t2. 最高分分析\t\t*\n");
	printf("*\t3. 最低分分析\t\t*\n");
	printf("*\t4. 成绩及格分析\t\t*\n");
	printf("*\t5. 返回主菜单\t\t*\n");
	printf("*********************************\n");
}

void analysisstudent(List* head)
{
	List* move = head->next;
	anaiysisReportWelcome();
	while (1)
	{
		char c = getch();
		switch (c)
		{
		case '1':// 平均分分析
			AverageScore(head);
			break;
		case '2':// 最高分分析
			HighestScore(head);
			break;
		case '3':// 最低分分析
			LowestScore(head);
			break;
		case '4':// 成绩及格分析
			PassScoreAnalysis(head);
			break;
		case '5':// 返回主菜单
			return;
		default:
			printf("无效的输入！");
		}
	}
	//暂停程序
	system("pause");
	//返回主菜单
	system("cls");

	return;
}

static void AverageScore(List* head)
{
	printf("正在计算学生平均分...\n");
	List* move = head->next;
	int totalScore = 0;
	int studentCount = 0;
	while (move != NULL)
	{
		totalScore += move->student.score;
		studentCount++;
		move = move->next;
	}
	if (studentCount > 0)
	{
		double averageScore = (double)totalScore / studentCount;
		printf("学生平均分为：%.2f\n", averageScore);
	}
	else
	{
		printf("没有学生信息，无法计算平均分！\n");
	}
	system("pause");
}

static void HighestScore(List* head)
{
	List* move = head->next;
	int highestScore = -1;
	student* topstudent = NULL;
	while (move != NULL)
	{
		if (move->student.score > highestScore)
		{
			highestScore = move->student.score;
			topstudent = &move->student;
		}
		move = move->next;
	}
	if (topstudent != NULL)
	{
		printf("最高分学生信息：学号：%d 姓名：%s 成绩: %d\n", topstudent->stuNum, topstudent->name, topstudent->score);
	}
	else
	{
		printf("没有学生信息，无法确定最高分！\n");
	}
	return;
}

static void LowestScore(List* head)
{
	List* move = head->next;
	int lowestScore = 101;
	student* lowstudent = NULL;
	while (move != NULL)
	{
		if (move->student.score < lowestScore)
		{
			lowestScore = move->student.score;
			lowstudent = &move->student;
		}
		move = move->next;
	}
	if (lowstudent != NULL)
	{
		printf("最低分学生信息：学号：%d 姓名：%s 成绩: %d\n", lowstudent->stuNum, lowstudent->name, lowstudent->score);
	}
	else
	{
		printf("没有学生信息，无法确定最低分！\n");
	}
	return;
}

static void PassScoreAnalysis(List* head)
{
	List* move = head->next;
	int passCount = 0;
	int totalCount = 0;
	while (move != NULL)
	{
		if (move->student.score >= 60)
		{
			passCount++;
		}
		totalCount++;
		move = move->next;
	}
	if (totalCount > 0)
	{
		double passRate = (double)passCount / totalCount * 100;
		printf("及格率为：%.2f%%\n", passRate);
	}
	else
	{
		printf("没有学生信息，无法计算及格率！\n");
	}
	return;
}

void ClassOrAll()
{
	printf("*********************************\n");
	printf("*    欢迎使用个性服务系统       *\n");
	printf("*********************************\n");
	printf("*\t请选择功能列表:\t\t*\n");
	printf("*********************************\n");
	printf("*\t1. 全体成绩\t\t*\n");
	printf("*\t2. 班级成绩\t\t*\n");
	printf("*\t3. 返回主菜单\t\t*\n");
	printf("*********************************\n");
}

void ClassOrAllService(List* head)
{
	//清屏
	system("cls");
	ClassOrAll();
	while (1)
	{
		char c = getch();
		switch (c)
		{
		case '1':// 全体成绩
			chartstudent(head);
			break;
		case '2':// 班级成绩
			classChartstudent(head);
			break;
		case '3':// 返回主菜单
			return;
		default:
			printf("无效的选择，请重新输入！\n");
			break;
		}
	}
}

void classChartstudent(List* head)
{
	system("cls");
	fopen("./student.info", "r");
	if (head->next == NULL)
	{
		printf("无学生信息，无法生成报表！\n");
		return;
	}
	List* move = head->next;
	List* specificClassHead = (List*)malloc(sizeof(List));
	if (specificClassHead == NULL) {
		printf("内存分配失败，无法生成报表！\n");
		return;
	}
	specificClassHead->next = NULL;  // 新链表头结点初始化
	int class;
	printf("请输入要生成报表的班级：\n");
	scanf("%d", &class);

	while (move != NULL)
	{
		if (class == move->student.class)
		{
			List* newList = (List*)malloc(sizeof(List));
			newList->student = move->student;
			newList->next = NULL;
			List* temp = specificClassHead;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newList;
		}
		move = move->next;
	}

	chartstudent(specificClassHead);  // 生成这个班级的报表
}