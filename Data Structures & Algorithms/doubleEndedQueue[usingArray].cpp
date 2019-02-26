#include<iostream>
using namespace std;
#define SIZE 5
class dequeue
{
   int a[10],front,rear,count;
public:
	dequeue();
	void add_beg(int);
	void add_end(int);
	void delete_front();
	void delete_rear();
	void display();
};

dequeue::dequeue()
{
   front=-1;
   rear=-1;
   count=0;
}
void dequeue::add_beg(int item)
{
	int  i;
	if(front==-1)
	{
	  front++;
	  rear++;
	  a[rear]=item;
	  count++;
	}
	else if(rear>=SIZE-1)
	{
		cout<<"\nMore elements can't be inserted. Dequeue is full."<<endl;
	}
	else
	{
	for(i=count;i>=0;i--)
	{
	  a[i]=a[i-1];
	}
	  a[i]=item;
	  count++;
	  rear++;
	}
}
void dequeue::add_end(int item)
{
	if(front==-1)
	{
	  front++;
	  rear++;
	  a[rear]=item;
	  count++;
	}
	else if(rear>=SIZE-1)
	{
	  cout<<"\nMore elements can't be inserted. Dequeue is full."<<endl;
	  return;
	}
	else
	{
	  a[++rear]=item;
	}
}

void dequeue::display()
{
  for(int i=front;i<=rear;i++)
   {
	cout<<a[i]<<" ";	
    }
}

void dequeue::delete_front()
{
	if(front==-1)
	{
	  cout<<"\nDeletion is not possible; Dequeue is empty."<<endl;
	  return;
	}
	else
	{
	  if(front==rear)
	  {
	    front=rear=-1;
            return;
	  }
	  cout<<"\nThe deleted element is "<<a[front];
	  front=front+1;
	}
}
void dequeue::delete_rear()
{
  if(front==-1)
   {
    cout<<"\nDeletion is not possible:Dequeue is empty.";
    return;
   }
   else
   {
     if(front==rear)
     {
	front=rear=-1;
     }
	cout<<"\nThe deleted element is "<< a[rear];
	rear=rear-1;
   }
}
int main()
{
  int c,item;
  dequeue d1;
  char ch;
   do
    {
	cout<<"\n--------------------------------"<<endl;
	cout<<"Menu:"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1. Insert at beginning."<<endl;
    cout<<"2. Insert at end."<<endl;
    cout<<"3. Display full dequeue."<<endl;
    cout<<"4. Deletion from front."<<endl;
    cout<<"5. Deletion from rear."<<endl;
    cout<<"6. Exit."<<endl;
    cout<<"Enter your choice:"<<endl;
    cout<<"--------------------------------"<<endl;
    cin>>c;
    cout<<"--------------------------------"<<endl;
	switch(c)
	  {
		case 1:
			cout<<"\nEnter the element to be inserted: ";
			cin>>item;
			d1.add_beg(item);
			break;

		case 2:
			cout<<"\nEnter the element to be inserted: "<<endl;
			cin>>item;
			d1.add_end(item);
			break;

		case 3:
			d1.display();
			break;

		case 4:
			d1.delete_front();
			break;
			
		case 5:
			d1.delete_rear();
			break;
			
		case 6:
			exit(0);
			break;    
				
		default: 
	        cout<<"\nInvalid choice."<<endl;
    }
   }while(c!=6);
	return 0;
}
