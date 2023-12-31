#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void thapHaNoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("Lay dia 1 tu coc %c sang coc %c\n", a, b);
        return;
    }
    thapHaNoi(n - 1, a, c, b);
    printf("Lay dia %d tu coc %c sang coc %c\n", n, a, b);
    thapHaNoi(n - 1, c, b, a);
}

int main()
{
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    thapHaNoi(n, 'A', 'B', 'C');
    return 0;
}
