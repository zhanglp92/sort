/*************************************************************************
	> File Name: bubble.c
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

void bubble_sort (int r[], int l)
{
    int     i, j; 
    int     t; 
    unsigned char   change = TRUE;

    for (i = 0; i < l && change; i++) {

        change = FALSE;
        for (j = 0; j < l-i-1; j++) 
            if (r[j] > r[j+1]) { 
                SWAP (r[j], r[j+1], int);
                change = TRUE;
            } 
    }
} 

int main (void)
{
    int     r[10] = {1, 0, 4, 2, 9, 4, 9, 5, 6, 9};

    bubble_sort (r, 10);

    int     i;
    for (i = 0; i < 10; i++) 
        printf ("%-4d", r[i]);
    printf ("\n");

    return 0;
}
