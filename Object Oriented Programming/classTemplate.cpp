#include<iostream>
using namespace std;
template <class T>
void select_sort(T a[],int n)
{
     int i,j;
	T t;
     for(i=0;i<n;i++)
     {
       for(j=i+1;j<n;j++)
       {
          if(a[j]<a[i]) 
          {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
          }
       }
     }
}
int main()
{
   int ch;
   do
   {
   cout<<"\n-------------------------------------------------------";
   cout<<"\nSelection sort (int,float) using templates"<<endl;    
   cout<<"1. Enter integer values"<<endl;
   cout<<"2. Enter floating point values"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<"Choice:";
   cout<<"\n-------------------------------------------------------\n";
   cin>>ch;
   cout<<"---------------------------------------------------------";
   switch(ch)
  {
    case 1:
           int a[100],i,n;
           cout<<"\nEnter no. of elements: ";
           cin>>n;
           cout<<"\nEnter elements: \n";
           for(i=0;i<n;i++)
           {
              cout<<"\n";
              cin>>a[i];
           }
           select_sort(a,n);
           cout<<"\n-------------------------------------------------------";
           cout<<"\nAfter Sorting: \n";
           for(i=0;i<n;i++)
           {
       	cout<<a[i]<<"\t";
           }
           cout<<"\n-------------------------------------------------------";
           break;
   case 2:
           float b[100];
           cout<<"\nEnter no. of elements:";
           cin>>n;
           cout<<"\nEnter elements: \n";
           for(i=0;i<n;i++)
           {
             cout<<"\n";
             cin>>b[i];
           }
           select_sort(b,n);
           cout<<"\n-------------------------------------------------------";
           cout<<"\nAfter Sorting: \n";
           for(i=0;i<n;i++)
           {
             cout<<b[i]<<"\t";
           }
           cout<<"\n-------------------------------------------------------";
           break;
 case 3:
        cout<<"\nExiting..."<<endl;		
   }
}while(ch!=3);
    return 0;
}
