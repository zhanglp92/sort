/*************************************************************************
	> File Name: QKSort.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月25日 星期二 19时14分43秒
 ************************************************************************/

#include <stdio.h>

int QK_pass (int r[], int low, int high);

void QK_sort (int r[], int low, int high)
{
    if (low < high) {
        int pos = QK_pass (r, low, high);
        QK_sort (r, low, pos-1);
        QK_sort (r, pos+1, high);
    }
}

int QK_pass (int r[], int low, int high)
{
    int x = r[low];

    while (low < high) {
        // 从右向左找小于x的元素
        while (low < high && r[high] >= x) 
            high--;
        // 找到小的送入low单元
        if (low < high) 
            r[low++] = r[high];

        // 从左向右找大于等于x的元素
        while (low < high && r[low] < x) 
            low++;
        // 找到大的送入high单元
        if (low < high) 
            r[high--] = r[low];
    }

    // 插入基准到 low = high单元
    r[low] = x;
    // 返回基准位置
    return low;
}

int main (void)
{
    int     r[10] = {1, 0, 4, 2, 9, 4, 9, 5, 6, 9};

    QK_sort (r, 0, 9);

    int     i;
    for (i = 0; i < 10; i++) 
        printf ("%-4d", r[i]);
    printf ("\n");

    return 0;
}
