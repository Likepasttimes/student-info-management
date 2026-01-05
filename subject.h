#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_SUBJECTS 50
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20

//学科结构体
typedef struct
{
	char subject_id[MAX_ID_LEN];
	char subject_name[MAX_NAME_LEN];
	int credit;
	int hours;
}Subject;

//全局学科数组和计数
extern Subject subjectss[MAX_SUBJECTS];
extern int subject_count;

//函数声明
void init_subjects();
void add_subject();
void delete_subject(const char* subject_id);
Subject* find_subject(const char* subject_id);
void list_subjects();

#endif