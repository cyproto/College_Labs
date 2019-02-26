#include<iostream>
using namespace std;
#define MAX 20
class sort
{
	float per[MAX];
	int n,flag;
	public:
	void accept();
	void display();
	void insertionSort(sort s);
	void shellSort(sort s);
	void displayTop5();
	sort()
	{
		n=0;
		flag=0;
	}
};

void sort::accept()
{
	cout<<"\nEnter Number of Students: "<<endl;
	cin>>n;
	cout<<"\nEnter percentages of "<<n<<" students: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>per[i];
	}
}
void sort::display()
{
	cout<<"% list:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"  "<<per[i]<<endl;
	}
}
void sort::displayTop5()
{
	int c;
	if(n!=5)
	{
		cout<<"\nEnter atleast 5 values to get top 5.";
		accept();
	}
	else if(flag!=1)
	{
		cout<<"\nFirst use any sorting algorithm to sort the values.";
		return;
	}
	else
	{	
		cout<<"Top 5 % are:"<<endl;
		for(int i=n-1,c=0;i>=0 && c<5; i--,c++)
		{
			cout<<c+1<<")"<<per[i]<<""<<endl;
		}
	}
}
void  sort::insertionSort(sort s)
{
	if(n==0)
	{
		cout<<"\nEnter some elements to sort & enter the sorting algo again.";
		accept();
	}
	else
	{
		cout<<"Before Sorting: "<<endl;
		s.display();
		cout<<"After Sorting: "<<endl;	
		int i,j;
		for(int i=1;i<n;i++)
		{
			float temp=per[i];
			for(j=i-1;j>=0 && per[j]>temp;j--)
			{
				per[j+1]=per[j];
			}
			per[j+1]=temp;
		}
	cout<<"Sorted List is: "<<endl;
	display();
	flag=1;
	}
}

void sort::shellSort(sort s)
{
	if(n==0)
	{
		cout<<"\nEnter some elements to sort & enter the sorting algo again.";
		accept();
	}
	else
	{
		cout<<"Before Sorting: "<<endl;
		s.display();
		cout<<"After Sorting: "<<endl;
		int i,j,k;
		float temp;
		for(int i=n/2;i>0;i=i/2)
		{
			for(j=i;j<n;j++)
			{
				temp=per[j];
				for(k=j-1;k>=0 && per[k]>temp;k--)
				{
					per[k+1]=per[k];
				}
			per[k+1]=temp;
			}	
		}
	cout<<"Sorted List is: "<<endl;
	display();
	flag=1;
	}
}

int main()
{
	sort s;
	int choice,num;
	char ch;
	do
	{
		cout<<"\n----------------------------\n";
		cout<<"Menu:"<<endl;
        cout<<"------------------------------"<<endl;
		cout<<"1.Enter values."<<endl;
		cout<<"2.Insertion sort."<<endl;
		cout<<"3.Shell sort."<<endl;
		cout<<"4.Display top 5 values."<<endl;
		cout<<"5.Exit."<<endl;
		cout<<"Enter Choice: "<<endl;
		cout<<"------------------------------"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				s.accept();
				break;
				
			case 2:
				s.insertionSort(s);
				break;
				
			case 3:
				s.shellSort(s);
				break;
				
			case 4: 
				s.displayTop5();
				break;
			
			case 5:
				exit(0);
				break;
				
		   	default: 
	              cout<<"Invalid choice"<<endl;
	    }
   }while(choice!=5);

	return 0;
}
