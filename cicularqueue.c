#include <stdio.h>
#define size 5

int a[size];
int front = -1, rear = -1;

int isempty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if (front == (rear + 1) % size)
        return 1;
    else
        return 0;
}

void enqueue(int x) {
    if (isfull()) {
        printf("The queue is full\n");
        return;
    } else if (isempty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    a[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", a[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (isempty()) {
        printf("The queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", a[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int ch, x;
    do {
        printf("\nEnter choice:\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Enter valid choice!\n");
        }
    } while (ch != 4);

    return 0;
}
