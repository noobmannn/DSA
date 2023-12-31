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

// Hàm kiểm tra tính cân xứng của biểu thức dấu ngoặc
int isBalanced(char *bt) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; bt[i] != '\0'; ++i) {
        if (bt[i] == '(' || bt[i] == '[' || bt[i] == '{') {
            // Nếu là dấu mở ngoặc, đẩy vào ngăn xếp
            push(&stack, bt[i]);
        } else if (bt[i] == ')' || bt[i] == ']' || bt[i] == '}') {
            // Nếu là dấu đóng ngoặc, kiểm tra với dấu mở ngoặc ở đỉnh ngăn xếp
            if (isEmpty(&stack)) {
                return 0; // Không cân xứng nếu không có dấu mở ngoặc tương ứng
            }
            char dinh = pop(&stack);
            if ((bt[i] == ')' && dinh != '(') ||
                (bt[i] == ']' && dinh != '[') ||
                (bt[i] == '}' && dinh != '{')) {
                return 0; // Không cân xứng nếu không có dấu mở ngoặc tương ứng
            }
        }
    }

    // Biểu thức cân xứng nếu ngăn xếp trống
    return isEmpty(&stack);
}

int main() {
    char bt[MAX_SIZE];

    printf("Nhap bieu thuc: ");
    scanf("%s", bt);

    if (isBalanced(bt)) {
        printf("Can xung.\n");
    } else {
        printf("Khong can xung.\n");
    }

    return 0;
}
