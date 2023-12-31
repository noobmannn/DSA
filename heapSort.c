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

// Hàm vun đống
void heapify(int K[], int root, int N)
{
    int Key = K[root];
    int c;
    while (2 * root < N - 1)
    {
        c = root * 2 + 1;
        if (c < N - 1 && K[c] < K[c + 1])
            c++;
        if (K[c] < Key)
            break;
        K[root] = K[c];
        root = c;
    }
    K[root] = Key;
}

// Hàm thực hiện Heap Sort
void heap_sort(int K[], int N)
{
    // Chuyển mảng thành một đống
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(K, i, N);
    // Heap sort
    for (int i = N - 1; i > 0; i--)
    {
        swap(K, 0, i);
        heapify(K, 0, i);
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
    heap_sort(a, N);
    printf("Mang sau khi sap xep: \n");
    hienthi(a, N);
    return 0;
}
