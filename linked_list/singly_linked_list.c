#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

struct list *search_list(struct list *head, int value)
{
    while (head != NULL) {
        if (head->data == value)
            break;
        head = head->next;
    }

    return head;
}

void insert_list(struct list **head, int value)
{
    struct list *temp;

    temp = (struct list *)malloc(sizeof(struct list));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void insert_list_nth(struct list **head, int n, int value)
{
    struct list *temp, *curr, *prev;
    int i;
    
    temp = (struct list *)malloc(sizeof(struct list));
    temp->data = value;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }
    
    if (n <= 0) {
        insert_list(head, value);
        return;
    }

    prev = *head;
    curr = prev->next;

    for (i = 1; i < n && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = temp;
    temp->next = curr;
}

void delete_list(struct list **head, int index)
{
    struct list *prev, *curr;
    int i;

    if (index == 0) {
        curr = *head;
        *head = (*head)->next;
        free(curr);
        return;
    }

    prev = *head;
    curr = prev->next;

    for (i = 1; i <= index && curr != NULL; i++) {
        if (i == index) {
            prev->next = curr->next;
            free(curr);
        }
        prev = curr;
        curr = curr->next;
    }
}

void Print(struct list *head)
{
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    Print(head->next);
}

void Print_reverse(struct list *head, struct list *curr)
{
    if (curr == NULL) {
        return;
    }
    Print_reverse(head, curr->next);
    printf("%d ", curr->data);

    if (curr == head) printf("\n");
}

void reverse_list(struct list **head)
{
    struct list *prev, *curr, *next;

    if (*head == NULL) return;

    prev = NULL;
    curr = *head;
    next = curr->next;

    while (next != NULL) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }

    curr->next = prev;
    *head = curr;
}

void reverse_list_recursion(struct list **head, struct list *prev, struct list *curr)
{
    if (curr == NULL) {
        *head = prev;
        return;
    }
    reverse_list_recursion(head, curr, curr->next);
    curr->next = prev;
}

int main(void)
{
    struct list *head = NULL;
    int nr_nums = 10;
    int i;

    for (i = 1; i <= nr_nums; i++) {
        insert_list(&head, i);
    }
    Print(head);

    printf("%d\n", search_list(head, 3)->data);
    delete_list(&head, 10);
    reverse_list_recursion(&head, NULL, head);
    Print(head);
    printf("%d\n", 3 /2);
}
