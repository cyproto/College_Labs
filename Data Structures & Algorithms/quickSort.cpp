#include<iostream>
using namespace std;
#define MAX 20

class sort
{
	float per[MAX];
	int n, flag;
	public:
	void accept();
	void display();
	void quickSort(int start,int end);
	void displayTop5();
	sort()
	{
		flag=0;
		n=0;
	}
	int getn()
	{
		return n;
	}
};

void sort::accept()
{
	cout<<"\nEnter Number of Students: "<<endl;
	cin>>n;
	cout<<"\nEnter % of "<<n<<" students: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>per[i];
	}
	return;
}
void sort::display()
{
	cout<<"Student List:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<per[i]<<" "<<endl;
	}
}

void sort::quickSort(int start,int end)
{
	int pivot,i,j;
	float temp;
	if(start<end)
	{
		pivot=start;
		i=start+1;
		j=end;

		while(i<j)
		{

			while(per[i]<=per[pivot] && i<j)
				i++;
			while(per[j]>=per[pivot] && i<=j)
				j--;
			if(i<=j)
			{
				temp=per[i];
				per[i]=per[j];
				per[j]=temp;
			}
		}
		temp=per[pivot];
		per[pivot]=per[j];
		per[j]=temp;

		quickSort(start,j-1);
		quickSort(j+1,end);
	}
	flag=1;
}

void sort::displayTop5()
{
	if(flag==0)
	{
		cout<<"\nUse sorting algorithm to sort the list.";
	}
	else
	{
		int c;
		for(int i=n-1,c=0;i>=0 && c<5; i--,c++)
		{
			cout<<c+1<<") "<<per[i]<<endl;
		}
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
        cout<<"----------------------------"<<endl;
		cout<<"1.Accept percentages"<<endl;
		cout<<"2.Quick Sort"<<endl;
		cout<<"3.Display Top 5"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter Choice: "<<endl;
		cout<<"----------------------------"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				s.accept();
				break;
				
			case 2:
				num=s.getn();
				if(num==0)
				{
					cout<<"Enter values to sort.";
					s.accept();
				}
				else
				{
					cout<<"Before Sorting: "<<endl;
					s.display();
					cout<<"After Sorting: "<<endl;
					s.quickSort(0,num-1);
					s.display();	
				}
				break;
			
			case 3: 
				num=s.getn();
				if(num>=5)
				{
					cout<<"\nTop 5 values are:"<<endl;
					s.displayTop5();
				}
				else
				{
					cout<<"\nEnter atleast 5 values.";
					s.accept();
				}
				break;
			
			case 4:
				exit(0);
				
			default: 
              cout<<"Invalid choice"<<endl;
    	}
   }while(choice!=4);   	
return 0;
}
