#ifndef CLASS_H
#define CLASS_H

#define MAX_CLASSES 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20

// 班级结构体
typedef struct {
    char class_id[MAX_ID_LEN];
    char class_name[MAX_NAME_LEN];
    int grade;
    int student_num;
    char teacher_id[MAX_ID_LEN];
} Class;

// 全局班级数组和计数
extern Class classes[MAX_CLASSES];
extern int class_count;

// 函数声明
void init_classes();
void add_class();
void delete_class(const char* class_id);
Class* find_class(const char* class_id);
void list_classes();

#endif