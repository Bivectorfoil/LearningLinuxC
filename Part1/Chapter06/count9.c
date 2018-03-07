#include <stdio.h>

int main(void)
{
        // 计算1~100数字9出现次数
        // 章节名：循环语句；文件位置：while语句；文件类型:习题2答案
        int i, count=2;
        for (i=10; i<=100; i++) {
                if (i/9==0 || i%10==9) {
                        ++count;
                }
        }
        printf("1 ~ 100中，共有%d个9\n", count);
        return 0;
}
