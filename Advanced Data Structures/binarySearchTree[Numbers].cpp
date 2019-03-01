#include<iostream>
using namespace std;
class BST
{
	struct node
	{
		int number;
		node * left;
		node * right;		
	} *root, *temp, *stk[10];
	int top, min, max, cnt;
	public:
			int count(node *);
			int height(node * temp);
			int search(int key, node *);
			void insert();
			void add(node *, node *);
			void display();
			void inorder_rec(node *);
			void inorder_nrec(node *);			
			void min_max(node *);			

			node *swapper(node * temp)
			{
				node *p;

				if(temp != NULL)
				{
					p = temp->left;

					temp->left = swapper(temp->right);

					temp->right = swapper(p);
				}
					
				return temp;
			}
			BST()
			{
				top = -1;
				root = NULL;
			}

			int empty()
			{
				if(top == -1)
					return 1;
				else
					return 0;
			}
		
			void push(node *p)
			{
				stk[++top] = p;
			}
			
			node * pop()
			{
				return(stk[top--]);
			} 
};

void BST::insert()
{
	char ans;
	do
	{
		node *New;
		New = new node;
		
		cout<<"\nEnter number : ";
		cin>>New->number;

		New->left = NULL;
		New->right = NULL;

		if(root == NULL)
			root = New;
		else
			add(root,New);

		cout<<"Add more?(Y|y or N|n): ";
		cin>>ans;

	}while(ans == 'y' || ans == 'Y');
}

void BST::add(node * temp, node * New)
{

	if(New->number < temp->number)
	{
		if(temp->left == NULL)
			temp->left = New;
		else
			add(temp->left, New);
	}else
	{
		if(temp->right == NULL)
			temp->right = New;
		else
			add(temp->right, New);
	}
}

void BST::display()
{
	if(root == NULL)
		cout<<"\nTree is empty.";
	else
	{
		int ans,key;
		do
		{	
			cout<<"\n\n1. In-order Recursive \n2. In-order Non-recursive \n3. Count number of nodes \n4. Swapper \n5. Get height of BST. \n6. Get minimum and maximum value. \n7. Search a value. \n8. Back to main menu. \nEnter choice : ";
			cin>>ans;
			cout<<endl;
			switch(ans)
			{
				case 1:
						cout<<"Elements are: ";
						inorder_rec(root);
						break;
						
				case 2:
						cout<<"Elements are: ";
						inorder_nrec(root);
						break;
						
				case 3:
						cout<<"Total no nodes of are : "<<count(root);
						break;
						
				case 4:
						swapper(root);
						cout<<"After swapping, tree is :";
						inorder_rec(root);			
						break;
						
				case 5:
						cout<<"Height of tree is: "<<height(root);
						break;

				case 6:
						min = root->number;	
						max = root->number;						
						min_max(root);
						cout<<"Max: "<<max<<"\t"<<"Min: "<<min;
						break;
				
				case 7:
						int flag;
						cout<<"Enter the number to be searched: ";
						cin>>key;
						cnt=0;
						flag = search(key, root);
						if(flag!=1)
						{
							cout<<"\nElement not found";
						}
						break;
																		
				case 8:
						return;
						
				default:
						cout<<"\nInvalid choice...";
			}

		}while(ans!=0);
	}
}

void BST::inorder_rec(node * temp)
{
	if(temp != NULL)
	{
		inorder_rec(temp->left);
		cout<<"\t"<<temp->number;
		inorder_rec(temp->right);
	}
}

void BST::inorder_nrec(node *temp)
{
	while(temp != NULL)
	{
		push(temp);
		temp = temp->left;
	}
	
	while(!empty())
	{
		temp = pop();
		cout<<"\t"<<temp->number;
		temp = temp->right;
	
		while(temp != NULL)
		{
			push(temp);
			temp = temp->left;
		}
	}
}

int BST::count(node * temp)
{
	if(temp == NULL)
		return 0;

	return (1 + count(temp->left) + count(temp->right));
	
}

int BST::height(node * temp)
{
	int hl,hr;

	if(temp == NULL)
	{
		return 0;
	}
	if(temp -> left == NULL && temp -> right == NULL)
	{
		return 0;
	}

	hl = height(temp->left);
	hr = height(temp->right);

	if(hr < hl)
	{
		return (hl + 1);
	} 
	return (hr + 1);
}

void BST::min_max(node * temp)
{
	if(temp != NULL)
	{
		if(temp->number > max)
			max = temp->number;
		
		if(temp->number < min)
			min = temp->number;

		min_max(temp->right);
		min_max(temp->left);
	}
}

int BST::search(int key,node *temp)
{
	if(temp!=NULL)
	{
		cnt=cnt+1;
		if(key==temp->number)
		{
			cout<<"\nElement found on node number: "<<cnt;
			return 1;
		}
		else
		{
			if(key<temp->number)
			{
				search(key,temp->left);
			}
			else
			{
				search(key, temp->right);
			}
		}
	}
}

int main()
{
	BST bst;
	int ans;
	do
	{
		cout<<"\n1. Add elements \n2. Perform operations \n3. Exit \nEnter choice : ";
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
					cout<<"\nExiting...";
					break;
					
			default:
					cout<<"\nInvalid choice...";
		}

	}while(ans != 3);
}
