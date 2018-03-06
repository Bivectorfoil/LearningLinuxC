#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) /* 剪刀石头布游戏 */
{
        char gesture[3][10] = { "scissor", "stone", "cloth" };
        int man, computer, result, ret;

        srand(time(NULL));
        while (1) {
                computer = rand() % 3;
                printf("\nInput your gesture (0-scissor 1-stone 2-cloth):\n");
                ret = scanf("%d", &man);
                if (ret != 1 || man < 0 || man > 2) {
                        printf("Invaild input!\n");
                        return 1;
                }
                printf("You: %s\tComputer: %s\n",
                                gesture[man], gesture[computer]);
                result = (man - computer + 4) % 3 -1;
                if (result > 0)
                        printf("You win!\n");
                else if (result == 0)
                        printf("Draw!\n");
                else
                        printf("You lose!\n");
        }
        return 0;
}

/*
 * 游戏原理：以0, 1, 2分别代表scissor, stone, cloth，形成一个环，
 * 通过取模和添加常数使得最终结果取值局限与-1，0，1三个数之中。
 */
