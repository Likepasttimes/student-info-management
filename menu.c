#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"
#include "subject.h"
#include "class.h"
#include "grade_standard.h"
#include "notice.h"
#include "menu.h"

// 显示欢迎信息
void display_welcome_message() {
    printf("\n==========================================\n");
    printf("      学生信息和成绩管理系统\n");
    printf("==========================================\n");
}

// 权限检查函数
int has_permission(int user_role, int required_level) {
    if (required_level == 1) { // 仅管理员
        return user_role == ROLE_MANAGER;
    }
    else if (required_level == 2) { // 教师和管理员
        return user_role == ROLE_MANAGER || user_role == ROLE_TEACHER;
    }
    else { // 所有用户
        return 1;
    }
}

// 用户管理
void user_management(int user_role) {
    if (!has_permission(user_role, 1)) {
        printf("权限不足！只有管理员可以访问用户管理功能。\n");
        return;
    }

    printf("\n========== 用户管理 ==========\n");
    printf("1. 添加用户\n");
    printf("2. 查看所有用户\n");
    printf("3. 删除用户\n");
    printf("4. 查找用户\n");
    printf("0. 返回\n");

    int choice;
    char target_user_id[MAX_ID_LEN];
    char* role_names[] = { "学生","教师","管理员" };
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        add_user();
        break;
    case 2:
        list_users();
        break;
    case 3:
        printf("请输入要删除的用户ID：");
        scanf_s("%s", target_user_id, (unsigned)_countof(target_user_id));
        delete_user(target_user_id);
        break;
    case 4:
        printf("请输入要查找的用户ID：");
        scanf_s("%s", target_user_id, (unsigned)_countof(target_user_id));
        if (find_user(target_user_id) != NULL)
        {
            printf(" %-15s %-15s %-10s %-10d\n",
                find_user(target_user_id)->user_id,
                find_user(target_user_id)->user_name,
                role_names[find_user(target_user_id)->role - 1],
                find_user(target_user_id)->permissions);
        }
        else
            printf("不存在该用户！\n");
        break;
    }
}

// 学科管理
void subject_management(int user_role) {

    if (!has_permission(user_role, 2)) {
        printf("权限不足！只有教师和管理员可以访问学科管理功能。\n");
        return;
    }

    printf("\n========== 学科管理 ==========\n");
    printf("1. 添加学科\n");
    printf("2. 查看所有学科\n");
    printf("3. 删除学科\n");
    printf("4. 查找学科\n");
    printf("0. 返回\n");

    int choice;
    char target_subject_id[MAX_ID_LEN];
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        add_subject();
        break;
    case 2:
        list_subjects();
        break;
    case 3:
        printf("请输入要删除的学科ID：");
        scanf_s("%s", target_subject_id, (unsigned)_countof(target_subject_id));
        delete_subject(target_subject_id);
        break;
    case 4:
        printf("请输入要查找的学科ID：");
        scanf_s("%s", target_subject_id, (unsigned)_countof(target_subject_id));
        if (find_subject(target_subject_id) != NULL)
        {
            printf("%-15s %-20s %-10d %-10d\n",
                find_subject(target_subject_id)->subject_id,
                find_subject(target_subject_id)->subject_name,
                find_subject(target_subject_id)->credit,
                find_subject(target_subject_id)->hours);
        }
        else
            printf("不存在该学科！\n");
        break;
    }

}

// 班级管理
void class_management(int user_role) {
    if (!has_permission(user_role, 2)) {
        printf("权限不足！只有教师和管理员可以访问班级管理功能。\n");
        return;
    }

    printf("\n========== 班级管理 ==========\n");
    printf("1. 添加班级\n");
    printf("2. 查看所有班级\n");
    printf("3. 删除班级\n");
    printf("4. 查找班级\n");
    printf("0. 返回\n");

    int choice;
    char target_class_id[MAX_ID_LEN];
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        add_class();
        break;
    case 2:
        list_classes();
        break;
    case 3:
        printf("请输入要删除的班级ID：");
        scanf_s("%s", target_class_id, (unsigned)_countof(target_class_id));
        delete_class(target_class_id);
        break;
    case 4:
        printf("请输入要查找的班级ID：");
        scanf_s("%s", target_class_id, (unsigned)_countof(target_class_id));
        if (find_class(target_class_id) != NULL)
        {
            printf("%-15s%-25s%-10d%-10d%-15s\n",
                find_class(target_class_id)->class_id,
                find_class(target_class_id)->class_name,
                find_class(target_class_id)->grade,
                find_class(target_class_id)->student_num,
                find_class(target_class_id)->teacher_id);
        }
        else
            printf("不存在该班级！\n");
    }
}

// 成绩标准查看
void grade_standard_view() {
    printf("\n========== 成绩评价标准 ==========\n");
    show_grade_standards();

    printf("\n输入分数查看对应等级和绩点(0-100, 输入-1退出): ");
    int score;
    scanf_s("%d", &score);

    if (score >= 0 && score <= 100) {
        printf("分数 %d 的等级是: %s\n", score, get_GradeLevel(score));
        printf("分数 %d 的绩点是: %.f\n", score, get_gpa(score));
    }
}

// 系统设置菜单
void system_settings_menu(int user_role) {
    if (!has_permission(user_role, 1)) {
        printf("权限不足！只有管理员可以访问系统设置。\n");
        return;
    }

    int choice;
    printf("\n========== 系统设置 ==========\n");
    printf("1. 用户管理\n");
    printf("2. 学科设置\n");
    printf("3. 班级设置\n");
    printf("4. 成绩标准查看\n");
    printf("0. 返回\n");
    printf("请选择: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        user_management(user_role);
        break;
    case 2:
        subject_management(user_role);
        break;
    case 3:
        class_management(user_role);
        break;
    case 4:
        grade_standard_view();
        break;
    }
}

// 发布通知菜单
void publish_notice_menu(int user_role) {
    if (!has_permission(user_role, 2)) {
        printf("权限不足！只有教师和管理员可以发布通知。\n");
        return;
    }

    publish_notice();
}

// 查看通知菜单
void view_notices_menu(int user_role) {
    view_notices(user_role);
}