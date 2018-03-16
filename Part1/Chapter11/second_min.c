#include <stdio.h>

#define LEN 8
int a[LEN] = { 9, 8, 7, 6, 5, 4, 3, 2 };

int second_min()
{
        /* Find the second smallest number */
        int i, se_min, min;

        i = 2;
        min = a[0];
        se_min = a[1];

        if (min > se_min) {
                min = a[1];
                se_min = a[0];
        }
        while (i < LEN) {
                if (a[i] < min) {
                        se_min = min;
                        min = a[i];
                }
                i++;
        }
        return se_min;
}

int main(void) {

        int se_min = second_min();
        printf("second smallest number is: %d\n", se_min);
        return 0;
}
