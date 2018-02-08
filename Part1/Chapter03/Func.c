#include <stdio.h>
#include <math.h>

/*
 * 函数定义：返回值类型 函数名（参数列表）函数体
 * 函数声明：返回值类型 函数名（参数列表）
 * 函数原型：返回值类型 函数名 （参数列表）

 * 区别：完整的函数原型即为一个函数声明，但在Old Style C
 * 中有些函数声明参数列表为空，不算函数原型；函数需要先声明，再调用，像变量那样
 * 如果调用函数时参数列表为空，且缺少函数原型，则为隐式声明参数类型为void。

 * 局部变量可以用类型相符的任意表达式初始化，而全局变量只能用常量表达式初始化
 * 注意区分编译时和运行时的概念
 * eg:
 * double pi = 3.14 + 0.0016;  work;
 * double pi = acos(-1.0); not allow;
 * 局部变量使用前需要先赋值

int main(void)
{
    double pi = 3.1416;
    printf("sin(pi/2)=%f\nln1=%f\n", sin(pi/2), log(1.0));
    return 0;
}

void newline(void)
{
    printf("\n");
}

void threelines(void)
{
    newline();
    newline();
    newline();
}

int main(void)
{
    printf("One lines:\n");
    newline();
    printf("Another three lines.\n");
    threelines();
    return 0;
}

void print_time(int hour, int minute)
{
    printf("%d:%d\n", hour, minute);
}

int main(void)
{
    int h = 23, m = 59;
    print_time(h, m);
    return 0;
}
*/


void increment(int x)
{
    x = x + 1;
}

int main(void)
{
    int i = 1, j = 2;
    increment(i); /* i now become 2? */
    printf("i is %d\n", i);
    increment(j); /* j now become 3? */
    return 0;
}
