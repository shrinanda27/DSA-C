#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

bool isFULL(struct queue *q) {
    if (q->r == q->size - 1) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty(struct queue *q) {
    if (q->r == q->f) {
        return true;
    } else {
        return false;
    }
}

void enqueue(struct queue *q, int val) {
    if (isFULL(q)) {
        printf("Queue Overflow! Cannot enqueue %d into queue\n", val);
    } else {
        q->r = q->r + 1;
        q->arr[q->r] = val;
        printf("%d enqueued into the queue.\n", val);
    }
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        q->f++;
        int val = q->arr[q->f];
        return val;
    }
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->f + 1; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    q.size = 50;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int choice, val;

    while (1) {
        printf("\nOptions: 1. Enqueue  2. Dequeue  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1) {
                    printf("Dequeued element: %d\n", val);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
