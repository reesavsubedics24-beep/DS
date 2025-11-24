#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;

void CreateLinked_list(int n) {
    struct node *newnode, *temp;
    int data;

    if (n == 0) {
        printf("Number of nodes cannot be zero\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
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
}

void CreateLinked_list2(int n) {
    struct node *newnode, *temp;
    int data;

    if (n == 0) {
        printf("Number of nodes cannot be zero\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for List2 node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head2 == NULL) {
            head2 = newnode;
            temp = head2;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void sort_list() {
    struct node *i, *j;

    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse() {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nextnode;

    while (curr != NULL) {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    head = prev;
}

void concat() {
    if (head == NULL) {
        head = head2;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void display(struct node *h) {
    struct node *temp = h;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create Linked List 1\n");
        printf("2. Create Linked List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List1 + List2\n");
        printf("6. Display List 1\n");
        printf("7. Display List 2\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            CreateLinked_list(n);
            break;

        case 2:
            printf("Enter number of nodes for List 2: ");
            scanf("%d", &n);
            CreateLinked_list2(n);
            break;

        case 3:
            sort_list();
            break;

        case 4:
            reverse();
            break;

        case 5:
            concat();
            break;

        case 6:
            display(head);
            break;

        case 7:
            display(head2);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
