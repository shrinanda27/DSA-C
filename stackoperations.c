#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    int size;
    int top;
    int *arr;
};

bool isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return true;
    }
    else{
        return false;
    }

}

bool isFUll(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return true;
    }
    else{
        return false;
    }
}

// push
void push(int value,struct stack *ptr){
    if(isFUll(ptr)){
        printf("Stack OverFlow!! cannot push %d into the stack\n",value);
        return;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
        printf("%d is pushed into the stack.\n",value);
    }
}

// pop
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack UnderFlow!! cannot pop an element from the stack\n");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        printf("%d is popped from the stack.\n",value);
        return value;
    }
}

// peek
int peek(struct stack *ptr,int i){
    int arrayIndex=ptr->top-i+1;
    if(arrayIndex<0){
        printf("Invalid Position\n");
        return -1;
    }
    else{
        return ptr->arr[arrayIndex];
    }

}

// stack top
int stacktop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

// stack bottom
int stackbottom(struct stack *ptr){
    return ptr->arr[0];
}


void main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    printf("Stack has been created successfully!\n");

    if(isEmpty(s)){
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }

    printf("-------------------------------------------------------------------------------------\n");

    push(5,s);
    int VAL=pop(s);
    printf("%d\n",VAL);

    push(6,s);
    push(7,s);
    push(8,s);

    int value=peek(s,3);
    printf("%d\n",value);

// to print stack elements
    for(int j=0;j<=s->top;j++){
        printf("The value at index %d is %d",j,peek(s,j+1));
        printf("\n");
    }

    // stack top and bottom
    printf("stack top element: %d\n",stacktop(s));
    printf("stack bottom element: %d\n",stackbottom(s));



    
}
