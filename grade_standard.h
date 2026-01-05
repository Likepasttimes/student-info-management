#ifndef GRADE_STANDARD_H
#define GRADE_STANDARD_H

// 成绩标准结构体
typedef struct {
    char level_name[20];
    int min_score;
    int max_score;
    double gpa;
} GradeStandard;

// 全局成绩标准数组和计数
extern GradeStandard standards[];
extern int standard_count;

// 函数声明
void show_grade_standards();
char* get_GradeLevel(int score);
double get_gpa(int score);

#endif