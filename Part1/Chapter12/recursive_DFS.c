#include <stdio.h>
#define MAX_ROW 5
#define MAX_COL 5


struct point { int row, col; };

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

struct point visit(int row, int col)
{
        struct point p = { row, col };
        maze[row][col] = 2;
        print_maze();
        return p;
}

int recursive_DFS(struct point p)
{
        /* 递归实现深度优先搜索 */
        if (p.row == MAX_ROW - 1 /* goal */
                        && p.col == MAX_COL - 1)
                return 1;
        if (p.col+1 < MAX_COL    /* right */
                        && maze[p.row][p.col+1] == 0)
                if (recursive_DFS(visit(p.row, p.col+1)) == 1) {
                        return 1;
                }
        if (p.row+1 < MAX_ROW    /* down */
                        && maze[p.row+1][p.col] == 0)
                if (recursive_DFS(visit(p.row+1, p.col)) == 1) {
                        return 1;
                }
        if (p.col-1 >= 0         /* left */
                        && maze[p.row][p.col-1] == 0)
                if (recursive_DFS(visit(p.row, p.col-1)) == 1) {
                        return 1;
                }
        if (p.row-1 >= 0        /* up */
                        && maze[p.row-1][p.col] == 0)
                if (recursive_DFS(visit(p.row-1, p.col)) == 1) {
                        return 1;
                }
        return -1;
}

int main(void)
{
        struct point p = { 0, 0 };

        maze[p.row][p.col] = 2;

        recursive_DFS(p);
        if (maze[4][4] != 2)
                printf("No path!\n");

        return 0;
}
