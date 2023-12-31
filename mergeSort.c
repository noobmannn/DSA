#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Ham hoa nhap
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int Left[n1];
    int Right[n2];
    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        Right[i] = arr[mid + i + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

//Ham sap xep hoa nhap
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(a, 0, N - 1);
    printf("Mang sau khi sap xep: \n");
    hienthi(a, N);
    return 0;
}
