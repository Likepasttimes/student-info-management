#include <stdio.h>
#include "grade_standard.h"

//成绩标准定义
GradeStandard standards[] = {
	{"优秀",90,100,4.0},
	{"良好",80,89,3.0},
	{"中等",70,79,2.0},
	{"及格",60,69,1.0},
	{"不及格",0,59,0.0}
};

int standard_count = 5;

//显示成绩标准
void show_grade_standards()
{
	printf("\n========== 成绩评价标准 ==========\n");
	printf("%-10s %-10s %-10s %-10s\n", "等级", "最低分", "最高分", "绩点");

	for (int i = 0; i < standard_count; i++)
	{
		printf("%-10s %-10d %10d %10.1f\n",
			standards[i].level_name,
			standards[i].min_score,
			standards[0].max_score,
			standards[0].gpa);
	}
}

//根据分数获取等级
char* get_GradeLevel(int score)
{
	for (int i = 0; i < standard_count; i++)
	{
		if (score >= standards[i].min_score && score <= standards[i].max_score)
			return standards[i].level_name;
	}
	return "无效分数";
}

//根据分数获取绩点
double get_gpa(int score)
{
	for (int i = 0; i < standard_count; i++)
	{
		if (score >= standards[i].min_score && score <= standards[i].max_score)
			return standards[i].gpa;
	}
	return -1.0;
}