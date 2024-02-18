//bubble sort---compare and swap
#include<iostream>
using namespace std;
void bubble_sort(int [],int);
int  main()
{
    int size;
    cout<<"enter size of array "<<endl;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
{
    cin>>a[i];
}
    bubble_sort(a,size);
    
    return 0;
}

void bubble_sort(int a[],int n)
{
    int round,i,temp;
    for(round=1;round=n-1;round++)
    {
        for(i=0;i<n-1-round;i++)
        {
            if(a[i]>a[i+1])
            {
              temp=a[i];
              a[i]=a[i+1];
              a[i+1]=temp;
            }
        }
    }
}