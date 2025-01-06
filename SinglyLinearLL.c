/*
   Singly Linear LinkedList
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head, int value)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = value;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head, int value)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = value;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE head)
{
    printf("Elements of Linked List are : \n");

    while(head != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }   
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCount = 0;
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;
        *head = (*head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE head, int value, int ipos)
{
    int CountNode = 0;
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    CountNode = Count(*head);

    if((ipos < 1) || (ipos > CountNode+1))      //Filter
    {
        printf("invalid Position\n");
        return;
    }

    if(ipos == 1)                      // POS first
    {
        InsertFirst(head, value);
    }
    else if(ipos == CountNode+1)      // POS last
    {
        InsertLast(head, value);
    }
    else                            // POS In between
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = value;
        newn->next = NULL;

        temp = *head;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE head, int ipos)
{
    int CountNode = 0;
    int i = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    CountNode = Count(*head);

    if((ipos < 1) || (ipos > CountNode))      //Filter
    {
        printf("invalid Position\n");
        return;
    }

    if(ipos == 1)                      // POS first
    {
        DeleteFirst(head);
    }
    else if(ipos == CountNode+1)      // POS last
    {
        DeleteLast(head);
    }
    else                            // POS In between
    {
        temp = *head;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        free(target);
    }
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    InsertLast(&first, 101);
    InsertLast(&first, 111);
    InsertLast(&first, 121);

    
    InsertAtPos(&first, 75, 4);

    Display(first);
    iRet = Count(first);
    printf("Elements in LL : %d\n",iRet);

    DeleteAtPos(&first, 4);
    
    Display(first);
    iRet = Count(first);
    printf("Elements in LL : %d\n",iRet);

    return 0;
}