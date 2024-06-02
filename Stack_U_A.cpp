#include<iostream>
#include<stdio.h>
using namespace std;
#define STACK_IS_EMPTY 1
class Stack{
private:
int capacity;
int top;
int *ptr;
public:
Stack();
Stack(int);
void createStack(int);
void push(int);
bool isFull();
bool isEmpty();
int peek();    //to see top element
void pop();
~Stack();
Stack(Stack&);
Stack& operator=(Stack&);
};
Stack::Stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
void Stack::createStack(int cap)
{
    if(ptr!=NULL)
      delete[] ptr;
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
Stack::Stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
void Stack::push(int data)
{
    if(isFull())
      cout<<"Stack overflow"<<endl;
    else
    {
        top++;
        ptr[top]=data;
}  
}
bool Stack::isFull()
{
    return top==capacity-1;
}
bool Stack::isEmpty()
{
    return top==-1;
}
int Stack::peek()
{
    if(isEmpty())
      throw STACK_IS_EMPTY;
    return ptr[top];  
}  
void Stack::pop()
{
    if(isEmpty())
      cout<<"Stack is empty"<<endl;
    else
    {
        top--;
    }
}
Stack::~Stack()
{
    if(ptr!=NULL)
      delete []ptr;
}
Stack::Stack(Stack& s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
      ptr[i]=s.ptr[i];
}
Stack& Stack::operator=(Stack& s)
{
    if(ptr!=NULL)
      delete []ptr;
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
      ptr[i]=s.ptr[i];
    return *this;    
}