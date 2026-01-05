#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "notice.h"


Notice notices[MAX_NOTICES];
int notice_count = 0;

// 发布通知菜单
void publish_notice() {
    if (notice_count >= MAX_NOTICES) {
        printf("通知数量已达上限！\n");
        return;
    }

    Notice new_notice;
    int target_type;

    printf("请输入通知标题: ");
    (void)getchar();  // 清除缓冲区
    fgets(new_notice.title, 100, stdin);
    new_notice.title[strcspn(new_notice.title, "\n")] = 0; //表示结束

    printf("请输入通知内容: ");
    fgets(new_notice.content, 500, stdin);
    new_notice.content[strcspn(new_notice.content, "\n")] = 0;

    printf("请输入发布者ID: ");
    scanf_s("%s", new_notice.publisher_id, (unsigned)_countof(new_notice.publisher_id));

    printf("请选择通知类型(1-学生 2-教师 3-全校 4-特定班级): ");
    scanf_s("%d", &target_type);

    if (target_type == TARGET_CLASS) {
        printf("请输入班级代码: ");
        scanf_s("%d", &new_notice.target_class);
        new_notice.target_role = TARGET_CLASS;
    }
    else {
        new_notice.target_role = target_type;
        new_notice.target_class = 0;
    }


    printf("是否为紧急通知(1-是 0-否): ");
    scanf_s("%d", &new_notice.is_urgent);

    time(&new_notice.publish_time);
    sprintf_s(new_notice.notice_id, sizeof(new_notice.notice_id), "N%03d", notice_count + 1);

    notices[notice_count++] = new_notice;
    printf("通知发布成功！通知ID: %s\n", new_notice.notice_id);
}

// 查看通知（根据用户角色）
void view_notices(int user_role) {
    printf("\n========== 通知公告 ==========\n");
    int found = 0;

    for (int i = notice_count - 1; i >= 0; i--) {
        // 显示所有通知或针对特定角色的通知
        if (notices[i].target_role == TARGET_ALL ||
            notices[i].target_role == user_role) {

            printf("\n通知ID: %s\n", notices[i].notice_id);
            printf("标题: %s\n", notices[i].title);
            char time_str[26];
            ctime_s(time_str, sizeof(time_str), &notices[i].publish_time);
            printf("发布时间: %s", time_str);
            printf("发布者: %s\n", notices[i].publisher_id);
            if (notices[i].is_urgent) {
                printf("【紧急】\n");
            }
            printf("内容: %s\n", notices[i].content);
            printf("------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("暂无通知！\n");
    }
}