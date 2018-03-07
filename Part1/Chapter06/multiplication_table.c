#include <stdio.h>

int main(void)
{
        // 打印九九乘法表
        // 章节名：循环语句；文件位置：嵌套循环；文件类型:习题1答案
        int i, j;
        for (i=1; i<=9; i++) {
                for (j=1; j<=i; j++)
                        printf("%d\t", i*j);
                printf("\n");
        }
        return 0;
}
