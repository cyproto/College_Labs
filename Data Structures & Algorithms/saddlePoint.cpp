#include <iostream>
#include <string.h>
#define size 10
using namespace std;

class saddle
{
   public:
   int ctem,rtem,rw,cl,a[size][size];
   void reada();
   void readb();
   void imp();
   void display();
	saddle()
   {
		rw=0;
		cl=0;
   }
};

void saddle::reada()
{
   cout<<"\nEnter the number of rows and columns:\n";
   cin>>rw;
   cin>>cl;
   int i,j;
   for(i=0;i<rw;i++)
   {
      for(j=0;j<cl;j++)
      {
          cout<<"Enter value for "<<i<<" row and "<<j<<" column\t:";
          cin>>a[i][j];
      }
   }
   return;
}

void saddle::imp()
{
	if(rw==0&&cl==0)
	{
		cout<<"\nEnter a matrix first.";
		reada();
	}
	else
	{
		int i,j,k,flag,sp,pos=0;
   		for(i=0;i<rw;i++)
   		{
	   		flag=1;
	   		sp=a[i][0];
   			for(j=0;j<cl;j++)
   			{
	    		if(a[i][j]<sp)
	     		{ 
		     		sp=a[i][j];
		     		pos=j;
		     	}
	   		}
	   		for(k=0;k<3;k++)
	   		{
				if(a[k][pos]>sp)
		      	{
		        	flag=0;
		        	break;
		      	}
	   		}
	   		if(flag==1)
	   		{
		     	cout<<"\nThe saddle point of row "<<i+1<<" is "<<sp<<endl;
		   	}
		   	else
		   	{
		     	cout<<"No saddle point for row "<<i+1;
			}
		}
	}
}

void saddle::display()
{
   int i,j;
   for(i=0;i<rw;i++)
   {
     	cout<<"\n";
     	for(j=0;j<cl;j++)
     	{
	        cout<<a[i][j]<<"\t";
   		}
   }
}

int main()
{
   saddle s;
   int ch;
   char z[10];
   do
   {
   cout<<"\n\nMenu:";
   cout<<"\n1.Enter data.";
   cout<<"\n2.Show saddle point.";
   cout<<"\n3.Display entered data.";
   cout<<"\n4.Exit.";
   cout<<"\nEnter choice: ";
   cin>>ch;
   switch(ch)
   {
     	case 1:
     		s.reada();
     		s.display();
     		break;     
     	case 2:
     		s.imp();
     		break;
     	case 3:
     		s.display();
     		break;
     	case 4:
     		cout<<"\nExiting...";
     		break;
     	default:
     		cout<<"\nInvalid Choice.";
   }
   }while(ch!=4);
}
