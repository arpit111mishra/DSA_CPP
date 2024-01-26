//singly Linked list 
#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
int item;
node *next;
};
class SLL
{
    private:
    node *start;
    public:
    void insertAtStart(int);
    void insertAtLast(int);
    void insertAfter(node *,int);
    node* search(int);
    void deleteFirst();
    void deleteLast();
    void deletenode(node *);
    SLL();
    ~SLL();
    SLL(SLL&);//copy constructor
    SLL& operator=(SLL&);
};
SLL::SLL()
{
    start=NULL;
}
void SLL::insertAtStart(int data)
{
  node *n=new node;
  n->item=data;
  n->next=start;
  start=n;
}
void SLL::insertAtLast(int data)
{
  node *t;
 node *n=new node;
 n->item=data;
 n->next=NULL;
  if(start==NULL)
  {
    start=n;
  }
  else{
    t=start;
 while(t->next!=NULL)
 {
    t=t->next;
}
t->next=n;
  }
}
void SLL::insertAfter(node *t,int data)
{
if(t)   //if t is not NULL  only then loop will executed
{
  node *n=new node;
  n->item=data;
  n->next=t->next;
  t->next=n;
}
}
node * SLL::search(int data)
{
  node *t;
  t=start;
  while(t)
  {
    if(t->item==data)
    {
      return t;
    }
    t=t->next;
  }
  return NULL;
} 
void SLL::deleteFirst()
{ 
  node *t;
  if(start)
  {
     t=start;
     start=t->next;
     delete t;
  }
}
void SLL::deleteLast()
{
  node *t;
  try
  {
    if(start==NULL)
     throw 1;
     if(start->next==NULL)
     {
      delete start;
      start=NULL;
     }
     else{
      t=start;
      while(t->next->next!=NULL)  //third last
      {
       t=t->next;  //second last jo last ban gaya ab
      }
      delete t->next;  //last wala delete
     }
  }
  catch(int e)
  {
   cout<<"empty";
  }
  }
  void SLL::deletenode(node *t)
  {
    node *r;
    try
    {
      if(start==NULL)
       throw 1;
       if(start==t)
       {
         deleteFirst();
       }
       else
       {
        r=start;
        while ((r->next!=t))
        {
          r=r->next;
        }
        r->next=t->next;
        delete t;
       }
    }
    catch(int e)
    {
      cout<<"Empty";
    }
   }
   SLL::~SLL()
   {
    while(start)
    {
      deleteFirst();
    }
   }
SLL::SLL(SLL& list)            //copy constructor (deep copy)
{
  node *t;
  t=list.start;   //list calling object .
  start=NULL;     //jo objecet parameter mai pass hua hoga uska start.
  while(t)
  {
     insertAtLast(t->item);
     t=t->next;   
  }
}
