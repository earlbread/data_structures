#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *new_node(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = value;

    return temp;
}

void insert(struct node **head, int value)
{
    struct node *temp = new_node(value);

    if (*head == NULL) {
        *head = temp;
        return;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
}

void delete(struct node **head, int value)
{
    struct node *temp;

    if (*head == NULL) return;

    temp = *head;

    while (temp != NULL) {
        if (temp->data == value) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }

            if (temp == *head) {
                *head = temp->next;
            }
            free(temp);
        }
        temp = temp->next;
    }
}

void print(struct node *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(struct node **head)
{
    struct node *curr, *next;

    curr = *head;
    
    while (curr != NULL) {
        next = curr->next;

        curr->next = curr->prev;
        curr->prev = next;

        if (curr->prev == NULL)
            break;

        curr = next;
    }
    *head = curr;
}

int main(void)
{
    struct node *head = NULL;
    int i;

    for (i = 0; i < 5; i++) {
        insert(&head, i);
    }
    print(head);
    reverse(&head);
    print(head);
    
    return 0;
}
