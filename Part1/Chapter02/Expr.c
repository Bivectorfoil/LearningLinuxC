#include <stdio.h>

/*
 * comment1
 * main: generate some simple output
 */
char firstletter = 'a';
int hour = 11, minute = 59; /* 全局变量的初始化(声明与赋值在一行) */
int main(void)
{
        printf(/* comment2 */"Hello, world.\n"); /* comment3 */
        printf("here are a tab.\t");
        printf("here are a line feed.\n");
        printf("now we are going to use constant.\n");
        printf("character: %c\ninteger: %d\nfloating point: %f\n", '}', 34, 3.14);
        printf("%c%c 是浮点数标识符，不是float类型，浮点数有单精度(float)和双精度(double)之分.\n", '%', 'f');
        printf("print %%: %%\n");
        printf("print float %f\n", 3.14);
        int total_minute; /* 局部变量声明 */
        total_minute = hour * 60 + minute;
        printf("%d:%d is %d minutes after 00:00\n", hour, minute, total_minute);
        printf("%d hours and %d precent of an hour\n", hour, minute * 100 / 60);
        printf("%d and %f hours\n", hour, minute / 60.0);
        int x, n;
        x = 17;
        n = 4;
        printf("x/n is %d\n", (x+n-1)/n); /* int型向上取整方法 */
        printf("'a' + 1 = %c\n", 'a' + 1); /* 字符类型也可以当作整数运算，内部转换为ASCII字符编码以后计算 */

        return 0;
}
