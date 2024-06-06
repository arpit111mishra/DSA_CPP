//using DLL
#include<iostream>
#include<stdio.h>
#define UNDERFLOW 1;
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DEQUE
{
    private:
    node* front,*rear;
    public:
    DEQUE();
    void insertFront(int);
    void insertRear(int);
    void deleteFront();
    void deleteRear();
    int getRear();
    int getFront();
    ~DEQUE();
    bool isEmpty();
    DEQUE(DEQUE&);
    DEQUE& operator=(DEQUE&);
};
DEQUE::DEQUE()
{
    front=NULL;
    rear=NULL;
}
void DEQUE::insertFront(int data)
    {
        node *n=new node;
        n->prev=NULL;
        n->item=data;
        n->next=front;
        if(front==NULL)
          front=rear=n;
        else
        {
            front->prev=n;
            front=n;
        }
    }
void DEQUE::insertRear(int data)
    {
     node *n=new node;
     n->next=NULL;
     n->item=data;
     n->prev=rear;
     if(rear==NULL)
       front=rear=n;
     else
     {
        rear->next=n;
        rear=n;
     }  
    }
void DEQUE::deleteFront()
    {
        if(front==NULL)
          throw UNDERFLOW;
        if (front==rear)
        {
            delete front;
            front=rear=NULL;
        }
        else
        {
            front=front->next;
            delete front->prev;
            front->prev=NULL;
        }
    }
void DEQUE::deleteRear()
    {
        if(rear==NULL)
          throw UNDERFLOW;
        if(rear==front)
        {
            delete rear;
            front=rear=NULL;

        }  
        else
        {
            rear=rear->prev;
            delete rear->next;
            rear->next=NULL;
        }
    }
int DEQUE::getFront()
    {
        if(front==NULL)
          throw UNDERFLOW;
        return front->item;  
    }
int DEQUE::getRear()
{
    if(rear==NULL)
      throw UNDERFLOW;
    return rear->item;  
}
DEQUE::~DEQUE()
{
    while(front)
      deleteFront();
}
bool DEQUE::isEmpty()
{
    return front==NULL;
}
DEQUE::DEQUE(DEQUE& d)
{
    node *t;
    if(d.front==NULL)
      front=rear=NULL;
    else
    {
        t=d.front;
        while(t!=NULL)
        {
            insertRear(t->item);
            t=t->next;
        }
    }  
}
DEQUE& DEQUE::operator=(DEQUE& d)
{
    while(front)
      deleteFront();
    node *t;
    if(d.front==NULL)
      front=rear=NULL;
    else
    {
        t=d.front;
        while(t!=NULL)
        {
            insertRear(t->item);
            t=t->next;
        }
    }  
    return *this;
}