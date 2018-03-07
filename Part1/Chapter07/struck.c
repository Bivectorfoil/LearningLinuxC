#include <stdio.h>

/*
   int main(void)
   {
   struct complex_struct { double x, y;} z;
   double x = 3.0;
   z.x = x;
   z.y = +4.0;
   if (z.y < 0)
   printf("z=%f%fi\n", z.x, z.y);
   else
   printf("z=%f+%fi\n", z.x, z.y);
   return 0;
   }
   */

struct complex_struct {
        double x, y;
};

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
        z1.x = z1.x + z2.x;
        z1.y = z1.y + z2.y;
        return z1;
}

int main(void)
{
        // 结构体的概念及相关构造方法
        // 章节名：结构体；文件位置：复合类型和结构体；文件类型：练习
        struct complex_struct z = {3.0, 4.0};
        z = add_complex(z, z);
        printf("z=%f+%fi\n", z.x, z.y);
        return 0;
}
