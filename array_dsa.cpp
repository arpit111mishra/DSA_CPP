#include<iostream>
#include<stdio.h>
using namespace std;
class Array
{
private:
int capacity;
int lastIndex;
int *ptr;
public:
void createArray(int);
void insert(int,int);
void append(int);
int getItem(int);
bool isEmpty();
bool isFull();
void del(int);
void edit(int,int);
int count();
int getCapacity();
void display();
Array(Array&);
Array& operator=(Array&);
Array();
~Array();
};
Array::Array()
{
 ptr=NULL;
}
void Array::createArray(int cap)
{     capacity=cap;
      lastIndex=-1;
      if(ptr!=NULL)
      {
       delete []ptr;
      }
      ptr=new int[capacity];
}
void Array::append(int a)
{  
       if(!isFull())
       {
         lastIndex++;
         ptr[lastIndex]=a;
       }
       else
       {
              cout<<" overflow ";
       }
}
bool Array::isFull()
{
       return (lastIndex==capacity-1);
}
bool Array::isEmpty()
{
       return (lastIndex==-1);
}
void Array::insert(int index,int data)
{
       try{
       if(index<0||index>lastIndex+1)
              throw 1;
              if(isFull())
              throw 2;
              for(int i=lastIndex;i>=index;i--)
              { 
                   ptr[i+1]=ptr[i];
              }
              ptr[index]=data;
              lastIndex++;
}
       catch(int e)
       {
           if(e==1)
           {
               cout<<"Invalid Index :";
           }
           else if(e==2)
           {
              cout<<" Overflow ";
           }
       }
}
int Array::getItem(int index)
{   try
           {
         if(index<0||index>lastIndex)
         throw 1;
         return ptr[index];      
}
catch(int e)
{
   if(e==1)
   {
       cout<<"invalid index or Array is empty ";
   }
}
return -1;
}
int Array::count()
{
       return (lastIndex+1);
}
void Array::del(int index)
{  try{
       if(index<0||index>lastIndex)
       throw 1;
       for(int i=index;i<lastIndex;i++)
       {
              ptr[i]=ptr[i+1];
       }
       lastIndex--;
}
catch(int e)
{
       if(e==1)
       {
              cout<<" Invalid index or Underflow ";
       }

}
}
void Array::edit(int index,int newdata)
{
       try{
  if(index<0||index>lastIndex)
               throw 1;
           ptr[index]=newdata;
       }
       catch(int e)
       {
              if(e==1)
              {
                     cout<<" Invalid index or Underflow ";
              }
       }
}
int Array::getCapacity()
{
       return capacity;
}
void Array::display()
{           
       try{
       if(isEmpty())
       throw 1;
       for(int i=0;i<=lastIndex;i++)
       {
              cout<<ptr[i];
       }
}
catch(int e)
{
       if(e==1)
       cout<<" Array is empty ";
}
}
Array::~Array()
{
       delete []ptr;
}
Array::Array(Array& arr)
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
   ptr =new int[capacity];
   for(int i=0;i<=lastIndex;i++)
     ptr[i]=arr.ptr[i];
}
Array& Array::operator=(Array& arr)
{
 capacity=arr.capacity;
   lastIndex=arr.lastIndex;
    if(ptr!=NULL)
    {
       delete []ptr;
    }
   ptr =new int[capacity];
   for(int i=0;i<=lastIndex;i++)
     ptr[i]=arr.ptr[i];
     return (*this);
}