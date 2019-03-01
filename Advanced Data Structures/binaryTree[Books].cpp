# include <iostream>
using namespace std;
class node
{
	char label[10];
	int ch_count,sub_count;
	struct node *child[10];
	node()
	{	
		ch_count=0;
		sub_count=0;
	}
friend class BT;
};

class BT
{
	
	public:
		node *root;
		int flag;
		void create_tree();
		void display(node * r1);
		BT()
		{
			root = NULL;
			flag=0;
		}
};

void BT::create_tree()
{
	int tbooks,tchapters,i,j;
	root = new node();
	cout<<"\nEnter name of book: ";
	cin>>root->label;
	cout<<"\nEnter no. of chapters in book: ";
	cin>>tchapters;
	root->ch_count = tchapters;
	for(i=0;i<tchapters;i++)
	{
		root->child[i] = new node;
		cout<<"\nEnter chapter name: \n";
		cin>>root->child[i]->label;
		cout<<"\nEnter number of sections in chapter "<<root->child[i]->label<<": \n";
		cin>>root->child[i]->ch_count;
		for(j=0;j<root->child[i]->ch_count;j++)
		{
			root->child[i]->child[j] = new node;
			cout<<"\nEnter name for section "<<j+1<<": \n";
			cin>>root->child[i]->child[j]->label;
			cout<<"\nEnter number of subsections: ";
			cin>>root->child[i]->child[j]->sub_count;
		}
	}
	flag=1;
}

void BT::display(node * r1)
{
	
	if(flag==0)
	{
		cout<<"\nNothing to display. Calling create method...\n\n";
		create_tree();
	}
	else
	{
		int i,j,tchapters;
		if(r1 != NULL)
		{
			cout<<"\n*********************************";
			cout<<"\nBook name: ";
			cout<<r1->label;
			cout<<"\n*********************************";
			tchapters = r1->ch_count;
			for(i=0;i<tchapters;i++)
			{
				cout<<"\n---------------------------------";
				cout<<"\n Chapter "<<i+1;
				cout<<". "<<r1->child[i]->label;
				cout<<"\n Sections :";
				for(j=0;j<r1->child[i]->ch_count;j++)
				{
					cout<<"\n---------------------------------";	
					cout<<"\n "<<j+1<<". "<<r1->child[i]->child[j]->label;
					cout<<"\tSub-sections: "<<root->child[i]->child[j]->sub_count;
				}
				cout<<"\n---------------------------------";
			}
		}
	}
}
int main()
{
	int choice;
	BT b;
	do
	{
		cout<<"\n\n-------------------\n";
		cout<<"Menu: \n";
		cout<<"-------------------\n";
		cout<<"1.Create\n";
		cout<<"2.Display\n";
		cout<<"3.Quit";
		cout<<"\nEnter choice : ";
		cout<<"\n-------------------\n";
		cin>>choice;
		cout<<"-------------------\n";
		switch(choice)
		{
			case 1:
				b.create_tree();
				break;
			case 2:
				b.display(b.root);
				break;
			case 3:
				cout<<"\nExiting...";
				break;
			default:
				cout<<"\nInvalid choice"<<endl;
		}
	}while(choice!=3);
}
