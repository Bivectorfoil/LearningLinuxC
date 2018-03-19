#include <math.h>
#include <stdio.h>

double mysqrt(double y)
{
        /* 折半查找求正平方根 */
        double start = 0, end = y;
        double x = 0;
        int i = 0;
        while (fabs(x*x - y) > 0.001) {
                x = (start + end) / 2.0;
                if (x*x < y)
                        start = x;
                else if (x*x > y)
                        end = x;
                i += 1;
         }
        return x;
}

int main(void)
{
        printf("%.3f\n", mysqrt(61));
        return 0;
}
