#include <stdio.h>

int fib(int n)
{
        // while循环实现fibonacci
        // 章节名：循环语句；文件位置：while语句；文件类型:习题1答案
        int i, befor, after;
        i = after = befor = 1;
        int temp;
        if (n <= 1) {
                after = 1;
                return after;
        } else {
                while (i<n) {
                        temp = after + befor;
                        after = befor;
                        befor = temp;
                        i++;
                }
        }
        return befor;
}

int main(void)
{
        int n = 6;
        printf("fib(%d) is %d\n", n, fib(n));
        return 0;
}
