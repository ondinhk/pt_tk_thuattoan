#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct
{
	keytype key;
	othertype otherfields;
} recordtype;

void Swap(recordtype &x, recordtype &y)
{
	recordtype temp;
	temp = x;
	x = y;
	y = temp;
}
//Selection Sort
void SelectionSort(recordtype a[], int n)
{
	int i, j, lowindex;
	keytype lowkey;
	for (i = 0; i <= n - 2; i++)
	{
		lowkey = a[i].key;
		lowindex = i;
		for (j = i + 1; j <= n - 1; j++)
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
//Insertion Sort -- SX xen
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
//Bubble Sort -- SX noi bot
void BubbleSort(recordtype a[], int n)
{
	int i, j;
	for (i = 0; i <= n - 2; i++)
		for (j = n - 1; j >= i + 1; j--)
			if (a[j].key < a[j - 1].key)
				Swap(a[j], a[j - 1]);
}
//Quick Sort -- SX nhanh
int FindPivot(recordtype a[], int i, int j)
{
	keytype firstkey;
	int k;
	k = i + 1;
	firstkey = a[i].key;
	while ((k <= j) && (a[k].key == firstkey))
		k++;
	if (k > j)
		return -1;
	if (a[k].key > firstkey)
		return k;
	return i;
}
int Partition(recordtype a[], int i, int j, keytype pivot)
{
	int L, R;
	L = i;
	R = j;
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
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a, i, j);
	if (pivotindex != -1)
	{
		pivot = a[pivotindex].key;
		k = Partition(a, i, j, pivot);
		QuickSort(a, i, k - 1);
		QuickSort(a, k, j);
	}
}
//Quick L<=pivot R>pivot
int FindPivot_50(recordtype a[], int i, int j)
{
	keytype firstkey;
	int k;
	k = i + 1;
	firstkey = a[i].key;
	while ((k <= j) && (a[k].key == firstkey))
		k++;
	if (k > j)
		return -1;
	if (a[k].key < firstkey)
		return k;
	return i;
}
int Partition_50(recordtype a[], int i, int j, keytype pivot)
{
	int L, R;
	L = i;
	R = j;
	while (L <= R)
	{
		while (a[L].key <= pivot)
			L++;
		while (a[R].key > pivot)
			R--;
		if (L < R)
			Swap(a[L], a[R]);
	}
	return L;
}
void QuickSort_50(recordtype a[], int i, int j)
{
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot_50(a, i, j);
	if (pivotindex != -1)
	{
		pivot = a[pivotindex].key;
		k = Partition_50(a, i, j, pivot);
		QuickSort(a, i, k - 1);
		QuickSort(a, k, j);
	}
}
//HeapSort
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
			Swap(a[r], a[2 * r + 1]);
			r = 2 * r + 1;
		}
		else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key))
		{
			Swap(a[r], a[2 * r + 2]);
			r = 2 * r + 2;
		}
		else
			r = last;
	}
}
void HeapSort(recordtype a[], int n)
{
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
		PushDown(a, i, n - 1);
	for (i = n - 1; i >= 2; i--)
	{
		Swap(a[0], a[i]);
		PushDown(a, 0, i - 1);
	}
	Swap(a[0], a[1]);
}
int main()
{
	FILE *file = fopen("dayso.inp", "r");
	recordtype a[100];
	int n, i, j;
	fscanf(file, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(file, "%d", &a[i]);
	}
	printf("Day so truoc khi sx: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	SelectionSort(a, n);
	printf("---SelectionSort:\n");

	//	InsertionSort(a,n);
	//	printf("\n\n---InsertionSort:\n");

	//	BubbleSort(a,n);
	//	printf("\n\n---BubbleSort:\n");

	//	i=0;
	//	j=n-1;
	//	QuickSort(a,i,j);
	//	printf("\n\n--QuickSort:\n");

	//BT 4-Trang50
	//	i=0;
	//	j=n-1;
	//	QuickSort_50(a,i,j);
	//	printf("\n\n--QuickSort (B4-50):\n");

	HeapSort(a, n);
	printf("\n\n---HeapSort:\n");
	printf("Day so sau khi sx: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
