#include <stdio.h>

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct
{
    // 定义复数
    enum coordinate_type t;
    double x, y;
};

struct segment
{
    // 结构体嵌套定义
    // 定义复平面下的线段
    struct complex_struct start;
    struct complex_struct end;
};

int main(void)
{
    // 嵌套地初始化
    struct segment s1 = {{ RECTANGULAR, 1.0, 2.0 }, { RECTANGULAR, 4.0, 6.0 }};// 嵌套地初始化
    // 平坦地初始化, gcc 会报警告: missing braces around initializer,
    // 原因是确少更准确的大括号来指定要初始化的成员
    struct segment s2 = { RECTANGULAR, 2.0, 4.0, RECTANGULAR, 3.0, 5.0 };
    printf("struct s1.start.t = %d\n", s1.start.t);
    printf("struct s2.start.t = %d\n", s2.start.t);
    printf("struct s1.start.x = %f\n", s1.start.x);
    printf("struct s2.start.x = %f\n", s2.start.x);
    printf("struct s1.start.y = %f\n", s1.start.y);
    printf("struct s2.start.y = %f\n", s2.start.y);
    printf("struct s1.end.t = %d\n", s1.end.t);
    printf("struct s2.end.t = %d\n", s2.end.t);
    printf("struct s1.end.x = %f\n", s1.end.x);
    printf("struct s2.end.x = %f\n", s2.end.x);
    printf("struct s1.end.y = %f\n", s1.end.y);
    printf("struct s2.end.y = %f\n", s2.end.y);
    return 0;
}
