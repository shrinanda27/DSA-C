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

Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head)
        return newNode;
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* sortList(Node* head) {
    if (!head || !head->next)
        return head;
    Node* i = head;
    while (i) {
        Node* j = i->next;
        while (j) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* concatenateLists(Node* head1, Node* head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    Node* temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate Lists\n");
        printf("6. Print List 1\n");
        printf("7. Print List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into List 1: ");
                scanf("%d", &value);
                list1 = insertEnd(list1, value);
                break;
            case 2:
                printf("Enter value to insert into List 2: ");
                scanf("%d", &value);
                list2 = insertEnd(list2, value);
                break;
            case 3:
                list1 = sortList(list1);
                printf("List 1 sorted.\n");
                break;
            case 4:
                list1 = reverseList(list1);
                printf("List 1 reversed.\n");
                break;
            case 5:
                list1 = concatenateLists(list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 6:
                printf("List 1: ");
                printList(list1);
                break;
            case 7:
                printf("List 2: ");
                printList(list2);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
