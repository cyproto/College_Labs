#include<iostream>
#define MAX 10
using namespace std;
class Hash
{
	private:	
			struct node
			{
				int ID;
				char name[50],mobile[12];
				node *next;
			}*temp,*head[MAX];
	public:
			Hash()
			{
				for(int i=0;i<MAX;i++)
					head[i]=NULL;
			}
			void create();
			void display();
			void search();
};
void Hash::create()
{
	char ch;
	int key;
	node *New;
	do
	{
		New = new node();
		cout<<"\nEnter client ID : ";
		cin>>New->ID;
		cout<<"\nEnter client name : ";
		cin>>New->name;
		cout<<"\nEnter client mobile number: ";
		cin>>New->mobile;
		New->next=NULL;
		key = (New->ID % MAX);
		if(head[key] == NULL)
		{
			head[key]=New;
		}
		else
		{
			temp = head[key];
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = New;	
		}
		cout<<"\nEnter more clients?(Y|y or N|n) \n";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
}

void Hash::display()
{
	int i,j;
	cout<<"\nHash Table: ";
	for(i=0 ; i<MAX ; i++)
	{		
		cout<<"\n Hash["<<i<<"] --> ";
		temp = head[i];
		while(temp != NULL)
		{
			cout<<"{"<<temp->ID<<","<<temp->name<<","<<temp->mobile<<"} --> ";
			temp=temp->next;
		}
		cout<<"NULL";
	}	
}

void Hash::search()
{
	int ID,key,flag=0;
	cout<<"\nEnter client ID: ";
	cin>>ID;
	key = (ID % MAX);
	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(temp->ID == ID)
			{
				cout<<"\nClient info: \nName:  "<<temp->name;	
				cout<<"\nMobile No.: "<<temp->mobile<<"\n";
				flag=1;	
			}
			temp = temp->next;
		}
	}
	if(flag==0)
	{
		cout<<"\nNo client with ID: "<<ID<<endl;
	}
}
int main()
{
	Hash hash;
	int ch;	
	do
	{
		cout<<"\n\n1. Create|Insert \n2. Display \n3. Search \n4. Exit \nEnter choice: \n";
		cin>>ch;
		switch(ch)
		{
			case 1:
					hash.create();
					break;
					
			case 2:
					hash.display();
					break;
					
			case 3:
					hash.search();
					break;
					
			case 4:
					cout<"\nExiting...";
					break;
					
			default:
					cout<<"\nInvalid choice...";			
		}
	
	}while(ch != 4);
}
