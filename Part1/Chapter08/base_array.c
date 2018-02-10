#include <stdio.h>

int count1[5] = {0, 1, 2, 3, 4};
int count2[5];

int main(void)
{
    // 将一个数组拷贝到另一个
    int i;
    for (i = 0; i < 5; i++)
        count2[i] = count1[i];
    for (i = 0; i < 5; i++)
        printf("count1[%d]=[%d]; count2[%d]=[%d]\n", i, count1[i], i, count2[i]);
    return 0;
}
