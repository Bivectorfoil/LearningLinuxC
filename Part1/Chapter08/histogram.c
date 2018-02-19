#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int a[N];

void gen_random(int low_bound, int upper_bound)
{
    // 生成low_bound~upper_bound范围内的随机数
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++)
        a[i] = rand() % (upper_bound - low_bound + 1) + low_bound;
}
int main(void)
{
    // 生成记录随机个数的数组
    int n, histogram[11] = {0};
    gen_random(0, 9);
    for (n = 0; n < N; n++)
        histogram[a[n]]++;

    // 打印直方图
    int i, j;
    for (i = 0; i < 10; i++)
        printf("%d\t", i);
    printf("\n\n");

    /*
    // 方法一，有待修改
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
            if (i < histogram[j]) {
                printf("*\t");
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
    */
    // 方法二，适用于不清楚循环次数的情形
    int sum;
    do {
        sum = 0;
        for(i = 0; i <= 9; i++)
            sum += histogram[i];
        for(j = 0; j <= 9; ++j) {
            if( histogram[j] != 0) {
                printf("*\t");
                --histogram[j];
            }else
                printf(" \t");
        }
        printf("\n");
    } while(sum != 0);
    return 0;
}

