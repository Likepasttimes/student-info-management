#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

User users[MAX_USERS];
int user_count = 0;

//初始化用户数据
void init_users()
{
	strcpy_s(users[0].user_id, sizeof(users[0].user_id), "manager001");
	strcpy_s(users[0].user_name, sizeof(users[0].user_name), "系统管理员");
	strcpy_s(users[0].password, sizeof(users[0].password), "123456");
	users[0].role = ROLE_MANAGER;
	users[0].permissions = 7;
	user_count = 1;
}

//添加用户
void add_user()
{
	if (user_count >= MAX_USERS)
	{
		printf("用户数量已达上限！\n");
		return;
	}

	User new_user;
	printf("请输入用户ID：");
	scanf_s("%s", new_user.user_id, (unsigned)_countof(new_user.user_id));
	printf("请输入用户名：");
	scanf_s("%s", new_user.user_name, (unsigned)_countof(new_user.user_name));
	printf("请输入密码：");
	scanf_s("%s", new_user.password, (unsigned)_countof(new_user.password));
	printf("请选择角色（1-学生 2-教师 3-管理员）：");
	scanf_s("%d", &new_user.role);

	//根据角色设置权限
	if (new_user.role == ROLE_MANAGER)
		new_user.permissions = 7;
	else if (new_user.role == ROLE_TEACHER)
		new_user.permissions = 3;
	else
		new_user.permissions = 1;


	users[user_count++] = new_user;
	printf("用户添加成功！\n");

}

//删除用户
void delete_user(const char* user_id)
{
	for (int i = 0; i < user_count; i++)
	{
		if (strcmp(users[i].user_id, user_id) == 0)
		{
			for (int j = i; j < user_count - 1; j++)
			{
				users[j] = users[j + 1];
			}
			user_count--;
			printf("用户删除成功！\n");
			return;
		}
	}
	printf("未找到该用户！\n");

}

//查找用户
User* find_user(const char* user_id)
{
	for (int i = 0; i < user_count; i++)
	{
		if (strcmp(users[i].user_id, user_id) == 0)
			return &users[i];
	}
	return NULL;
}

//列出所有用户
void list_users()
{
	printf("\n========== 用户列表 ==========\n");
	printf("%-15s %-15s %-10s %-10s\n", "用户ID", "用户名", "角色", "权限");
	char* role_names[] = { "学生","教师","管理员" };

	for (int i = 0; i < user_count; i++)
	{
		printf(" %-15s %-15s %-10s %-10d\n",
			users[i].user_id,
			users[i].user_name,
			role_names[users[i].role - 1],
			users[i].permissions);
	}

}

//用户认证
int authenticate_user(char* user_id, const char* password)
{
	for (int i = 0; i < user_count; i++)
	{
		if (strcmp(users[i].user_id, user_id) == 0 && strcmp(users[i].password, password) == 0)
			return users[i].role;
	}
	return -1;   //认证失败
}