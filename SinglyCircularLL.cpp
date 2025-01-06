/*
    29.12.24
    Singly Circular LL
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;

        SinglyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
            }
            else
            {
                newn->next = head;
                head = newn;
            }
            tail->next = head;

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL & tail == NULL)
            {
                head = newn;
                tail = newn;
            }
            else
            {
                tail->next = newn;
                tail = newn;
            }
            tail->next = head;

            iCount++;
        }

        void DeleteFirst()
        {
            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                delete (tail->next);
                tail->next = head;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                delete tail;
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp = head;
                while(temp->next != tail)
                {
                    temp = temp->next;
                }
                tail = temp;
                delete(temp->next);
                tail->next = head;
            }

            iCount--;
        }

        void Display()
        {
            if(head == NULL && tail == NULL)
            {
                cout<<"LL is Empty\n";
                return;
            }

            cout<<"Nodes of Singly Circular : \n";
            do
            {
                cout<<" | "<<head->data<<" | > ";
                head = head->next;
            }while(head != tail->next);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no,int ipos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            int i = 0;

            if(ipos < 1 || ipos > iCount+1)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(ipos == 1)
            {
                InsertFirst(no);
            }
            if(ipos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                temp = head;

                for(i = 1; i < (ipos-1); i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int ipos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;

            int i = 0;

            if(ipos < 1 || ipos > iCount)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(ipos == 1)
            {
                DeleteFirst();
            }
            if(ipos == iCount+1)
            {
                DeleteLast();
            }
            else
            {
                temp = head;
                for(i = 1; i < (ipos-1); i++)
                {
                    temp = temp->next;
                }
                target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }
        
};

int main()
{
    SinglyCL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    sobj.InsertAtPos(75,4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    sobj.DeleteAtPos(4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";


    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";


    return 0;
}