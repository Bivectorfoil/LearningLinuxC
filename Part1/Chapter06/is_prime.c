#include <stdio.h>

int is_prime(int n)
{
        // 使用break和continue控制流程
        // 章节名：循环语句；文件位置：break,continue语句；文件类型:习题1答案
        int i;
        for (i = 2; i < n; i++)
                if (n % i == 0)
                        break;
        if (i == n)
                return 1;
        else
                return 0;
}

int main(void)
{
        int i;
        for (i = 1; i <= 100; i++) {
                if (!is_prime(i))
                        continue;
                printf("%d\n", i);
        }
        return 0;
}

/*
   int is_prime(int n)
   {
// 不使用break和continue控制流程
int i;
for (i = 2; i < n; i++)
if (n % i == 0)
return 0;
return 1;
}

int main(void)
{
int i;
for (i = 1; i <= 100; i++) {
if (is_prime(i))
printf("%d\n", i);
}
return 0;
}
*/
