#include <stdio.h>

void diamond(int n, char c)
{
        // 打印菱形
        // 章节名：循环语句；文件位置：嵌套循环；文件类型:习题2答案
        int i, j;
        if (n <= 0 || !(n % 2))
                return;
        for (i=1; i<= (n+1)/2; i++) {
                for (j=1; j<=n/2-i+1; j++)
                        printf("\t");
                for (j=1; j<=2*i-1; j++)
                        printf("%c\t", c);
                printf("\n");
        }
        for (i=1; i <= n/2; i++) {
                for (j=1; j<=i; j++)
                        printf("\t");
                for (j=1; j<=n-2*i; j++)
                        printf("%c\t", c);
                printf("\n");
        }
}

int main(void)
{
        diamond(11, '+');
        return 0;
}
