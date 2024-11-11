#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

struct Node* create(int data, struct Node *head) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode; 
    }
    return head;
}

struct Node* deletefirst(struct Node *head) {
    if (head == NULL) {printf("LINKED LIST is empty"); return NULL;}
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* deleteatindex(struct Node *head, int index) {
    if (head == NULL || index < 0) {
        printf("LINKED LIST is empty");
        return head;
    }
    
    if (index == 0) { 
        return deletefirst(head);
    }

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++) {
        if (q == NULL) {
            printf("index out of range\n");
            return head; } 
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);  
    return head;
}

struct Node* deleteatlast(struct Node *head) {
    if (head == NULL){
    printf("LINKED LIST is empty");
    return NULL;}
    else if (head->next == NULL) {  
        free(head);
        return NULL;
    } else {
        struct Node *p = head;
        struct Node *q = head->next;
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        p->next = NULL; 
        free(q);
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    int data, idx;
    
    while (1) {
        printf("SELECT:\n");
        printf("1. CREATE\n");
        printf("2. DELETE AT FIRST\n");
        printf("3. DELETE AT INDEX\n");
        printf("4. DELETE AT LAST\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create a new node: ");
                scanf("%d", &data);
                head = create(data, head);
                break;
                
            case 2:
                head = deletefirst(head);
                break;
                
            case 3:
                printf("Enter the index to delete: ");
                scanf("%d", &idx);
                head = deleteatindex(head, idx);
            
                break;
                
            case 4:
                head = deleteatlast(head);
            
                break;
                
            case 5:
                printf("Linked List: ");
                display(head);
                break;
                
            case 6:
                printf("Exiting.......\n");
                exit(0);
                
            default:
                printf("Invalid choice!!!!!\n");
        }
    }

    return 0;
}
