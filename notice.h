#ifndef NOTICE_H
#define NOTICE_H

#include <time.h>

#define MAX_NOTICES 100
#define MAX_ID_LEN 20

// 通知目标定义
#define TARGET_STUDENT 1
#define TARGET_TEACHER 2
#define TARGET_ALL 3
#define TARGET_CLASS 4

// 通知结构体
typedef struct {
    char notice_id[MAX_ID_LEN];
    char title[100];
    char content[500];
    char publisher_id[MAX_ID_LEN];
    time_t publish_time;
    int target_role;
    int target_class;  // 如果是班级通知，指定班级代码
    int is_urgent;
} Notice;

// 全局通知数组和计数
extern Notice notices[MAX_NOTICES];
extern int notice_count;

// 函数声明
void publish_notice();
void view_notices(int user_role);
#endif