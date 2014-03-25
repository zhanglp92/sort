/*************************************************************************
	> File Name: select.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月25日 星期二 19时14分43秒
 ************************************************************************/

#include <stdio.h>

#define FALSE   0
#define TRUE    1


#define SWAP(x, y, type) \
    {type    __swap_; \
     __swap_ = x; \
     x = y; \
     y = __swap_;}

void select_sort (int r[], int n)
{
    int     i, j;

    for (i = 0; i < n; i++) { 
        int     k = i; 
        for (j = i+1; j < n; j++) {
            // 记录k的位置，k是j到n-1小于i且最小的
            if (r[j] < r[k]) 
                k = j;

            // 如果有这样的k则替换
            if (k != i)
                SWAP (r[i], r[k], int);
        }
    }
}

int main (void)
{
    int     r[10] = {1, 0, 4, 2, 9, 4, 9, 5, 6, 9};

    select_sort (r, 10);

    int     i;
    for (i = 0; i < 10; i++) 
        printf ("%-4d", r[i]);
    printf ("\n");

    return 0;
}
