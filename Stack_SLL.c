#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* s, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack Empty\n");
        return -1;
    }
    struct Node* temp = s->top;
    int pop_data = temp->data;
    s->top = s->top->next;
    free(temp);
    printf("Deleted data: %d\n", pop_data);
}

void display(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* current = s->top;
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}

void menu() {
    struct Stack s;
    s.top = NULL;
    int choice, data;
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
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exit\n");
                return;
        }
    }
}

int main() {
    menu();
    return 0;
}
