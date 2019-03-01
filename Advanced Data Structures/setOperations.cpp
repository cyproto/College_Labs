#include <iostream>
using namespace std;
int main()
{
	int acnt,bcnt;
	cout<<"\nEnter number of elements for set A: \n";
	cin>>acnt;
	cout<<"\nEnter number of elements for set B: \n";
	cin>>bcnt;
	int a[acnt],b[bcnt],c[30],i,m=0,ch,f=0,j;
	int k=0;
	int q;
	cout<<"\nEnter elements for set A: \n";
	for(i=0;i<acnt;i++)
	{	
		cin>>a[i];
	}
	cout<<"\nEnter elements for set B: \n";
	for(i=0;i<bcnt;i++)
	{	
		cin>>b[i];
	}
	do
	{
		cout<<"\n\n1. A union B.        (A U B)\n2. A intersection B. (A n B)\n3. A minus B.        (A - B)\n4. B minus A.        (B - A)\n5. Symmetric difference. \n6. Exit.\nEnter choice: \n";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				k=0;
				cout<<"\nA union B is: ";
				for(i=0;i<acnt;i++)
				{	
					c[k]=a[i];
					k++;
				}
				for(i=0;i<bcnt;i++)
				{	
					f=0;
					for(j=0;j<acnt;j++)
					{
						if(a[j]==b[i])
						{	
							f=0;
							break;
						}
						else 
						{
							f=1;					
						}
					}
					if(f==1)
					{
						c[k]=b[i];
						k++;			
					}
				}
				m=k;
				for(k=0;k<m;k++)
				{
					cout<<c[k]<<"\t";
				}			
				break;
	
			case 2:
				cout<<"Intersection of A & B is: ";
				for(i=0;i<acnt;i++)
				{
					for(j=0;j<bcnt;j++)
					{
						if(a[i]==b[j])
						{
							f=b[j];
							cout<<f<<"\t";				
						}
					}
				}
				break;
				
			case 3:
				cout<<"\nA minus B: ";
				for(i=0;i<acnt;i++)
				{
					f=1;
					for(j=0;j<bcnt;j++)
					{
						if(a[i]==b[j])
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						cout<<a[i]<<"\t";
					}			
				}	
				break;
				
			case 4:
				cout<<"\nB minus A: ";
				for(i=0;i<bcnt;i++)
				{
					f=1;
					for(j=0;j<acnt;j++)
					{
						if(b[i]==a[j])
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						cout<<b[i]<<"\t";
						
					}
				}
				break;
				
			case 5:
				cout<<"\nSymmetric difference is: ";
				for(i=0;i<acnt;i++)
				{
					f=1;
					for(j=0;j<bcnt;j++)
					{
						if(a[i]==b[j])
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						cout<<a[i]<<"\t";
					}			
				}	
				for(i=0;i<bcnt;i++)
				{
					f=1;
					for(j=0;j<acnt;j++)
					{
						if(b[i]==a[j])
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						cout<<b[i]<<"\t";
						
					}
				}
				break;
			
			case 6:
				cout<<"\nExiting...";
				break;
		
			default:
				cout<<"\nInvalid. Enter again.";	
			
		}	
	}while(ch!=6);
 return 0;		
}	
