#include<iostream>
#include<stdlib.h>
using namespace std;
#define TRUE 1
#define FALSE 0
#define SIZE 20	
class node
{
	public:
	int num;
	node *next;
}*head;


class linklist
{
    public:
	linklist();
	node *create();
	void disp(node *);
	node *insert_head();
	void insert_after();
	void insert_last();
	node *remove();
	node *sort();
	node *merge(node *,node *);
	~linklist();
};

linklist::linklist()
	{
		head=NULL;
	}

linklist::~linklist()
	{
		node *p,*q;
		p=head->next;
		delete head;
		while(p!=NULL)
		{
			p=p->next;
			delete p;
			p=q;
		}
	}	
node *linklist::create()
{
	node *p=NULL,*New;
	int val,flag;
	char ans='y';
	flag=TRUE;
	do
	{
		cout<<"Enter number"<<endl;
		cin>>val;
		New=new node;
		if(New==NULL)
		{
			cout<<"List is empty"<<endl;
		}	
		New->num=val;
		New->next=NULL;
		if(flag==TRUE)
		{
			head=New;
			p=head;
			flag=FALSE;
		}
		else
		{
			p->next=New;
			p=New;
		}
		cout<<"Do u want to insert more?(y or n)"<<endl;
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return head;
}

void linklist::disp(node * head)
{
	class node *p;
	p=head;
	if(p==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	while(p!=NULL)
	{
		cout<<" "<<p->num<<endl;
		cout<<"------------------------------------------------- "<<endl;
		p=p->next;
	}
}

void linklist::insert_last()
{
	node *p,*New;
	New=new node;
	cout<<"Enter new value"<<endl;
	cin>>New->num;
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		p=New;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=New;
		New->next=NULL;
	}
	cout<<"Node inserted"<<endl;
}

void linklist::insert_after()
{
	node *p,*New;
	int key;
	New=new node;
	cout<<"Enter the value"<<endl;
	cin>>New->num;
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		head=New;
	}	
	else
	{
		cout<<"Enter value of the node after which you want to insert the node"<<endl;
		cin>>key;
		p=head;
		do
		{
			if(p->num==key)
			{
				New->next=p->next;
				p->next=New;
				break;
			}
		else
			p=p->next;
		}while(p!=NULL);
	}
	cout<<"Node inserted"<<endl;
}

node *linklist::insert_head()
{
	node *p,*New;
	New=new node;
	cout<<"Enter the value"<<endl;
	cin>>New->num;
		if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		head=New;
	}	
	else
	{
		p=head;
		New->next=p;
		head=New;
	}
	cout<<"Node inserted"<<endl;
	return head;
}

node *linklist::remove()
{
	node *p,*q,*prev;
	prev=new node;
	q=head;
	while(q!=NULL)
	{
		if(q->num<0)
		{
			p=head;
			while(p!=NULL)
			{
				if(p->num<0)
					break;
				prev=p;
				p=p->next;
			}
			if(p==NULL)
			{
			cout<<"List is empty"<<endl;
			}	
			else
			{
				if(p==head)
				{
					head=p->next;
					q=head;
				}
				else
				{	
					prev->next=p->next;
					q=prev->next;
				}
				delete p;
				cout<<"Node deleted"<<endl;
			}
		}
		else
			q=q->next;
	}
	return head;
}

node *linklist::sort()
{
	node *p,*New,*head,*prev;
	char ch;
	p=NULL;
	head=NULL;
	do
	{
		New=new node;
		New->next=NULL;
		cout<<"Enter the data"<<endl;
		cin>>New->num;
		if(head==NULL)
			head=New;
		else
		{
			p=head;
			prev=NULL;
			while(p!=NULL)
			{
				if(p->num<New->num)
				{
					prev=p;
					p=p->next;
				}
				else				
					break;
			}
			if(prev==NULL)
			{
				New->next=head;
				head=New;
			}
			else
			{
				New->next=prev->next;
				prev->next=New ;
			}
		}
		cout<<"Continue?(y or n)"<<endl;
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return head;
}

node *linklist::merge(node* first,node* second)
{
	node *third=NULL;
    if(first==NULL)
    {
    	return(second);
	} 
    else if(second==NULL)
    {
    	return(first);
	}
    if(first->num<=second->num)
    {
       third=first;
       third->next=merge(first->next,second);
    }
    else
    {
        third=second;
        third->next=merge(first,second->next);
    }
    return(third);
}

int main()
{
	linklist s;
	int choice,ch1;
	char ch;
	node *start;
	node *start1,*start2;
	start1=NULL;
	start2=NULL;
	do	
	{
		cout<<"***************MENU**********"<<endl;
		cout<<"------------------------------------------------- "<<endl;
		cout<<"1.Create"<<endl;
		cout<<"2.Display list"<<endl;
		cout<<"3.Insert no"<<endl;
		cout<<"4.Delete -ve no"<<endl;
		cout<<"5.Create two lists & merge into 3rd list"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter your choice (1-6)"<<endl;
		cout<<"------------------------------------------------- "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				start=s.create();
				break;
			case 2:
				s.disp(start);
				break;
			case 3:
				cout<<"the list is:"<<endl;
				s.disp(start);
				cout<<"\nMENU"<<endl;
				cout<<"1.Insert head"<<endl;
				cout<<"2.Insert after"<<endl;
				cout<<"3.Insert last"<<endl;				
				cout<<"enter your choice"<<endl;
				cin>>ch1;
				switch(choice)
				{
					case 1:
						start=s.insert_head();
						break;
					case 2:
						s.insert_after();
						break;
					case 3:
						s.insert_last();
						break;
					default:
						cout<<"Invalid choice"<<endl;
				}
				break;
			case 4:
				start=s.remove();
				break;
			case 5:
				cout<<"Enter 1st list"<<endl;
				start1=s.sort();
				cout<<"Enter 2nd list"<<endl;
				start2=s.sort();
				cout<<"List of numbers:"<<endl;
				s.disp(start1);
				s.disp(start2);
				start=s.merge(start1,start2);
				cout<<"Merged list is"<<endl;
				s.disp(start);
				break;
				
			case 6:
				exit(0);
		}
		cout<<"Do you want to go to main menu?(y or n)"<<endl;
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}

