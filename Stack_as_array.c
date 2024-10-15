#include <stdio.h>
#define max 100

struct stack {
    int a[max];
    int top;
};

void push(struct stack *s,int d) {
    if (s->top == max-1)
        printf("Stack full.");
    else {
        s-> top++;
        s->a[s->top] = d;
    }
}

void pop(struct stack *s) {
    if (s-> top == -1)
        printf("Empty stack");
    else {
        int data;
        data = s-> a[s->top];
        s->top--;
        printf("Deleted element is: %d",data);
    }
}

void display(struct stack *s) {
    if (s->top == -1){
        printf("Empty Stack\n");
        return;
    }
    for (int i = s-> top; i >= 0;i--) {
        printf("%d ",s->a[i]);
    }
}

int main() {
    struct stack s;
    s.top = -1; 
    int choice, value;

    while (1) {
        printf("Hello");
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exit");
                return 0;
        }
    }
    return 0;
}