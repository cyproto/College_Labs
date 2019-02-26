#include<iostream>
#include<cstring>
using namespace std;

class book
{
	char author[50],title[50],pub[50];
	double price;
	int numcopies;
	public:
		book();
		int searchbook(char t[],char a[]);
		void inputdata();
		void displayrecord();
		void requestcopies(int);
};

book::book()
{
	char *author=new char[50];
	char *title=new char[50];
	char *pub=new char[50];
	price=0;
	numcopies=0;
}

void book::displayrecord()
{
	cout<<"\n-------------------------------------------------------------------";
	cout<<"\n"<<title<<"\t"<<author<<"\t"<<pub<<"\t\t"<<price<<"\t"<<numcopies;
	cout<<"\n-------------------------------------------------------------------";
}


void book::inputdata()
{
	cout<<"\n Title:";
	cin>>title;

	cout<<"\n Author:";
	cin>>author;

	cout<<"\n Publisher:";
	cin>>pub;

	cout<<"\n Price:";
	cin>>price;
	
	cout<<"\n Copies Available:";
	cin>>numcopies;
}
int book::searchbook(char t[],char a[])
{
	if((strcmp(title,t)) && (strcmp(author,a)))
		return 0;
	else
		return 1;
}

void book::requestcopies(int num)
{
	if(numcopies>=num)
	{
		cout<<"\n--------------------------------------------------------";
		cout<<"\n Title is available"<<endl;
		cout<<"\n Cost of "<<num<< " book/s is "<<(price*num);	
		cout<<"\n--------------------------------------------------------";
	}
	else
		cout<<"\n Required copies aren't stock"<<endl;
}

int main()
{
	book obj[10];
	char ans;
	char key_title[50],key_author[50];
	int ch,n,i,copies,flag=0;
	i=0;
	do
	{
	cout<<"\n\n 1]Add book details.\n 2]Display available books.\n 3]Inquire.\n 4]Exit\n   ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter Details of Books\n";
			obj[i].inputdata();
			i++;
			break;
	
		case 2:
			n=i;
			cout<<"\nTitle\tAuthor\tPublisher\tPrice\tCopies";
			for(i=0;i<n;i++)
			{
				obj[i].displayrecord();	
			}
			cout<<endl;
			break;
			
		case 3:
			cout<<"\n Enter the title of required book: ";
			cin>>key_title;
			cout<<"\n\n Enter the author of required book: ";
			cin>>key_author;
			for(i=0;i<n;i++)
			{
				if(obj[i].searchbook(key_title,key_author))
			{		
				flag=1;
				break;		
			}
			}	
			if(flag==1)
			{
			cout<<"\n Enter the number of copies required: ";
			cin>>copies;
			obj[i].requestcopies(copies);
			}
			else
			cout<<"\n Book is not available";
			break;
		case 4:
			cout<<"\nExiting...";
			break;
		default:
			cout<<"Invalid choice";
	}
}while(ch!=4);

return 0;
}

