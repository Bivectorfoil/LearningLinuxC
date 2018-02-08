#include <stdio.h>

int factorial(int n)
{
    // 输出阶乘
    // 在循环控制语句中，i++和++i并无太大区别
    int result = 1;
    int i;
    for (i = 1; i <= n; ++i)
        result = result * i;
    return result;
}

int odd_number(void)
{
    // 输出奇数
    int i;
    for (i = 0; i <= 11; i++) {
        i++;
        printf("i == %d\n", i);
    }
    return 0;
}

void even_number(void)
{
    // 输出偶数
    int i;
    for (i = 1; i <= 11; i++) {
        i++;
        printf("i == %d\n", i);
    }
}

int main(void)
{
    printf("3! == %d\n", factorial(3));
    odd_number();
    even_number();
    return 0;
}
