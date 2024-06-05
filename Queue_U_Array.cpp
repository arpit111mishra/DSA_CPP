#include<iostream>
#include<stdio.h>
using namespace std;
#define INVALID_QUEUE_STATE 1
#define OVERFLOW 2
#define UNDERFLOW 3
class QUEUE
{
    private:
    int capacity;
    int front,rear;
    int *ptr;
    public:
    QUEUE(int);
    void insert(int);
    int getFront();
    int getBack();
    bool isFull();
    bool isEmpty();
    void del();
    ~QUEUE();
    int count();
    QUEUE(QUEUE&);
    QUEUE& operator=(QUEUE&);
};
QUEUE::QUEUE(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    if(cap>0)
      ptr=new int[cap];
    else
     ptr=NULL;  
}
bool QUEUE::isEmpty()
{
  return (front==0&&rear==capacity-1||rear+1==front);
}
void QUEUE::insert(int data)
{
    if(capacity<=0)
       throw INVALID_QUEUE_STATE;
    if(isFull())
      throw OVERFLOW;
    if(rear==-1)     //WHEN QUEUE IS EMPTY
    {
    rear=front=0;
    ptr[rear]=data;
    }     
    else if (rear==capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
bool QUEUE::isEmpty()
{
    return front==-1;
}
int QUEUE::getFront()
{
  if(isEmpty())
    throw UNDERFLOW;
  return ptr[front];
}
int QUEUE::getBack()
{
  if(isEmpty())
    throw UNDERFLOW;
  return ptr[rear];  
}
void QUEUE::del()
{
  if(isEmpty())
    throw UNDERFLOW;
  if(front==rear)
    front=rear=-1;
  else if(front=capacity-1)
    front=0;
  else
  front++;    
}
QUEUE::~QUEUE()
{
  delete []ptr;
}
int QUEUE::count()
{
  if(front==-1)
    return 0;
  if(front==rear)
    return 1;
  if(rear>front)
    return rear-front+1;
  else
    return capacity-front+rear+1;     
}
QUEUE::QUEUE(QUEUE& q)
{
  capacity=q.capacity;
  front=q.front;
  rear=q.rear;
  ptr=new int[capacity];
  for(int i=0;i<capacity;i++)
    ptr[i]=q.ptr[i];
}
QUEUE& QUEUE::operator=(QUEUE& q)
{
  if(ptr)
    delete[]ptr;
  capacity=q.capacity;
  front=q.front;
  rear=q.rear;
  ptr=new int[capacity];
  for(int i=0;i<capacity;i++)
    ptr[i]=q.ptr[i];
    return *this;
}