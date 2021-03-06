#include <stdio.h>

int GCD(int a, int b)
{
        // while循环实现辗转相除法
        // 章节名：循环语句；文件位置：while语句；文件类型:习题1答案
        int remainder;
        remainder = a % b;
        while (remainder != 0) {
                a = b;
                b = remainder;
                remainder = a % b;
        }
        printf("The greatest common divisor is %d\n", b);
        return 0;
}

int main(void)
{
        int a = 102;
        int b = 170;
        GCD(a, b);
        return 0;
}
