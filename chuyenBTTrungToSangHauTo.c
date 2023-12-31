#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc ngăn xếp
typedef struct {
    char data[MAX_SIZE];
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

// Hàm kiểm tra xem toán tử có ưu tiên cao hơn toán tử khác không
int KTUT(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Hàm chuyển biểu thức trung tố sang biểu thức hậu tố
void infixToPostfix(char *bt) {
    Stack stack;
    initialize(&stack);

    printf("Ket qua bien doi sang bieu thuc hau to: ");
    for (int i = 0; bt[i] != '\0'; ++i) {
        if (bt[i] >= 0x30 && bt[i] <= 0x39) {
            // Nếu là toán hạng, in ra màn hình
            printf("%c", bt[i]);
        } else if (bt[i] == '(') {
            // Nếu là dấu mở ngoặc, đẩy vào ngăn xếp
            push(&stack, '(');
        } else if (bt[i] == ')') {
            // Nếu là dấu đóng ngoặc, lấy toán tử từ ngăn xếp và in ra màn hình cho đến khi gặp dấu mở ngoặc
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                printf("%c", pop(&stack));
            }
            // Loại bỏ dấu mở ngoặc khỏi ngăn xếp
            pop(&stack);
        } else {
            // Nếu là toán tử, lấy toán tử từ ngăn xếp và in ra màn hình cho đến khi gặp toán tử có ưu tiên thấp hơn hoặc ngăn xếp trống
            while (!isEmpty(&stack) && KTUT(stack.data[stack.top]) >= KTUT(bt[i])) {
                printf("%c", pop(&stack));
            }
            // Đẩy toán tử mới vào ngăn xếp
            push(&stack, bt[i]);
        }
    }

    // In ra toàn bộ toán tử còn lại trong ngăn xếp
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }

    printf("\n");
}

int main() {
    char bt[MAX_SIZE];

    printf("Nhap bieu thuc trung to: ");
    scanf("%s", bt);

    infixToPostfix(bt);

    return 0;
}
