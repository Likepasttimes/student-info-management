#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subject.h"


Subject subjects[MAX_SUBJECTS];
int subject_count = 0;

// 初始化学科数据
void init_subjects()
{
    strcpy_s(subjects[0].subject_id, sizeof(subjects[0].subject_id), "MATH001");
    strcpy_s(subjects[0].subject_name, sizeof(subjects[0].subject_name), "高等数学");
    subjects[0].credit = 5;
    subjects[0].hours = 80;

    strcpy_s(subjects[1].subject_id, sizeof(subjects[1].subject_id), "ENG001");
    strcpy_s(subjects[1].subject_name, sizeof(subjects[1].subject_name), "大学英语");
    subjects[1].credit = 4;
    subjects[1].hours = 64;

    subject_count = 2;
}

// 添加学科
void add_subject()
{
    if (subject_count >= MAX_SUBJECTS)
    {
        printf("学科数量已达上限！\n");
        return;
    }

    Subject new_subject;
    printf("请输入学科ID: ");
    scanf_s("%s", new_subject.subject_id, (unsigned)_countof(new_subject.subject_id));
    printf("请输入学科名称: ");
    scanf_s("%s", new_subject.subject_name, (unsigned)_countof(new_subject.subject_name));
    printf("请输入学分: ");
    scanf_s("%d", &new_subject.credit);
    printf("请输入学时: ");
    scanf_s("%d", &new_subject.hours);

    subjects[subject_count++] = new_subject;
    printf("学科添加成功！\n");
}

// 删除学科
void delete_subject(const char* subject_id)
{
    for (int i = 0; i < subject_count; i++)
    {
        if (strcmp(subjects[i].subject_id, subject_id) == 0)
        {
            for (int j = i; j < subject_count - 1; j++)
            {
                subjects[j] = subjects[j + 1];
            }
            subject_count--;
            printf("学科删除成功！\n");
            return;
        }
    }
    printf("未找到该学科！\n");
}

//查找学科
Subject* find_subject(const char* subject_id)
{
    for (int i = 0; i < subject_count; i++)
    {
        if (strcmp(subjects[i].subject_id, subject_id) == 0)
            return &subjects[i];
    }
    return NULL;
}

// 列出所有学科
void list_subjects()
{
    printf("\n========== 学科列表 ==========\n");
    printf("%-15s %-20s %-10s %-10s\n",
        "学科ID", "学科名称", "学分", "学时");

    for (int i = 0; i < subject_count; i++)
    {
        printf("%-15s %-20s %-10d %-10d\n",
            subjects[i].subject_id,
            subjects[i].subject_name,
            subjects[i].credit,
            subjects[i].hours);
    }
}