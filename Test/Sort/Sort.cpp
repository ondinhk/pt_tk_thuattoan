#include <stdio.h>
typedef struct
{
    int key;
    float otherfields;
} recordtype;
void Swap(recordtype &x, recordtype &y)
{
    recordtype temp = x;
    x = y;
    y = temp;
}
void SelectionSort(recordtype a[], int n)
{
    int lowindex;
    int lowkey;
    for (int i = 0; i <= n - 2; i++)
    {
        lowindex = i;
        lowkey = a[i].key;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j].key < lowkey)
            {
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        Swap(a[i], a[lowindex]);
    }
}
void InsertionSort(recordtype a[], int n)
{
    int i, j;
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while ((j > 0) && (a[j].key < a[j - 1].key))
        {
            Swap(a[j], a[j - 1]);
            j--;
        }
    }
}
void BubbleSort(recordtype a[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j].key < a[j - 1].key)
            {
                Swap(a[j], a[j - 1]);
            }
        }
    }
}
//Quick Sort
//FindPivot
int FindPivot(recordtype a[], int i, int j)
{
    int firstkey = a[i].key;
    int k = i + 1;
    while ((k <= j) && (a[k].key == firstkey))
        k++;
    if (k > j)
        return -1;
    if (a[k].key > firstkey)
        return k;
    return i;
}
int Partition(recordtype a[], int i, int j, int pivot)
{
    int L = i, R = j;
    while (L <= R)
    {
        while (a[L].key < pivot)
            L++;
        while (a[R].key >= pivot)
            R--;
        if (L < R)
            Swap(a[L], a[R]);
    }
    return L;
}
void QuickSort(recordtype a[], int i, int j)
{
    int pivot, pivotindex, k;
    pivotindex = FindPivot(a, i, j);
    if (pivotindex != -1)
    {
        pivot = a[pivotindex].key;
        k = Partition(a, i, j, pivot);
        QuickSort(a, i, k - 1);
        QuickSort(a, k, j);
    }
}
void printArr(recordtype a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].key);
    }
}
//Heap Sort
void PushDown(recordtype a[], int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
    {
        if (last == 2 * r + 1)
        {
            if (a[r].key > a[last].key)
                Swap(a[r], a[last]);
            r = last;
        }
        else if (a[r].key > a[2 * r + 1].key && (a[2 * r + 1].key <= a[2 * r + 2].key))
        {
            Swap(a[r], a[r * 2 + 1]);
            r = 2 * r + 1;
        }
        else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key))
        {
            Swap(a[r], a[2 * r + 2]);
            r = 2 * r + 2;
        }
        else
        {
            r = last;
        }
    }
}
void pushdown(recordtype a[], int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
    {
        if (last == r * 2 + 1)
        {
            if (a[r].key > a[last].key)
                Swap(a[r], a[last]);
            r = last;
        }
        else if (a[r].key > a[r * 2 + 1].key && a[r * 2 + 1].key <= a[r * 2 + 2].key)
        {
            Swap(a[r], a[r * 2 + 1]);
            r = r * 2 + 1;
        }
        else if (a[r].key > a[r * 2 + 2].key && a[r * 2 + 2].key < a[r * 2 + 1].key)
        {
            Swap(a[r], a[r * 2 + 2]);
            r = r * 2 + 2;
        }
        else
            r = last;
    }
}
void Heap(recordtype a[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        pushdown(a, i, n - 1);
    }
    for (int i = n - 1; i >= 2; i--)
    {
        Swap(a[0], a[i]);
        pushdown(a, 0, i - 1);
    }
    Swap(a[0], a[1]);
}
int main()
{
    FILE *p = fopen("dayso.inp", "r");
    int n;
    recordtype a[100];
    fscanf(p, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(p, "%d", &a[i].key);
    }
    printf("DaySo: ");
    printArr(a, n);

    //SelectionSort(a, n);
    //InsertionSort(a, n);
    //BubbleSort(a, n);
    //QuickSort(a, 0, n - 1);
    Heap(a, n);
    printf("\nSau khi sap xep: ");
    printArr(a, n);
    return 0;
}
