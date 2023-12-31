#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int x[], int i, int j)
{
    int tmp;
    tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

//Hàm Phân Đoạn
int partition(int k[], int t, int p)
{
    int i = t + 1;
    int j = p;
    do
    {
        while (i <= j && k[i] < k[t])
            i++;
        while (i <= j && k[j] > k[t])
            j--;
        if (i < j)
        {
            swap(k, i, j);
            i++;
            j++;
        }
    } while (i <= j);
    swap(k, t, j);
    return j;
}

//Hàm sắp xếp nhanh
void quick_sort(int k[], int t, int p)
{
    if (t < p)
    {
        int pivot = partition(k, t, p);
        quick_sort(k, t, pivot - 1);
        quick_sort(k, pivot + 1, p);
    }
}

void hienthi(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &N);
    int a[N];
    for(int i = 0; i < N; i++){
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Mang truoc khi sap xep: \n");
    hienthi(a, N);
    quick_sort(a, 0, N - 1);
    printf("Mang sau khi sap xep: \n");
    hienthi(a, N);
    return 0;
}
