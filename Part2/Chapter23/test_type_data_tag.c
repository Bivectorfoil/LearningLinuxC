#include <stdio.h>
#include <math.h>

double PI = 3.1415926;

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
        // 定义一个标识复数的结构体
        // 通过数据类型标志标记类型：直角坐标系或是极坐标系
        enum coordinate_type t;
        double a, b;
};

double rect_real_part(struct complex_struct z)
{
        return z.a;
}

double rect_img_part(struct complex_struct z)
{
        return z.b;
}

double rect_magnitude(struct complex_struct z)
{
        return sqrt(z.a * z.a + z.b * z.b);
}

double rect_angle(struct complex_struct z)
{
        double PI = acos(-1.0);

        if (z.a > 0)
                return atan(z.b / z.a);
        else
                return atan(z.b / z.a) + PI;
}

double pol_real_part(struct complex_struct z)
{
        return z.a * cos(z.b);
}

double pol_img_part(struct complex_struct z)
{
        return z.a * sin(z.b);
}

double pol_magnitude(struct complex_struct z)
{
        return z.a;
}

double pol_angle(struct complex_struct z)
{
        return z.b;
}

double (*real_part_tbl[])(struct complex_struct) = { rect_real_part, pol_real_part };
double (*img_part_tbl[])(struct complex_struct) = { rect_img_part, pol_img_part };
double (*magnitude_tbl[])(struct complex_struct) = { rect_magnitude, pol_magnitude };
double (*angle_tbl[])(struct complex_struct) = { rect_angle, pol_angle };

#define real_part(z) real_part_tbl[z.t](z)
#define img_part(z) img_part_tbl[z.t](z)
#define magnitude(z) magnitude_tbl[z.t](z)
#define angle(z) angle_tbl[z.t](z)

// 直角坐标系构造复数
struct complex_struct make_from_real_img(double x, double y)
{
        // 从实部和虚部构造复数z
        struct complex_struct z;
        z.t = RECTANGULAR;
        z.a = x;
        z.b = y;
        return z;
}
// 极坐标系构造复数
struct complex_struct make_from_mag_ang(double r, double A)
{
        // 从模和幅角构造复数z
        struct complex_struct z;
        z.t = POLAR;
        z.a = r;
        z.b = A;
        return z;
}

// 复数的+ - * /
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
        return make_from_real_img(real_part(z1) + real_part(z2),
                        img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
        return make_from_real_img(real_part(z1) - real_part(z2),
                        img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
        return make_from_mag_ang(magnitude(z1) * magnitude(z2),
                        angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
        return make_from_mag_ang(magnitude(z1) / magnitude(z2),
                        angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z)
{
        // 打印复数
        double real_part, img_part;
        double magnitude, angle;
        if (z.t == RECTANGULAR) {
                real_part = z.a;
                img_part = z.b;
                if (real_part == 0 && img_part == 0)
                        printf("0\n");
                else if (real_part == 0)
                        printf("%fi\n", img_part);
                else if (img_part == 0)
                        printf("%f\n", real_part);
                else {
                        if (img_part < 0)
                                printf("%f%fi\n", real_part, img_part);
                        else
                                printf("%f+%fi\n", real_part, img_part);
                }
        } else if (z.t == POLAR) {
                magnitude = z.a;
                angle = z.b;
                printf("%fe^%fi\n", magnitude, angle);
        }

}

int main(void)
{
        // 复数的表示(直角坐标系)
        struct complex_struct z1 = { RECTANGULAR, 3.0, 4.0 };
        struct complex_struct z2 = { RECTANGULAR, 6.0, -8.0 };
        struct complex_struct z3 = { RECTANGULAR, 0.0, -4.0 };
        struct complex_struct z4 = { RECTANGULAR, -3.0, 0.0 };
        struct complex_struct z5 = { RECTANGULAR, 0.0, 0.0 };
        // （极坐标系)
        struct complex_struct z6 = { POLAR, sqrt(2), PI / 4 };
        struct complex_struct z7 = { POLAR, 2, PI / 3 };
        printf("z1 = ");print_complex(z1);
        printf("z2 = ");print_complex(z2);
        printf("z3 = ");print_complex(z3);
        printf("z4 = ");print_complex(z4);
        printf("z5 = ");print_complex(z5);
        printf("z6 = ");print_complex(z6);
        printf("z7 = ");print_complex(z7);
        // 复数的+ - * /
        struct complex_struct add_result = add_complex(z1, z2);
        struct complex_struct sub_result = sub_complex(z1, z2);
        struct complex_struct mul_result = mul_complex(z1, z2);
        struct complex_struct div_result = div_complex(z1, z2);
        printf("%f+%fi + %f+%fi = %0.1f+%0.1fi\n", z1.a, z1.b, z2.a, z2.b, add_result.a, add_result.b);
        printf("%f+%fi - %f+%fi = %0.1f+%0.1fi\n", z1.a, z1.b, z2.a, z2.b, sub_result.a, sub_result.b);
        printf("%f+%fi * %f+%fi = %0.1f+%0.1fi\n", z1.a, z1.b, z2.a, z2.b, mul_result.a, mul_result.b);
        printf("%f+%fi / %f+%fi = %0.1f+%0.1fi\n", z1.a, z1.b, z2.a, z2.b, div_result.a, div_result.b);
        // 极坐标系下的* /
        struct complex_struct mul = mul_complex(z6, z7);
        struct complex_struct div = div_complex(z6, z7);
        print_complex(mul);
        print_complex(div);

        return 0;
}
