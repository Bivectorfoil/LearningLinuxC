#include <stdio.h>

int foo(int x)
{
    // return digits and ten digits of a number
    int digits, ten_digits;
    digits = x % 10;
    ten_digits = x / 10;
    printf("digits is %d, ten digits is %d", digits, ten_digits);
    return 0;
}

void print_day(int day)
{
    switch (day) {
        case 1:
            printf("Monsday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Illegal day number!\n");
    }
}

int main(void)
{
    /* int i = 0;
    {
        int i = 1;
        int j = 2;
        printf("i=%d, j=%d\n", i, j);
    }
    printf("i=%d\n", i); cannot accept j here
    */
    int x = 32;
    foo(x);
    // print_day(6);
    return 0;
}
