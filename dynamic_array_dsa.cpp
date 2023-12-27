/*dynamic array means which can grrow and shrick */
#include<iostream>
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
int getItem();
int getCapacity();
void del();
Array();
~Array();

};