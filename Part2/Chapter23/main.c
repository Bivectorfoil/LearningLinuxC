#include <stdio.h>

int *swap(int *px, int *py)
{
        int temp;
        temp = *px;
        printf("addr of temp %p\n", &temp);
        *px = *py;
        printf("value of px %p\n", px);
        *py = temp;
        printf("value of py %p\n", py);
        return px;
}

int main(void)
{
        int i = 10, j = 20;
        printf("address of i: %p\n", &i);
        printf("address of j: %p\n", &j);
        printf("value of swap: %p\n", swap);
        int *p = swap(&i, &j);
        printf("now i=%d, j=%d, *p=%d\n", i, j, *p);
        return 0;
}
