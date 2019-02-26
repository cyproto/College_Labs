#include <iostream>
#include<string>
using namespace std;

class list;

class node
{
	int prn;
	string name;
	node *next;
public:
	node(int pno,string n)
{
		prn=pno;
		next=NULL;
		name=n;
}

friend class list;
};
class list
{
	node *p;
public:
	list()
	{
		p=NULL;
	}
	void create();
	void display();
	void insertAtBeginning();
	void insertAtEnd();
	void insertAfter();
	void deleteAtFirst();
	void deleteByValue();
	void deleteAtEnd();
	int computeTotal();
	void sortList();
	void concatList(list &q1);
	void displayRev(node *t);
	bool reverseDisplay() 
         {
        	 if(p==NULL)
        		return false;
        	 node *temp=p;
        	 return true;
         }
};

void list::create()
{
	int no,flag;
	string nam;
	if(p==NULL)
	{
		cout<<"Enter PRN: ";
		cin>>no;
		while(!cin)
		{
			cout<<"\nEnter an integer!";
			cout<<"\nEnter PRN again: ";
			cin.clear();
        	cin.ignore(256,'\n');
        	cin>>no;
		}
		cout<<"Enter name: "<<endl;
		cin>>nam;
		cout<<nam;
		p=new node(no,nam);
		cout<<"List Created."<<endl;
		
	}
	else
	{
		cout<<"List is already present."<<endl;
	}
}
void list::display()
{
	node *t;
	int cnt,temp;
	temp=1;
	t=p;
	if(p==NULL)
		{
			cout<<"List is Empty"<<endl;
			return;
		}
	else
	{ 
		cout<<"President :  ";
		while(t!=NULL)
			{
				cout<<"PRN: "<<t->prn<<"->"<<"Name:  "<<t->name<<"    ";
				t=t->next;
			}
		}
		cout<<": Secretary"<<endl;
		
}
void list::insertAtBeginning()
{
	int no;
	string nam;
 node *temp;
 if(p==NULL)
 {
	 create();
 }
 else
 {
	 cout<<"Enter PRN: "<<endl;
	 cin>>no;
	 while(!cin)
		{
			cout<<"\nEnter an integer!";
			cout<<"\nEnter PRN again: ";
			cin.clear();
        	cin.ignore(256,'\n');
        	cin>>no;
		}
	 cout<<"Enter name: "<<endl;
	 cin>>nam;
	 temp=new node(no,nam);
	 temp->next=p;
	 p=temp;
	 cout<<"Inserted  "<<temp->name<<" at the beginning."<<endl;
 }
}
void list::insertAtEnd()
{
	int no;
	string nam;
	node *t;
	if(p==NULL)
		create();
	else
	{
	 cout<<"Enter PRN: "<<endl;
	 cin>>no;
	 while(!cin)
		{
			cout<<"\nEnter an integer!";
			cout<<"\nEnter PRN again: ";
			cin.clear();
        	cin.ignore(256,'\n');
        	cin>>no;
		}
	 cout<<"Enter name: "<<endl;
	 cin>>nam;
	 t=p;
	 while(t->next!=NULL)
	 	t=t->next;
	 	
	 	node*p=new node(no,nam);
	 	t->next=p;
	}
}
void list::insertAfter()
{
	int prev_no;
	cout<<"Enter PRN No. after do you want insert:"<<endl;
	cin>>prev_no;
	node *t;
	t=p;
	string nam;
	int flag=0,no;
	while(t!=NULL)
	{
		if(t->prn==prev_no)
		{
			flag=1;break;
		}
		t=t->next;
	}
	if(flag==1)
	{
	 node *p;
	 cout<<"Enter PRN: "<<endl;
	 cin>>no;
	 while(!cin)
		{
			cout<<"\nEnter an integer!";
			cout<<"\nEnter PRN again: ";
			cin.clear();
        	cin.ignore(256,'\n');
        	cin>>no;
    	}
	 cout<<"Enter name: "<<endl;
	 cin>>nam;
	 p=new node(no,nam);
	 p->next=t->next;
	 t->next=p;
	}
	else
	{
		cout<<""<<prev_no<<" is not in list."<<endl;
	}
	
}

void list::deleteAtFirst()
{
	node *t;
	if(p==NULL)
		cout<<"List is Empty.."<<endl;
	else
	{
	t=p;
	p=p->next;
	t->next=NULL; 
	delete t;
	cout<<"President deleted.."<<endl;
}
}

void list::deleteByValue()
{
	int no,flag;
	flag=0;
	node *t,*prev;
	if(p==NULL)
		{
			cout<<"List is empty."<<endl;
		}
	cout<<"Enter PRN no. of member to be deleted: "<<endl;
	cin>>no;
	t=p;
	if(t->prn==no)
		{
			cout<<"President cannot be deleted using this option."<<endl;
			flag=1;
			return;
		} 
	while(t->next!=NULL)
		{
			t=t->next;
		}
	if(t->prn==no)
		{
			cout<<"Secretary cannot be deleted using this option."<<endl;	
			flag=1;
			return;
		}	
	else 
	{	
		t=p->next; 
		prev=t;
		while(t->next!=NULL)
		{
			
			if(t->prn==no)
			{
				prev->next=t->next;
				t->next=NULL;
				delete t;
				cout<<"Member with prn no "<<no<<" is deleted."<<endl;
				flag=1;
				return;	
			}
			else
			{
				t=t->next;
				prev=t;
			}
		}
		
	}
	if(flag==1)
	{
		return;
	}
	else
	{
		cout<<"Member not found."<<endl;
	
	}
	
}

void list::deleteAtEnd()
{
	node *t,*prev;
	t=p;
		if(p==NULL)
		cout<<"List is Empty.."<<endl;
	else
	{
	while(t->next!=NULL)
	{
		prev=t;
		t=t->next;
	}
	prev->next=NULL;
	delete t;
	cout<<"Secretary Deleted."<<endl;
}
}
int list::computeTotal()
{
node *t;
int count=0;
t=p;
if(p==NULL)
{
	cout<<"List is empty."<<endl;
	return 0;
}
while(t!=NULL)
{
count++;
t=t->next;
}

return count;
}

void list::sortList()
{
	node *i,*j,*last=NULL;
	int tprn;
	string tname;

if(p==NULL)
{
	cout<<"List is empty."<<endl;
	return ;
}
for(i=p;i->next!=NULL;i=i->next)
{
	for(j=p;j->next!=last;j=j->next)
	{
		if((j->prn)>(j->next->prn))
		{
			tprn=j->prn;
			tname=j->name;
			j->prn=j->next->prn;
			j->name=j->next->name;
			j->next->prn=tprn;
			j->next->name=tname;

		}
	}
}
cout<<" List is sorted: "<<endl;
display();
}
void list::concatList(list &q1)
{
	node *t,*p;
	t=q1.p;
	if(t==NULL)
	{
		cout<<"List 2 is empty"<<endl;
		return;
	}
	p=p;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=t;
	q1.p=NULL; 
	cout<<"After concatenation list"<<endl;
	display();	
}

void list::displayRev(node *t)
{
    node *q;
    q=t;
    if(q==NULL)
        return;
    displayRev(q->next);
    cout<<t->prn<<"  "<<t->name<<" \n"<<endl;
}

int main() 
{
	list *l;
	int choice,selectList;
	char a;
	list l1,l2;
	l=&l1;
	X:cout<<"Select List\n1.List 1\n2.List 2\nEnter choice: "<<endl;
	cin>>selectList;

	if(selectList==1)
	{
		l=&l1;
	}
	else if(selectList==2)
	{
		l=&l2;
	}
	else
	{
		cout<<"Wrong list Number."<<endl;
		goto X;
	}
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1.Create"<<endl;
		cout<<"2.Insert President"<<endl;
		cout<<"3.Insert secretary"<<endl;
		cout<<"4.Insert after position(member)"<<endl;
		cout<<"5.Display list"<<endl;
		cout<<"6.Delete President"<<endl;
		cout<<"7.Delete Secretary"<<endl;
		cout<<"8.Delete Member"<<endl;
		cout<<"9.Find total No. of members"<<endl;
		cout<<"10.Sort list"<<endl;
		cout<<"11.Reselect List"<<endl;
		cout<<"12.Combine lists"<<endl;
		cout<<"13.Reverse Display"<<endl;
		cout<<"14.Exit"<<endl;
		cout<<"Select your choice:"<<endl;
		cout<<""<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1: l->create();
				break;
			
			case 2:	l->insertAtBeginning();
				break;
			
			case 3: l->insertAtEnd();
				break;
			
			case 4: l->insertAfter();
				break;
			
			case 5: l->display();
				break;
			
			case 6: l->deleteAtFirst();
				break;
			
			case 7: l->deleteAtEnd();
				break;
			
			case 8: l->deleteByValue();
				break;
			
			case 9:	cout<<"Total members(including President & Secretary): "<<l->computeTotal();
				break;
			
			case 10: l->sortList();
				break;
			
			case 11:
				goto X;
				break;
				
			case 12:
					l1.concatList(l2);
					break;
					
			case 13:
					l->reverseDisplay();
					break;
			deafult:
				 cout<<"Wrong choice"<<endl;
		}
	}while(choice!=14);

	return 0;
}

