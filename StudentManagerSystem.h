#ifndef student_MANAGER_SYSTEM_H
#define student_MANAGER_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// 定义学生结构体和链表节点结构体
typedef struct _student
{
	int stuNum;    //学号
	char name[32];                //姓名
	char gender;                  //性别
	int class;               //班级
	char birth[20];                   //出生日期
	char phone[16];                   //联系方式
	char address[64];                 //地址
	int score;                //成绩
} student;

// 链表节点结构体
typedef struct _List
{
	student student;  // 节点中的学生信息
	struct _List* next;
} List;

void welcome();

void inputstudent(List* head);

void printstudent(List* head);

void savestudent(List* head);

void findstudent(List* head);

void countstudent(List* head);

void loadstudent(List* head);

void modifystudent(List* head);

void deletestudent(List* head);

void sortstudent(List* head);



#endif // student_MANAGER_SYSTEM_H

