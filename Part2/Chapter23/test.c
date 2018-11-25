#include <stdio.h>

int i;
int *pi = &i;
char c;
char *pc = &c;
int j = 10;
struct unit {
        char c;
        int num;
};

int main(void)
{
        int i = 1;
        int *pi = &i;
        int **ppi = &pi;
        printf("value of ppi: %d\n", **ppi);

        struct unit u = { 'a', 1 };
        struct unit *p = &u;
        printf("struct unit c: %c\n",p->c);
        printf("struct unit num: %d\n",p->num);

        int *ptr = pi;
        printf("value of i: %x\n", *pi);
        printf("value of pi, also address of i: %p\n", pi);
        printf("value of ptr, also address of i: %p\n", ptr);
        printf("value of c: %x\n", c);
        printf("address of c: %p\n", &c);
        printf("value of pc, also address of c: %p\n", pc);
        printf("size of point pi: %ld\n", sizeof(pi));
        printf("size of point pc: %ld\n", sizeof(pc));
        pi = &j;
        *pi = *pi + 10;
        printf("value of j: %d\n", j);

        int a[10];
        int *pa = &a[0];
        int *x = pa;
        printf("pa: %p\n", pa);
        printf("a[0]: %p\n", &a);
        printf("x - pa : %ld\n", x - pa);
        pa++;
        printf("pa - a: %ld\n", pa - a);
        printf("pa: %p\n", pa);

        int t[2][2] = { {1, 2}, {3, 4} };
        int (*pt)[2] = &t[0];
        printf("pt[0]: %d, t[0]: %d\n", *pt[1], *t[1]);
        int tmp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int (*tpt)[10] = &tmp;
        printf("tpt[0][0]: %d, tmp[0]: %d\n", tpt[0][0], tmp[0]);
        return 0;
}
