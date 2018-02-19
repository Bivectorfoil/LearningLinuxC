#include <stdio.h>
#include <stdlib.h>
#define N 100000

int a[N];

void gen_random(int low_bound, int upper_bound)
{
    // 生成low_bound~upper_bound范围内的随机数
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % (upper_bound - low_bound + 1) + low_bound;
}


int howmany(int value)
{
    // 统计某一随机数出现次数
    int count = 0, i;
    for (i = 0; i < N; i++)
        if (a[i] == value)
            ++count;
    return count;
}

int main(void)
{
    int i;
    int low_bound, upper_bound;
    low_bound = 0;
    upper_bound = 9;
    gen_random(low_bound, upper_bound);
    printf("value\thow many\n");
    for (i = low_bound; i < upper_bound + 1; i++)
        printf("%d\t%d\n", i, howmany(i));

    return 0;
}
