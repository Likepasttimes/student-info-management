#ifndef USER_H
#define USER_H



#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20
#define	MAX_PASSWORD_LEN 50

#define ROLE_STUDENT 1
#define ROLE_TEACHER 2
#define ROLE_MANAGER 3


typedef struct
{
	char user_id[MAX_ID_LEN];
	char user_name[MAX_NAME_LEN];
	char password[MAX_PASSWORD_LEN];
	int role;
	int permissions;
}User;

//全局变量声明
extern User users[MAX_USERS];
extern int user_count;

//函数声明
void init_users();
void add_user();
void delete_user(const char* user_id);
User* find_user(const char* user_id);
void list_users();
int authenticate_user(char* user_id, const char* password);
//void save_users_to_file();
//void load_users_from_file;

#endif