/*
    Doubly Linear LL using C++ (OOP APPROACH)
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class DoublyLL
{
    public:
        int iCount;
        PNODE head;

        DoublyLL()
        {
            iCount = 0;
            head = NULL;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head->prev = newn;
                head = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
            }
            iCount++;
        }

        void InsertAtPos(int ipos, int no)
        {
            if(ipos < 1 && ipos > iCount+1)
            {
                cout<<"Invalid Position\n";
            }
            
            if(ipos == 1)
            {
                InsertFirst(no);
            }
            else if(ipos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = NULL;
                PNODE temp = NULL;
                int i = 0;

                newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = head;
                for(i = 1; i < ipos-1; i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                iCount++;
            }
            
            
        }

        void DeleteAtPos(int ipos)
        {
            if(ipos < 1 && ipos > iCount)
            {
                cout<<"Invalid Position\n";
            }
            
            if(ipos == 1)
            {
                DeleteFirst();
            }
            else if(ipos == iCount)
            {
                DeleteLast();
            }
            else
            {
                PNODE target = NULL;
                PNODE temp = NULL;
                int i = 0;

                temp = head;
                for(i = 1; i < ipos-1; i++)
                {
                    temp = temp->next;
                }
                target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;
                delete target;

                iCount--;
            }   
        }

        void Display()
        {
            PNODE temp = head;
            
            cout<<"ELements of the LL are : NULL <=>";
            while(temp != NULL)
            {
                cout<<" | "<<temp->data<<" | <=> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return;
            }
            if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return;
            }
            if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                temp = head;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        
};

int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements : "<<iRet<<"\n";

    dobj.InsertAtPos(4, 75);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements : "<<iRet<<"\n";

    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements : "<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements : "<<iRet<<"\n";
    
    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements : "<<iRet<<"\n";


    
    return 0;
}