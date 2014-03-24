/*************************************************************************
	> File Name: zhijieInsertSort.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月24日 星期一 17时34分39秒
 ************************************************************************/

#include <stdio.h>

typedef struct _NODE {

    int     key;
    char    other_data;
}RecordType;

void insert_sort (RecordType *r, int l)
{
    /* 数组元素 r[0]是监视哨 */
    int     i, j;
    for (i = 2; i <= l; i++) {
        r[0] = r[i];
        /* 从后向前比较，边比较边移动 */
        for (j = i-1; r[0].key < r[j].key; j--) 
            r[j+1] = r[j];
        r[j+1] = r[0];
    }
}

int main (void)
{
    RecordType     r[10+1] = {{0}, {3, 'a'}, {9, 'b'}, {3, 'c'}, {5, 'd'}, {3, 'e'}, {8, 'f'}, {6, 'g'}, {4, 'h'}, {9, 'i'}, {1, 'j'}};

    insert_sort (r, 10); 

    int     i;
    for (i = 1; i <= 10; i++) 
        printf ("%+4d,%c", r[i].key, r[i].other_data);
    printf ("\n");

    return 0;
}
