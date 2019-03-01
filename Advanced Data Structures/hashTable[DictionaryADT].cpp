#include<iostream>
#include<string.h>
using namespace std;

class Dictionary
{
	struct node
	{
		char word[50],mean[50];
		node *next;		
	}*head[26],*temp,*prev;
	
	public:
		Dictionary()
		{	
			for(int i=0;i<26;i++)
				head[i]=NULL;
	
		}
		void create();
		void find();
		void deleter();
		void display();
		int hash(char);
};

int Dictionary::hash(char ch)
{
	if((int)ch <= 90)
		return (int)ch-65;
	else
		return (int)ch-97;
}

void Dictionary::create()
{
	char ch;
	int key;
	node *New;
	do
	{
		New = new node;
		cout<<"\nEnter word: ";
		cin>>New->word;
		cout<<"\nEnter meaning: ";
		cin>>New->mean;
		New->next = NULL;
		key = hash(New->word[0]);
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
		cout<<"\nEnter another word? (Y|y or N|n)\n";
		cin>>ch;					
	}while(ch == 'y' || ch == 'Y');
}

void Dictionary::display()
{
	for(int i=0;i<26;i++)
	{
		cout<<"\nHead["<<(char)(i+65)<<"]";
		temp = head[i];
		while(temp != NULL)
		{
			cout<<"[ "<<temp->word<<", "<<temp->mean<<" ]";
			temp = temp->next;
		}
		cout<<"--> NULL";
	}
}

void Dictionary::find()
{
	char word[50];
	int key,flag=0;		
	cout<<"\nEnter word to be searched: ";
	cin>>word;
	key = hash(word[0]);
	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(strcmp(temp->word,word)==0)
			{
				cout<<"\nWord: "<<temp->word<<"\nMeaning: "<<temp->mean;
				flag=1;
				break;
			}
			temp=temp->next;
		}
	}
	if(flag == 0)
	{
		cout<<"\nWord not found.";
	}
	
}

void Dictionary::deleter()
{
	char word[50];
	int key,flag=0;
	cout<<"\nEnter word to be nuked from dictionary: ";
	cin>>word;
	key = hash(word[0]);
	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(strcmp(temp->word,word) == 0)
			{
				if(temp == head[key])
				{
					head[key] = head[key]->next;
				}
				else
				if(temp->next != NULL)
				{
					prev->next = temp->next;					
				}
				else
				{
					prev->next = NULL;
				}				
				delete temp;
				cout<<"\nWord deleted from dictionay.";
				flag=1;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	if(flag == 0)
		cout<<"\nWord not found.";		
}

int main()
{
	Dictionary dict;
	int ch;
	do
	{	cout<<"\n\n1. Create | Insert \n2. Display \n3. Find \n4. Delete \n5. Exit \nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				dict.create();
				break;
				
			case 2:
				dict.display();
				break;
				
			case 3:
				dict.find();
				break;
				
			case 4:
				dict.deleter();
				break;
			
			case 5:
				cout<<"\nExiting...";
				break;
				
			default:
				cout<<"\n--->> Invalid choice...";
		}
	}while(ch != 5);
}
