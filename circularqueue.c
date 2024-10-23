#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct circularqueue {
    int size;
    int f;
    int r;
    int *arr;
};

bool isFull(struct circularqueue *q) {
    if ((q->r + 1) % q->size == q->f) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty(struct circularqueue *q) {
    if (q->r == -1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(struct circularqueue *q, int val) {
    if (isFull(q)) {
        printf("Queue OverFlow\n");
    } else {
        if (q->r == -1) {
            q->f = q->r = 0;
        } else {
            q->r = (q->r + 1) % q->size;
        }
        q->arr[q->r] = val;
        printf("%d enqueued into the queue.\n", val);
    }
}

int dequeue(struct circularqueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int val = q->arr[q->f];
        if (q->f == q->r) {
            q->f = q->r = -1;
        } else {
            q->f = (q->f + 1) % q->size;
        }
        return val;
    }
}

void display(struct circularqueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = q->f;
    printf("Queue elements: ");
    while (i != q->r) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[i]);
}

int main() {
    struct circularqueue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size * sizeof(int));

    int choice, val;

    while (1) {
        printf("\nOptions: 1. Enqueue  2. Dequeue  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1) {
                    printf("Deleted element: %d\n", val);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
