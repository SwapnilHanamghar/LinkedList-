/*
    Doubly Circular LinkList Using C
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;.

void InsertFirst(PPNODE head, PPNODE tail, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->next = NULL;

    if((*head) == NULL && (*tail) == NULL)
    {
        
    }
}

void InsertLast(PPNODE head, PPNODE tail, int no)
{

}

void InsertAtPos(PPNODE head, PPNODE tail, int ipos, int no)
{

}

void DeleteFirst(PPNODE head, PPNODE tail)
{

}

void DeleteLast(PPNODE head, PPNODE tail)
{

}

void DeleteAtPos(PPNODE head, PPNODE tail, int ipos)
{

}

void Display(PNODE head, PNODE tail)
{

}

int Count(PNODE head, PNODE tail)
{

}

int main()
{
    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    InsertFirst(&first, &last, 51);
    InsertFirst(&first, &last, 21);
    InsertFirst(&first, &last, 11);

    InsertLast(&first, &last, 101);
    InsertLast(&first, &last, 111);
    InsertLast(&first, &last, 121);

    Display(first, last);
    iRet = Count(first, last);
    printf("Elements in Singly Circular LL are : %d\n",iRet);

}