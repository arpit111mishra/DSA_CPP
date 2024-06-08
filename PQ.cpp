//using SLL
#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_QUEUE 1
struct node
{
    int item;
    node* next;
    int pno;
};
class PQ
{
node *start;
public:
PQ();
void insert(int,int);
void del();
int getItem();
int getHigestPriority();
bool isEMpty();
~PQ();
PQ(PQ&);
PQ& operator=(PQ&);
};
PQ::PQ(){
start=NULL;
}
void PQ::insert(int p,int data)
{
    node *n=new node;
    n->item=data;
    n->pno=p;
    node*t;
    if(start==NULL||start->pno<n->pno)
    {
        n->next=start;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
          {
            if(t->next->pno<n->pno)
               break;
            t=t->next;   
          }
        n->next=t->next;
        t->next=n;
    }
}
void PQ::del()
{
    node *t;
    if(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
int PQ::getItem()
{
    if(start)
      return start->item;
    throw EMPTY_QUEUE;  
}
int PQ::getHigestPriority()
{
    if(start)
      return start->pno;
    throw EMPTY_QUEUE;  
}
PQ::~PQ()
{
    while(start)
      del();
}
bool PQ::isEMpty()
{
    return start==NULL;
}
PQ::PQ(PQ& p)
{
    node *t;
    start=NULL;
    if(p.start)
    {
        t=p.start;
        while(t!=NULL)
        {
            insert(t->pno,t->item);
            t=t->next;
        }
    }
}
PQ& PQ::operator=(PQ& p)
{
    while(start)
      del();
    node *t;
    start=NULL;
    if(p.start)
    {
        t=p.start;
        while(t!=NULL)
        {
            insert(t->pno,t->item);
            t=t->next;
        }
    }
    return *this;
}