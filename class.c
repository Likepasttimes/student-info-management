#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"


Class classes[MAX_CLASSES];
int class_count = 0;

//初始化班级数据
void init_classes()
{
	strcpy_s(classes[0].class_id, MAX_ID_LEN, "NE202501");
	strcpy_s(classes[0].class_name, MAX_NAME_LEN, "网络工程1班");
	classes[0].grade = 2025;
	classes[0].student_num = 36;
	strcpy_s(classes[0].teacher_id, MAX_ID_LEN, "T001");

	strcpy_s(classes[1].class_id, MAX_ID_LEN, "NE202502");
	strcpy_s(classes[1].class_name, MAX_NAME_LEN, "网络工程2班");
	classes[1].grade = 2025;
	classes[1].student_num = 38;
	strcpy_s(classes[1].teacher_id, MAX_ID_LEN, "T002");

	class_count = 2;
}

//添加班级
void add_class()
{
	if (class_count >= MAX_CLASSES)
	{
		printf("已达班级上限！\n");
		return;
	}

	Class new_class;
	printf("请输入班级ID：");
	scanf_s("%s", new_class.class_id, (unsigned)_countof(new_class.class_id));
	printf("请输入班级名称：");
	scanf_s("%s", new_class.class_name, (unsigned)_countof(new_class.class_name));
	printf("请输入年级：");
	scanf_s("%d", &new_class.grade);
	printf("请输入班级人数：");
	scanf_s("%d", &new_class.student_num);
	printf("请输入班主任ID：");
	scanf_s("%s", new_class.teacher_id, (unsigned)_countof(new_class.teacher_id));

	classes[class_count++] = new_class;
	printf("班级添加成功！\n");

}

// 删除班级
void delete_class(const char* class_id)
{
	for (int i = 0; i < class_count; i++)
	{
		if (strcmp(classes[i].class_id, class_id) == 0)
		{
			for (int j = i; j < class_count - 1; j++)
			{
				classes[j] = classes[j + 1];
			}
			class_count--;
			printf("班级删除成功！\n");
			return;
		}
	}
	printf("未找到该班级！\n");
}

//查找班级
Class* find_class(const char* class_id)
{
	for (int i = 0; i < class_count; i++)
	{
		if (strcmp(classes[i].class_id, class_id) == 0)
			return &classes[i];
	}
	return NULL;
}

//列出所有班级
void list_classes()
{
	printf("\n========== 班级列表 ==========\n");
	printf("%-15s%-25s%-10s%-10s%-15s\n", "班级ID", "班级名称", "年级", "班级人数", "班主任ID");

	for (int i = 0; i < class_count; i++)
	{
		printf("%-15s%-25s%-10d%-10d%-15s\n",
			classes[i].class_id,
			classes[i].class_name,
			classes[i].grade,
			classes[i].student_num,
			classes[i].teacher_id);
	}
}