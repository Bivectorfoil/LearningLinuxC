#include <math.h>
#include <stdio.h>

double distance(double x1, double y1, double x2, double y2)
{
        double dx = x2 - x1;
        double dy = y2 - y1;
        // printf("dx is %f\ndy is %f\n", dx, dy);
        double disquared = dx * dx + dy * dy;
        // printf("disquared is %f\n", disquared);
        double result = sqrt(disquared);
        return result;
}

double area(double radius)
{
        return 3.1415926 * radius * radius;
}

double area_point(double x1, double y1, double x2, double y2)
{
        return area(distance(x1, y1, x2, y2));
}

int main(void)
{
        // 增量式开发一个给定两点坐标，求圆面积的程序
        // printf("distance is %f\n", distance(1.0, 2.0, 4.0, 6.0));
        // printf("radius is %f\n", area(distance(1.0, 2.0, 4.0, 6.0)));
        printf("area is %f\n", area_point(1.0, 2.0, 4.0, 6.0));
        return 0;
}
