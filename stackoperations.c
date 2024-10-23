#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack {
    int size;
    int top;
    int *arr;
};

bool isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

bool isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(int value, struct stack *ptr) {
    if (isFull(ptr)) {
        printf("Stack OverFlow!! cannot push %d into the stack\n", value);
        return;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d is pushed into the stack.\n", value);
    }
}

int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack UnderFlow!! cannot pop an element from the stack\n");
        return -1;
    } else {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d is popped from the stack.\n", value);
        return value;
    }
}

int peek(struct stack *ptr, int i) {
    int arrayIndex = ptr->top - i + 1;
    if (arrayIndex < 0) {
        printf("Invalid Position\n");
        return -1;
    } else {
        return ptr->arr[arrayIndex];
    }
}

void display(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= ptr->top; i++) {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int stacktop(struct stack *ptr) {
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr) {
    return ptr->arr[0];
}

void main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully!\n");

    int choice, element, i;

    while (1) {
        printf("\nOptions: 1. Push  2. Pop  3. Peek  4. Display  5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element, s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printf("Enter the position to peek: ");
                scanf("%d", &i);
                printf("Element at position %d is %d\n", i, peek(s, i));
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
