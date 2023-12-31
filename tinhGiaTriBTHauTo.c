#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc ngăn xếp
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Hàm khởi tạo ngăn xếp
void initialize(Stack *stack) {
    stack->top = -1;
}

// Hàm kiểm tra xem ngăn xếp có trống hay không
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm kiểm tra xem ngăn xếp có đầy hay không
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Hàm đẩy một phần tử vào ngăn xếp
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Day\n");
        exit(0);
    }
    stack->data[++stack->top] = value;
}

// Hàm lấy và xóa một phần tử từ ngăn xếp
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Rong\n");
        exit(0);
    }
    return stack->data[stack->top--];
}

// Hàm tính giá trị của biểu thức hậu tố
int evaluatePostfix(char *bt) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; bt[i] != '\0'; ++i) {
        if (bt[i] >= 0x30 && bt[i] <= 0x39) {
            // Nếu là số, đẩy vào ngăn xếp
            push(&stack, bt[i] - 0x30);
        } else {
            // Nếu là toán tử, lấy hai toán hạng từ ngăn xếp và thực hiện phép toán
            int gt2 = pop(&stack);
            int gt1 = pop(&stack);

            switch (bt[i]) {
                case '+':
                    push(&stack, gt1 + gt2);
                    break;
                case '-':
                    push(&stack, gt1 - gt2);
                    break;
                case '*':
                    push(&stack, gt1 * gt2);
                    break;
                case '/':
                    push(&stack, gt1 / gt2);
                    break;
            }
        }
    }

    // Kết quả cuối cùng nằm trên đỉnh ngăn xếp
    return pop(&stack);
}

int main() {
    char bt[MAX_SIZE];

    printf("Nhap bieu thuc hau to: ");
    scanf("%s", bt);

    int result = evaluatePostfix(bt);

    printf("Gia tri cua bieu thuc hau to la: %d\n", result);

    return 0;
}
