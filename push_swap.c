#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void   lst_addback(t_list  *lst, int i);

void    swap_a(t_list *a)
{
    int     i;

    if(a && a->next)
    {
        i = a->data;
        a->data = a->next->data;
        a->next->data = i;
    }
}

void    swap_b(t_list *b)
{
    int     i;

    if(b && b->next)
    {
        i = b->data;
        b->data = b->next->data;
        b->next->data = i;
    }
}

void    swap_ab(t_list *a, t_list *b)
{
    swap_a(a);
    swap_b(b);
}

void    push_a(t_list **a, t_list **b)
{
    t_list  **tem;

    *tem = (*b)->next;
    (*b)->next = *a;
    *a = *b;
    *b = *tem;
}

void    push_b(t_list **b, t_list **a)
{
    t_list  **tem;

    *tem = (*a)->next;
    (*a)->next = *b;
    *b = *a;
    *a = *tem;
}
void    rotate_a(t_list **a)
{
    t_list  **t;
    t_list  **tt;

    *t = *a;
    (*a) = (*a)->next;
    *tt = *a;
    while((*tt)->next != NULL)
    {
        *tt = (*tt)->next;
    }
    (*t)->next = NULL;
    (*tt)->next = *t;
}

void    rotate_b(t_list **b)
{
    t_list  **t;
    t_list  **tt;

    *t = *b;
    (*b) = (*b)->next;
    *tt = *b;
    while((*tt)->next != NULL)
    {
        *tt = (*tt)->next;
    }
    (*t)->next = NULL;
    (*tt)->next = *t;
}

void    rotate_all(t_list **a, t_list **b)
{
    rotate_a(a);
    rotate_b(b);
}

void    reverse_rotate_a(t_list **a)
{
    t_list  **t;
    t_list  **tt;

    *tt = *a;
    while((*tt)->next->next != NULL)
    {
        *tt = (*tt)->next;
    }
    *t = (*tt)->next;
    printf("\nthe result:%d\n", (*tt)->data);
    (*tt)->next = NULL;
    (*t)->next = *a;
    *a = *t;
}

void    reverse_rotate_b(t_list **b)
{
    t_list  **t;
    t_list  **tt;

    *tt = *b;
    while((*tt)->next->next != NULL)
    {
        *tt = (*tt)->next;
    }
    *t = (*tt)->next;
    printf("\nthe result:%d\n", (*tt)->data);
    (*tt)->next = NULL;
    (*t)->next = *b;
    *b = *t;
}

void    reverse_rotate_all(t_list **a, t_list **b)
{
    reverse_rotate_a(a);
    reverse_rotate_b(b);
}

int main(void)
{
    t_list  *a;

    a = (t_list *)malloc(sizeof(t_list));
    a->data = 1;
    lst_addback(a, 2);
    lst_addback(a, 3);
    printf("1.%d, 2.%d 3.%d\n", a->data, a->next->data, a->next->next->data);
    reverse_rotate_a(&a);
    printf("a1.%d, a2.%d 3.%d\n", a->data, a->next->data, a->next->next->data);
    return (0);
}

void   lst_addback(t_list  *lst, int i)
{
    t_list  *t_lst;

    t_lst = lst;
    while(t_lst->next != NULL)
        t_lst = t_lst->next;
    t_lst->next = (t_list *)malloc(sizeof(t_list));
    t_lst->next->data = i;
    t_lst->next->next = NULL;
    return;
}