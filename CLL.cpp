#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
int item;
node *next;
};
class CLL{
node *last;
public:
CLL();
void insertAtStart(int);
void insertAtLast(int);
void insertAfter(node*,int);
node *search(int);
void deleteFirst();
void deleteLast();
void del(node*);
~CLL();
CLL(CLL&);
CLL& operator=(CLL&);
};
CLL::CLL()
{
 last=NULL;
}
void CLL::insertAtStart(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
    }
}
void CLL::insertAtLast(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
void CLL::insertAfter(node *t,int data)
{
    node* n=new node;
    if(t==last)
    {
        insertAtLast(data);
    }
    else{
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
node * CLL::search(int data)
{
    node *t;
    if(last==NULL)
       return NULL;
    t=last->next;
    while(t!=last)
    {
        if(t->item==data)
           return t;
        t=t->next;   
    }   
    if(last->item==data)
      return last;
    return last;  
}
void CLL::deleteFirst()
{
    node *r;
    if(last)
    {
        r=last->next;
        if(last==r)
           last=NULL;
        delete r;   
    }
}
void CLL::deleteLast()
{
node *r,*t;
if(last)
{
r=last;
if(r->next==r)
   last=NULL;   
else
{
t=last->next;
while(t->next!=last)
  t=t->next;
t->next=last->next;
last=t;  
}
delete r;
}
}
void CLL::del(node *t)
{
    node *r;
    if(t!=NULL)
    {
        if(t==last)
          deleteLast();
        else if(t==last->next)
          deleteFirst();
        else
        {
            r=last->next;
            while(r->next!=t)
              r=r->next;
            r->next=t->next;
            delete t;  
        }    
        }
}
CLL::~CLL()
{
    while(last)
     deleteFirst();
}
CLL::CLL(CLL& C)
{
    node *t;
    if(C.last==NULL)
      last=NULL;
    else
    {
        t=C.last->next;
        while(t!=C.last)
        {
         insertAtLast(t->item);
         t=t->next;
        }
    insertAtLast(last->item);
    }  
}
CLL& CLL::operator=(CLL& C)
{
    while(last)
      deleteFirst();
    node *t;
    if(C.last==NULL)
      last=NULL;
    else
    {
        t=C.last->next;
        while(t!=C.last)
        {
         insertAtLast(t->item);
         t=t->next;
        }
    insertAtLast(last->item);
    }  
    return *this;
}
