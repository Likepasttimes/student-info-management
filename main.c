#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


// 学生结构
typedef struct Student
{
	unsigned long long stuNum;    //学号
	char name[32];                //姓名
	char gender;                  //性别
	char className[16];               //班级
	char birth[20];                   //出生日期
	char phone[16];                   //联系方式
	char address[64];                 //地址
	float score;                //总分

}Student;

// 节点 Node
typedef struct Node
{
	Student stu;              //学生
	struct Node* next;        //指向下一个节点的指针
}Node;

//链表
typedef struct List
{
	Node* front;                //指向第一个节点
	int size;                   //当前节点的数量
}List;

typedef enum MenuOptions
{
	Quit,                 //退出系统
	Entry,                //录入信息
	Print,                //打印信息
	Save,                 //保存信息
	Read,                 //读取信息
	Statistics,           //统计人数
	Find,                 //查找信息
	Alter,                //修改信息
	Remove,               //删除信息
}MenuOptions;

// 打印菜单，并提示用户选择功能
int menu()
{
	printf("**********************************************\n");
	printf("*         欢迎使用学生成绩管理系统V1.0       *\n");
	printf("**********************************************\n");
	printf("*                请选择功能                  *\n");
	printf("**********************************************\n");
	printf("*              1.录入学生信息                *\n");
	printf("*              2.打印学生信息                *\n");
	printf("*              3.保存学生信息                *\n");
	printf("*              4.读取学生信息                *\n");
	printf("*              5.统计学生人数                *\n");
	printf("*              6.查找学生信息                *\n");
	printf("*              7.修改学生信息                *\n");
	printf("*              8.删除学生信息                *\n");
	printf("*              0.退出系统                    *\n");
	printf("**********************************************\n");
	printf("select>");
	int select = -1;
	scanf("%d", &select);
	return select;
}

// 学生录入
void entryStudent(List* list)
{
	//创建节点
	Node* node = malloc(sizeof(Node));
	if (!node)
	{
		printf("malloc failed\n");
		return;
	}
	node->next = NULL;

	//输入学生信息
	printf("输入学生学号>");
	scanf("%llu", &node->stu.stuNum);

	printf("输入学生姓名>");
	scanf("%s", node->stu.name);

	printf("输入学生性别>");
	scanf("%s", &node->stu.gender);

	printf("输入学生班级>");
	scanf("%s", &node->stu.className);

	printf("输入学生出生日期>");
	scanf("%s", &node->stu.birth);

	printf("输入学生联系方式>");
	scanf("%s", &node->stu.phone);

	printf("输入学生地址>");
	scanf("%s", &node->stu.address);

	printf("输入学生总成绩>");
	scanf("%f", &node->stu.score);

	//插入到链表中
	node->next = list->front;
	list->front = node;
	list->size++;
}


//查找学生
Node* findStudent(List* list)
{
	char buffer[32];
	printf("请输入要查找的学生学号或姓名>");
	scanf("%s", buffer);
	
	//尝试把buffer转成整型
	unsigned long long number=-1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 || 
			curNode->stu.stuNum==number)
		{
			return  curNode;
		}
		curNode = curNode->next;

	}

	return NULL;
}

int main()
{
	//创建链表
	List list = {0};
	//内存设置
	memset(&list, 0, sizeof(List));

	while (1)
	{
		switch (menu())
		{
		case Quit:
			printf("Quit\n");
			break;
		case Entry:
			entryStudent(&list);
			break;
		case Print:
			break;
		case Save:
			break;
		case Read:
			break;
		case Statistics:
			break;
		case Find:
		{
			Node* node = findStudent(&list);
			if (!node)
			{
				printf("没有找到查询的学生\n");
			}
			else
			{
				printf("%llu\n%s\n%c\n%s\n,node->stu.stuNum,node->stu.name,node->stu.gender,node->stu.className");
				printf("%s\n%s\n%s\n,node->stu.birth,node->stu.phone,node->stu.address");
				printf("%.1f\n,node->stu.score");

			}
			break;
		}
		case Alter:
			break;
		case Remove:
			break;
		}

		
		//让程序暂停一下
		system("pause");
		//清屏
		system("cls");
	}


	return 0;
}
