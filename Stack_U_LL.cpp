#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_STACK 1
struct node
{
    int item;
    node *next;
};
class Stack
{
    node *top;
    public:
    Stack();
    void push(int);
    int peek();
    void pop();
    ~Stack();
    void reverse();
    Stack(Stack&);
    Stack& operator=(Stack&);
};
Stack::Stack()
{
    top=NULL;
}
void Stack::push(int data)
{
    node *n;
    n=new node;
    n->item=data;
    n->next=top;
    top=n;
}
int Stack::peek()
{

    if(top==NULL)
      throw EMPTY_STACK;
    return top->item;  
}
void Stack::pop()
{
    node *r;
    if(top!=NULL)
    {
        r=top;
        top=top->next;
        delete r;
    }
}
Stack::~Stack()
{
    while(top)
      pop();
}
void Stack::reverse()
{
    Stack S1;
    while(top)
    {
        S1.push(peek());
        pop();
    }
    top=S1.top;
    S1.top=NULL;
}
Stack::Stack(Stack& s)
{
    node* t;
    s.reverse();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reverse();
}
Stack& Stack::operator=(Stack& s)
{
    if(top!=NULL)
    {
       while(top)
         pop();
    }     
    node* t;
    s.reverse();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reverse();
    return *this;
}