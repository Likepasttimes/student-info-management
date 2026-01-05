#ifndef MENU_H
#define MENU_H

#define MAX_USERS 100
#define	MAX_PASSWORD_LEN 50
#define ROLE_STUDENT 1
#define ROLE_TEACHER 2
#define ROLE_MANAGER 3
#define MAX_SUBJECTS 50
#define MAX_CLASSES 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20


// 函数声明
void publish_notice_menu(int user_role);
void view_notices_menu(int user_role);
void system_settings_menu(int user_role);
void display_welcome_message();
void user_management(int user_role);
void subject_management(int user_role);
void class_management(int user_role);
void grade_standard_view();


// 权限检查函数
int has_permission(int user_role, int required_permission);

#endif