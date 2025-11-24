#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
}

void display_stack() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enqueue(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display_queue() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1. PUSH (Stack)\n2. POP (Stack)\n3. DISPLAY STACK\n");
        printf("4. ENQUEUE (Queue)\n5. DEQUEUE (Queue)\n6. DISPLAY QUEUE\n7. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter data: ");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            pop();
            break;

        case 3:
            display_stack();
            break;

        case 4:
            printf("Enter data: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            display_queue();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
