#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
int nailong;
int fruit;
int score = 0;
int life = 3;

void show()
{
    system("clear");
    for (int i = 0; i < WIDTH; i++)
    {
        if (i == fruit)
            printf("🍑");
        else
            printf("·");
    }
    printf("\n");
    for (int i = 0; i < WIDTH; i++)
    {
        if (i == nailong)
            printf("🐉");
        else
            printf("·");
    }
    printf("\n分数：%d | 生命：%d\n", score, life);
    printf("输入 a 左，d 右，q退出：");
}

int main()
{
    char op;
    srand((unsigned int)time(NULL));
    nailong = WIDTH / 2;
    fruit = rand() % WIDTH;

    while (life > 0)
    {
        show();
        scanf(" %c", &op);
        if (op == 'a' && nailong > 0) nailong--;
        if (op == 'd' && nailong < WIDTH - 1) nailong++;
        if (op == 'q') break;

        if (fruit == nailong)
        {
            printf("✅奶龙吃到桃子！+10分\n");
            score += 10;
        }
        else
        {
            printf("❌没吃到！-1生命\n");
            life--;
        }
        fruit = rand() % WIDTH;
    }
    printf("\n游戏结束！奶龙最终得分：%d\n", score);
    return 0;
}
