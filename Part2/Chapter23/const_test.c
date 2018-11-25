#include <stdio.h>

const char *p = "abcd";
const char str1[5] = "abcd";
char str2[5] = "abcd";
char *pt;

int main(void)
{
        *pt = 'A';
        printf("%s\n", p);
        printf("%s\n", str1);
        printf("%s\n", str2);
        printf("abcd");
        printf("%s\n", pt);
        return 0;
}

