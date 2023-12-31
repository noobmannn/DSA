#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count;
int x[50];
int a[50];
int b[50];
int c[50];

void Try(int i){
    for (int j = 1; j <= 8; j++) {
            // k tra hàng j và hai đường chèo i+j, i-j
            if (a[j] == 1 && b[i + j - 1] == 1 && c[i - j + 8] == 1) {
                x[i] = j; // đặt quân hậu
                a[j] = b[i + j - 1] = c[i - j + 8] = 0;// các vị trí không còn an toàn
                if (i < 8)
                    Try(i + 1);//quay lui cho tìm tiếp
                else{
                    count++; //Tìm thành công giải pháp và tăng lên
                    for (int k = 1; k <= 8; k++) printf("%d " ,x[k]);
                    printf("\n");
                    //in giải pháp
                }
                a[j] = b[i + j - 1] = c[i - j + 8] = 1;// xét lại để tiếp tục tìm giải pháp mới
            }
        }
}

int main(){
    count = 0;
    for (int i = 0; i < 50; i++) a[i] = b[i] = c[i] = 1;
    printf("Cac loi giai cua bai toan 8 quan hau: \n");
    Try(1);
    printf("So loi giai thu duoc: %d\n", count);
    return 0;
}
