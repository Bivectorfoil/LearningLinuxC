#include <math.h>
#include <stdio.h>

int is_leap_year(int year)
{
    // 闰年判断
    if (year % 4 == 0 && year % 100 != 0) {
        return 0;
    } else if (year % 400 == 0) {
        return 0;
    } else {
    printf("%d is not leap_year\n", year);
    }
    return 0;
}

int double_myround(double x)
{
    if (x > 0) {
        printf("floor(%f) == %f\n", x, floor(x));
    } else if (x < 0) {
        printf("ceil(%f) == %f\n", x, ceil(x));
    } else {
        printf("%f is %f\n", x, x);
    }
    return 0;
}

int main(void)
{
    // is_leap_year(2018);
    double_myround(4.49);
    double_myround(-3.51);
    return 0;
}
