#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (!*top) return -1;
    Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = createNode(data);
    if (!*rear) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(Node** front, Node** rear) {
    if (!*front) return -1;
    Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (!*front) *rear = NULL;
    free(temp);
    return data;
}

void printStack(Node* top) {
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void printQueue(Node* front) {
    while (front) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Node* stack = NULL;
    Node* queueFront = NULL;
    Node* queueRear = NULL;

    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Enqueue to Queue\n");
        printf("4. Dequeue from Queue\n");
        printf("5. Print Stack\n");
        printf("6. Print Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value == -1) printf("Stack is empty.\n");
                else printf("Popped from stack: %d\n", value);
                break;
            case 3:
                printf("Enter value to enqueue to queue: ");
                scanf("%d", &value);
                enqueue(&queueFront, &queueRear, value);
                break;
            case 4:
                value = dequeue(&queueFront, &queueRear);
                if (value == -1) printf("Queue is empty.\n");
                else printf("Dequeued from queue: %d\n", value);
                break;
            case 5:
                printf("Stack: ");
                printStack(stack);
                break;
            case 6:
                printf("Queue: ");
                printQueue(queueFront);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
