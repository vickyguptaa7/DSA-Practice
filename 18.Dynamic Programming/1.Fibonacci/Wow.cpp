#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL, *tail = NULL;
int n = 0;

// Function prototypes
void insert_beg(void);
void insert_end(void);
void insert_gposition(void);
void delete_beg(void);
void delete_end(void);
void search(void);
void display(void);
void reverse_d(void);
void to_free_m(void);
int is_empty(void);

int main(void)
{
    printf("\n20BCS012 ARISH ANWAR\n\n");

    int choice;
    while (1)
    {
        printf("<-+--MENU--+->\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at given position\n");
        printf("4. Deletion from beginning\n");
        printf("5. Deleion from end\n");
        printf("6. Print linked list in reverse order\n");
        printf("7. Search for element\n");
        printf("8. Display\n");
        printf("9. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            insert_beg();
            display();
            break;

        case 2:
            insert_end();
            display();
            break;

        case 3:
            insert_gposition();
            display();
            break;

        case 4:
            delete_beg();
            display();
            break;

        case 5:
            delete_end();
            display();
            break;

        case 6:
            reverse_d();
            display();
            break;

        case 7:
            search();
            display();
            break;

        case 8:
            display();
            break;

        case 9:
            printf("Exit.\n");
            to_free_m();
            return 1;

        default:
            printf("Not a valid choice.\n\n");
            break;
        }
    }
}

void insert_beg(void)
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Error.\n\n");
        return;
    }

    n++;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
        printf("Enter the number: ");
        scanf("%d", &(ptr->x));
        printf("\n");
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }

    printf("Enter the number: ");
    scanf("%d", &(ptr->x));
    printf("\n");
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    head = ptr;
    return;
}

void insert_end(void)
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Error.\n\n");
        return;
    }

    n++;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
        printf("Enter the number: ");
        scanf("%d", &(ptr->x));
        printf("\n");
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }

    printf("Enter the number: ");
    scanf("%d", &(ptr->x));
    printf("\n");
    ptr->next = NULL;
    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;
    return;
}

void insert_gposition(void)
{
    int a;
    printf("To insert at position: ");
    scanf("%d", &a);

    if (a == 0 || a > n + 1)
    {
        printf("Out of bound position.\n\n");
        return;
    }

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Error.\n\n");
        return;
    }

    n++;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
        printf("Enter the number: ");
        scanf("%d", &(ptr->x));
        printf("\n");
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }

    printf("Enter the number: ");
    scanf("%d", &(ptr->x));
    printf("\n");

    if (a == 1)
    {
        head->prev = ptr;
        ptr->next = head;
        ptr->prev = NULL;
        head = ptr;
        return;
    }
    if (a == n)
    {
        ptr->next = NULL;
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
        return;
    }

    node *tmp = head;
    for (int i = 1; i < a - 1; i++)
    {
        tmp = tmp->next;
    }
    ptr->next = tmp->next;
    tmp->next->prev = ptr;
    ptr->prev = tmp;
    tmp->next = ptr;
    return;
}

void delete_beg(void)
{
    if (is_empty())
    {
        printf("Linked list is empty.\n\n");
        return;
    }

    n--;
    node *ptr;

    if (head == tail)
    {
        printf("Deleted element: %d\n\n", head->x);
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    printf("Deleted element: %d\n\n", head->x);
    ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return;
}

void delete_end(void)
{
    if (is_empty())
    {
        printf("Linked list is empty.\n\n");
        return;
    }

    n--;
    node *ptr;

    if (head == tail)
    {
        printf("Deleted element: %d\n\n", head->x);
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    printf("Deleted element: %d\n\n", tail->x);
    ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(ptr);
    return;
}

void search(void)
{
    if (is_empty())
    {
        printf("Linked list is empty.\n\n");
        return;
    }

    int b, c = 0;
    printf("Enter element to search for: ");
    scanf("%d", &b);

    node *ptr = head;
    while (ptr != NULL)
    {
        c++;
        if (ptr->x == b)
        {
            printf("Element is present at position %d.\n\n", c);
            return;
        }
        ptr = ptr->next;
    }
    printf("Element is not present.\n\n");
    return;
}

void display(void)
{
    if (is_empty())
    {
        printf("Linked list is empty.\n\n");
        return;
    }

    node *ptr = head;
    printf("Linked list: START | ");
    while (ptr->next != NULL)
    {
        printf("%d ⇄  ", ptr->x);
        ptr = ptr->next;
    }
    printf("%d | END\n\n", ptr->x);
    return;
}

void reverse_d(void)
{
    if (is_empty())
    {
        printf("Linked list is empty.\n\n");
        return;
    }

    node *ptr = tail;
    printf("Reversed linked list: END | ");
    while (ptr->prev != NULL)
    {
        printf("%d ⇄  ", ptr->x);
        ptr = ptr->prev;
    }
    printf("%d | START\n\n", ptr->x);
    return;
}

void to_free_m(void)
{
    if (is_empty())
    {
        return;
    }
    node *ptr;
    while (head != NULL)
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    return;
}

int is_empty(void)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}