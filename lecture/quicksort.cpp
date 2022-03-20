#include "../leetcode.h"

// ------------------------------------------------
// 快速排序
// ------------------------------------------------
// https://www.geeksforgeeks.org/quick-sort/
// https://www.runoob.com/w3cnote/quick-sort-2.html

int partition(int* arr, int low, int high)
{
    // 将第一个元组设为pivot
    int pivot = arr[low];
    //   ▼
    //   ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛
    //   ▲                ▲
    //  low ▶          ◄ high

    while (low < high)
    {
        // 如果high ≥ pivot，右边界持续左移
        while (low < high && arr[high] >= pivot)
        {
            --high;
        }
        arr[low] = arr[high]; // 直至arr[high] < pivot，将其移至arr[low]

        // 如果low ≤ pivot，左边界持续右移
        while (low < high && arr[low] <= pivot)
        {
            ++low;
        }
        arr[high] = arr[low]; // 直至arr[low] > pivot，将其移至arr[high]
    }

    // 经过上面的操作，右移的low与左移的high相遇，将pivot放置此位
    arr[low] = pivot;
    return low;
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        // 分而治之，以arr[low]的值为pivot
        // 将所有小于pivot的元素放在pivot左侧
        // 将所有大于pivot的元素放在pivot右侧
        // ------------------------------
        //   smaller       bigger
        //  ┗┻┻┻┻┻┻┻┻pivot┻┻┻┻┻┻┻┻┛
        int pi = partition(arr, low, high);

        // 递归对两侧进行快排
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(int argc, char** argv)
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 快速排序
    quickSort(arr, 0, n-1);

    display(vector<int>(begin(arr), end(arr)));
    return 0;
}
