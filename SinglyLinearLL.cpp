#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public:
        PNODE head;
        int iCount;

        SinglyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn -> data = no;
            newn -> next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn -> next = head;
                head = newn;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;
            newn -> data = no;
            newn -> next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = newn;   
            }

            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return;
            }
            else if(head -> next == NULL)
            {
                delete head;
                head -> next = NULL;
            }
            else
            {
                temp = head;

                head = head -> next;
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
            else if(head -> next == NULL)
            {
                delete head;
                head -> next = NULL;
            }
            else
            {
                temp = head;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                
                delete temp -> next;
                temp -> next = NULL;
            }
            iCount--;
        }

        void Display()
        {
            PNODE temp = head;

            cout<<"Elements in LinkedList are : \n";

            while(temp != NULL)
            {
                cout<<"| "<<temp -> data<<" | > ";
                temp = temp -> next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int ipos)
        {
            int CountNode = 0;
            int i = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            CountNode = Count();

            if((ipos < 1) || (ipos > CountNode+1))
            {
                cout<<"invalid \n";
                return;
            }

            if(ipos == 1)
            {
                InsertFirst(no);
            }
            else if(ipos == CountNode+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn -> data = no;
                newn -> next = NULL;

                temp = head;

                for(i = 1; i < ipos-1; i++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;
                temp -> next = newn; 
            }
            iCount++;
        }

        void DeleteAtPos(int ipos)
        {
            int CountNode = 0;
            int i = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            CountNode = Count();

            if((ipos < 1) || (ipos > CountNode))
            {
                cout<<"invalid \n";
                return;
            }

            if(ipos == 1)
            {
                DeleteFirst();
            }
            else if(ipos == CountNode)
            {
                DeleteLast();
            }
            else
            {
                temp = head;

                for(i = 1; i < ipos-1; i++)
                {
                    temp = temp -> next;
                }
                
                target = temp -> next;
                temp -> next = target -> next;
                delete target;
            }
            iCount--;
        }
};

int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"number of elements in LL : "<<iRet<<"\n";

    /*sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"number of elements in LL : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"number of elements in LL : "<<iRet<<"\n";*/

    sobj.InsertAtPos(75, 4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"number of elements in LL : "<<iRet<<"\n";

    sobj.DeleteAtPos(4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"number of elements in LL : "<<iRet<<"\n";

    return 0;
}