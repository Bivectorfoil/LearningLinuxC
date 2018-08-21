#include <math.h>
#include <stdio.h>

/*
 * 章节名：结构体；文件位置：数据类型标志；文件类型：习题1答案
 */
struct complex_struct {
        // 定义一个标识复数的结构体
        double x, y;
};

// 复数的各项定义（直角座标表示）
double real_part(struct complex_struct z)
{
        // 返回复数实部
        return z.x;
}

double img_part(struct complex_struct z)
{
        // 返回复数虚部
        return z.y;
}

double magnitude(struct complex_struct z)
{
        // 返回复数的模
        return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)
{
        // 返回复数的幅角
        return atan2(z.y, z.x);
}

// 直角座标系构造复数
struct complex_struct make_from_real_img(double x, double y)
{
        // 从实部和虚部构造复数z
        struct complex_struct z;
        z.x = x;
        z.y = y;
        return z;
}
// 极座标系构造复数
struct complex_struct make_from_mag_ang(double r, double A)
{
        // 从模和幅角构造复数z
        struct complex_struct z;
        z.x = r * cos(A);
        z.y = r * sin(A);
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
        double real_part, img_part;
        real_part = z.x;
        img_part = z.y;
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
}

int main(void)
{
        // 复数的表示
        struct complex_struct z1 = { 3.0, 4.0 };
        struct complex_struct z2 = { 6.0, -8.0 };
        struct complex_struct z3 = { 0.0, -4.0 };
        struct complex_struct z4 = { -3.0, 0.0 };
        struct complex_struct z5 = { 0.0, 0.0 };
        print_complex(z1);
        print_complex(z2);
        print_complex(z3);
        print_complex(z4);
        print_complex(z5);
        // 复数的+ - * /
        struct complex_struct add_result = add_complex(z1, z2);
        struct complex_struct sub_result = sub_complex(z1, z2);
        struct complex_struct mul_result = mul_complex(z1, z2);
        struct complex_struct div_result = div_complex(z1, z2);
        print_complex(add_result);
        print_complex(sub_result);
        print_complex(mul_result);
        print_complex(div_result);
        printf("%f+%fi + %f+%fi = %0.1f+%0.1fi\n", z1.x, z1.y, z2.x, z2.y, add_result.x, add_result.y);
        printf("%f+%fi - %f+%fi = %0.1f+%0.1fi\n", z1.x, z1.y, z2.x, z2.y, sub_result.x, sub_result.y);
        printf("%f+%fi * %f+%fi = %0.1f+%0.1fi\n", z1.x, z1.y, z2.x, z2.y, mul_result.x, mul_result.y);
        printf("%f+%fi / %f+%fi = %0.1f+%0.1fi\n", z1.x, z1.y, z2.x, z2.y, div_result.x, div_result.y);
        return 0;
}
