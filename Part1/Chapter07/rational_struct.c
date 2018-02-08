#include <stdio.h>

struct rational {
    // 定义一个有理数的结构体
    int x, y;
};

int GCD(int a, int b)
{
    // while循环实现辗转相除法
    if (a == 0)
        return 0;
    int remainder;
    remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}

int numerator_part(struct rational z)
{
    // 返回分子
    return z.x;
}

int denominator_part(struct rational z)
{
    // 返回分母
    return z.y;
}

struct rational make_rational(int x, int y)
{
    // 构造有理数z
    if (y == 0)
        printf("Invaild Input!\n");
    struct rational z;
    z.x = x;
    z.y = y;
    return z;
}

struct rational simplify_rational(int x, int y)
{
    // 返回化简后的有理数结构体
    int numerator, denominator;
    if (x == 0) {
        numerator = 0;
        denominator = y;
    } else {
        numerator = x / GCD(x, y);
        denominator = y / GCD(x, y);
    }
    struct rational z = { numerator, denominator};
    return z;
}

// 有理数的+ - * /
struct rational add_rational(struct rational z1, struct rational z2)
{
    int numerator = (numerator_part(z1) * denominator_part(z2) + \
            denominator_part(z1) * numerator_part(z2));
    int denominator = (denominator_part(z1) * denominator_part(z2));
    return simplify_rational(numerator, denominator);
}

struct rational sub_rational(struct rational z1, struct rational z2)
{
    int numerator = (numerator_part(z1) * denominator_part(z2) - \
            denominator_part(z1) * numerator_part(z2));
    int denominator = (denominator_part(z1) * denominator_part(z2));
    return simplify_rational(numerator, denominator);
}

struct rational mul_rational(struct rational z1, struct rational z2)
{
    return simplify_rational(numerator_part(z1) * numerator_part(z2),
            denominator_part(z1) * denominator_part(z2));
}

struct rational div_rational(struct rational z1, struct rational z2)
{
    return simplify_rational(numerator_part(z1) * denominator_part(z2),
            denominator_part(z1) * numerator_part(z2));
}

void print_rational(struct rational z)
{
    // 打印有理数
    printf("%d/%d\n", numerator_part(z), denominator_part(z));
}

int main(void)
{
    struct rational a = make_rational(1, 8);
    struct rational b = make_rational(-1, 8);
    print_rational(add_rational(a, b));
    print_rational(sub_rational(a, b));
    print_rational(mul_rational(a, b));
    print_rational(div_rational(a, b));

    return 0;
}
