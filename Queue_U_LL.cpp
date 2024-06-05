#include<iostream>
#include<stdio.h>
#define EMPTY_LIST 1
using namespace std;
struct node
{
    int item;
    node *next;
};
class QUEUE
{
node *front;
node *rear;
public:
QUEUE();
void insert(int);
int getFront();
int getBack();
void del();
~QUEUE();
QUEUE(QUEUE&);
QUEUE& operator=(QUEUE&);
int count();
};
QUEUE::QUEUE()
{
front=NULL;
rear=NULL;
}
void QUEUE::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(rear==NULL)
      {
        front=n;
        rear=n;
      }
      else
      {
        rear->next=n;
        rear=n;
      }
}
int QUEUE::getBack()
{
    if(rear==NULL)
      throw EMPTY_LIST;
    return rear->item;  
}
int QUEUE::getFront()
{
    if(front==NULL)
      throw EMPTY_LIST;
    return front->item;  
}
void QUEUE::del()
{
    if(front==NULL)
      throw EMPTY_LIST;
    if(front==rear)
    {
     delete front;
     front=NULL;
     rear=NULL;
    }
    else
    {
        node* t=front;
        front=front->next;
        delete t;
    }
}
QUEUE::~QUEUE()
{
    while(front)
      del();
}
QUEUE::QUEUE(QUEUE& q)
{
    front=rear=NULL;
    node *t;
    t=q.front;
    while(t!=NULL)
    {
        insert(t->item);
        t=t->next;
    }
}
QUEUE& QUEUE::operator=(QUEUE& q)
{
    while(front)
      del();
    front=rear=NULL;
    node *t;
    t=q.front;
    while(t!=NULL)
    {
        insert(t->item);
        t=t->next;
    }
    return *this;
}
int QUEUE::count()
{
    node *t;
    int c=0;
    t=front;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}