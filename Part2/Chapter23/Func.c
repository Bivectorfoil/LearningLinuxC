#include <stdio.h>

void increment(int *x)
{
        // 传入参数的地址
        *x = *x + 1;
}

int main(void)
{
        int i = 1, j = 2;
        increment(&i); /* i now become 2? */
        printf("i is %d\n", i);
        increment(&j); /* j now become 3? */
        printf("j is %d\n", j);
        return 0;
}
