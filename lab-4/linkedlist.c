#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void CreateLinked_list(int n) {
    struct node *newnode, *temp;
    int i, data;

    if (n == 0) {
        printf("number of node cannot be zero\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("memory allocation failed\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Linked list created successfully\n");
}

void InsertAtBeginning(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    printf("Node inserted at the beginning.\n");
}

void InsertAtEnd(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node inserted at the end.\n");
}

void InsertAtPosition(int data, int pos) {
    int i;
    struct node *newnode, *temp = head;

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        InsertAtBeginning(data);
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted at position %d.\n", pos);
    }
}

void displayList() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                CreateLinked_list(n);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtBeginning(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                InsertAtPosition(data, pos);
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtEnd(data);
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
