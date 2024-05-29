/*dynamic array means which can grow  */
#include<iostream>
#include<stdio.h>
using namespace std;
class Array{
private:
int capacity;
int lastIndex;
int *ptr;
public:
void createArray(int);
void append(int);
void insert(int,int);
bool isFull();
bool isEmpty();
void edit(int,int);
int getItem(int);
int getCapacity();
void del(int);
Array();
Array(Array&);
Array& operator=(Array&); 
~Array();
void doubleArray();
void display();
};
void Array::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
    {
        delete []ptr;
    }
    ptr =new int[capacity];
}
Array::Array()
{
    ptr=NULL;
}
void Array::append(int data)
{   
    if(isFull())
    {
       doubleArray();
    }
        lastIndex++;
        ptr[lastIndex]=data;
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
        doubleArray();
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
    cout<<" invalid index ";
}
}
}
int Array::getItem(int index)
{  try
{
    if(index<0||index>lastIndex)
    throw 1;
    return ptr[index];
}
       catch(int e)
{
if(e==1)
{
    cout<<" invalid index ";
}
}
return -1;
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
        cout<<" Invalid index ";
    }
  }
}
int Array::getCapacity()
{
    return capacity;
}
void Array::del(int index)
{
     try{
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
cout<<" invaid index number ";
}
}
Array::~Array()
{
    delete []ptr;
}
Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
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
void Array::display()
{
    for(int i=0;i<=lastIndex;i++)
    cout<<ptr[i];
}
void Array::doubleArray()
{   
    int *temp;
    capacity = capacity * 2;
    temp =new int[capacity];
    for(int i=0;i<=lastIndex;i++)
     temp[i]=ptr[i];
     delete []ptr;
      ptr=temp;
}
