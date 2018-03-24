#include <stdio.h>
#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int top = 0;

void push(struct point p)
{
        stack[top++] = p;
}

struct point pop(void)
{
        return stack[--top];
}

int is_empty(void)
{
        return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 0 },
};

void print_maze(void)
{
        int i, j;
        for (i = 0; i < MAX_ROW; i++) {
                for (j = 0; j < MAX_COL; j++)
                        printf("%d ", maze[i][j]);
                putchar('\n');
        }
        printf("*********\n");
}

int predecessor[MAX_ROW][MAX_COL] = {
        /* 简化predecessor的数据结构，将row和col整合到一个数上 */
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
};

void visit(int row, int col, struct point pre)
{
        struct point visit_point = { row, col };
        maze[row][col] = 2;
        predecessor[row][col] = pre.row * MAX_ROW + pre.col;
        push(visit_point);
}

int main(void)
{
        /* 深度优先搜索走迷宫 */
        struct point p = { 0, 0 };
        struct point positive_stack[512]; /* 维护一个记录路径的栈 */
        int pos_top = 0; /* 栈顶 */

        maze[p.row][p.col] = 2;
        push(p);

        while (!is_empty()) {
                p = pop();
                if (p.row == MAX_ROW - 1 /* goal */
                                && p.col == MAX_COL - 1)
                        break;
                if (p.col+1 < MAX_COL    /* right */
                                && maze[p.row][p.col+1] == 0)
                        visit(p.row, p.col+1, p);
                if (p.row+1 < MAX_ROW    /* down */
                                && maze[p.row+1][p.col] == 0)
                        visit(p.row+1, p.col, p);
                if (p.col-1 >= 0         /* left */
                                && maze[p.row][p.col-1] == 0)
                        visit(p.row, p.col-1, p);
                if (p.row-1 >= 0        /* up */
                                && maze[p.row-1][p.col] == 0)
                        visit(p.row-1, p.col, p);
                print_maze();
        }
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
                positive_stack[pos_top++] = p;
                while (predecessor[p.row][p.col] != -1) {
                        /* 从终点到起点反向压入路径记录栈 */
                        int row = p.row, col = p.col;
                        p.row = predecessor[row][col] / MAX_ROW;
                        p.col = predecessor[row][col] % MAX_ROW;
                        positive_stack[pos_top++] = p;
                }
                while (pos_top != 0) {
                        --pos_top;
                        printf("(%d, %d)\n", positive_stack[pos_top].row,
                                        positive_stack[pos_top].col);
                }
        } else
                printf("No path!\n");

        return 0;
}
