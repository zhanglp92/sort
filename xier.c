/*************************************************************************
	> File Name: xier.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月24日 星期一 21时30分32秒
 ************************************************************************/

#include <stdio.h>

void shell_insert (int r[], int l, int delta)
{
    int     i, j;
    for (i = 1+delta; i <= l; i++) {
        if (r[i] < r[i-delta]) {
            r[0] = r[i];

            // 组内进行直接插入排序
            for (j = i-delta; j > 0 && r[0] < r[j]; j-=delta) 
                r[j+delta] = r[j];
            r[j+delta] = r[0];
        }
    }
}

void shell_sort (int r[], int l, int delta[], int n)
{
    int     i;
    for (i = 0; i < n; i++) {
        shell_insert (r, l, delta[i]);
    }
}

int main (void)
{
    int     r[10+1] = {0, 1, 9, 7, 3, 0, 5, 2, 0, 8, 3};
    int     delta[5] = {5, 3, 2, 1};

    shell_sort (r, 10, delta, 4);

    int     i;
    for (i = 1; i <= 10; i++) 
        printf ("%-4d", r[i]);
    printf ("\n");

    return 0;
}
