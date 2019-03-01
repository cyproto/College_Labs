#include<iostream>
#include<string.h>
using namespace std;
class BST
{
	struct node
	{
		char word[50], mean[50];	
		node * left;
		node * right;		
	}*root,*temp,*parent,*temp_successor;

	public:
			BST()
			{
				root=NULL;
			}
			void insert();
			void add(node *, node *);
			void display();
			void inorder(node *);	
			void postorder(node *);		
			void search();
			void deleter();
			void update();
};
void BST::insert()
{
	char ans;
	do
	{	node *New;
		New = new node;		
		cout<<"\nEnter word : ";
		cin>>New->word;
		cout<<"\nEnter meaning : ";
		cin>>New->mean;
		New->left = NULL;
		New->right = NULL;

		if(root == NULL)
			root = New;
		else
			add(root,New);

		cout<<"Add more nodes? (Y|y or N|n): ";
		cin>>ans;
	}while(ans == 'y' || ans == 'Y');
}
void BST::add(node * temp, node * New)
{


	if(strcmp(New->word , temp->word) == 0)
	{
		cout<<"\nWord already exists.";
		return;
	}
	if(strcmp(New->word , temp->word) == 1)
	{
		if(temp->right == NULL)
			temp->right = New;
		else
			add(temp->right, New);
	}
	else
	{
		if(temp->left == NULL)
			temp->left = New;
		else
			add(temp->left, New);
	}
}
void BST::display()
{
	if(root == NULL)
		cout<<"Dictionary is empty.";
	else
	{	int ans;
		do
		{	cout<<"\n1. Ascending. \n2. Descending. \n3. Back to main menu. \nEnter choice : ";
			cin>>ans;
			
			switch(ans)
			{
				case 0:
						break;
				case 1:
						inorder(root);
						break;
				case 2:
						postorder(root);
						break;
				default:
						cout<<"Invalid choice.";
			}

		}while(ans != 3);
	}
}
void BST::inorder(node * temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<"\nWord: "<<temp->word<<"\tMeaning: "<<temp->mean;
		inorder(temp->right);
	}
}

void BST::postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<"\nWord: "<<temp->word<<"\tMeaning: "<<temp->mean;
	}
}

void BST::search()
{
	if(root == NULL)
	{
		cout<<"Dictionary is Empty.";	
	}else
	{		
		int flag=0,cmp=0;
		char search[50];
		cout<<"Enter word to be searched: ";		
		cin>>search;
			temp = root;
			while(temp != NULL)
			{
				if(strcmp(search , temp->word) == (-1))
				{	cmp++;
					temp = temp->left;
				}
				else if(strcmp(search , temp->word) == 1)
				{	cmp++;
					temp = temp->right;				
				}
				else if(strcmp(search , temp->word) == 0)
				{	cmp++;
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				cout<<"Word found.\nMeaning :: "<<temp->mean<<"\nComparisons required :: "<<cmp;		
			}else
			{
				cout<<"Word Not found.";
			}			
	}
}
void BST::deleter()
{
	if(root == NULL)
	{
		cout<<"\nDictionary is empty.";
	}
	else
	{	temp = root;
		parent = root;
		int flag = 0;
		char del_word[50];
		
		cout<<"\nEnter word to be deleted: ";
		cin>>del_word;
					
		while(temp != NULL)
		{
			if(strcmp(temp->word,del_word) == 0)
			{
				if(temp->right == NULL && temp->left == NULL)
				{
					cout<<"Parent --> "<<parent->word;
					if(parent->left == temp)
						parent->left = NULL;
					else
						parent->right = NULL;	
				}				
				if(temp->left != NULL && temp->right == NULL)
				{
					if(parent->left == temp)
						parent->left = temp->left;
					else
						parent->right = temp->left;
				}				
				if(temp->left == NULL && temp->right != NULL)
				{
					if(parent->left == temp)
						parent->left = temp->right;
					else
						parent->right = temp->right;
				}
				if(temp->left != NULL && temp->right != NULL)
				{
					parent = temp;
					temp_successor = temp->right;
					while(temp_successor->left != NULL) 
					{	
						parent = temp->right;
						temp_successor = temp_successor->left;
					}
					strcpy(temp->word , temp_successor->word);
					strcpy(temp->mean , temp_successor->mean);
					if(parent->left == temp_successor)
						parent->left = temp_successor->right;
					else
						parent->right = temp_successor->right;
				}
				flag = 1;
			}
			if(strcmp(del_word , temp->word) == 1)
			{
				parent = temp;
				temp = temp->right;
			}
			else
			{
				parent = temp;
				temp = temp->left;
			}
			
		}
		if(flag == 1)
			cout<<"\nWord deleted.";
		else
			cout<<"\nWord not found.";
	}
}
void BST::update()
{
	if(root == NULL)
	{
		cout<<"Dictionary is Empty";	
	}else
	{	int flag=0;
		char search[50];
		cout<<"Enter word to be updated: ";		
		cin>>search;		
			temp = root;
			while(temp != NULL)
			{
				if(strcmp(search , temp->word) == (-1))
				{
					temp = temp->left;
				}
				else if(strcmp(search , temp->word) == 1)
				{
					temp = temp->right;				
				}
				else if(strcmp(search , temp->word) == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				char update[50];
				cout<<"Word found.\nMeaning: "<<temp->mean;
				cout<<"\nEnter new meaning: ";
				cin>>update;
				strcpy(temp->mean , update);
				cout<<"\nMeaning updated.";
		
			}
			else
			{
				cout<<"Word not found.";
			}				
	}
}
int main()
{
	BST bst;
	int ans;
	do
	{
		cout<<"\n1. Add node \n2. Display node \n3. Search \n4. Delete \n5. Update meaning. \n6. Exit \n Enter your choice : ";
		cin>>ans;
		switch(ans)
		{
			case 0:
					break;

			case 1:	bst.insert();			
					break;

			case 2:	bst.display();
					break;
					
			case 3:
					bst.search();
					break;
					
			case 4:
					bst.deleter();
					break;
					
			case 5:
					bst.update();
					break;
			
			case 6:
					cout<<"\nExiting...";
					break;
					
			default:
					cout<<"\nInvalid choice...";
		}

	}while(ans != 6);
}
