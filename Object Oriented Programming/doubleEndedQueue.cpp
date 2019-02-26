#include<iostream>
#include<deque>
using namespace std;
int main()
{
	int a,choice;
	char ch;
	deque<int>d1;
	deque<int>::iterator i;
	do
	{
		cout<<"\n\n1. Insert element from front";
		cout<<"\n2. Insert element from rear";
		cout<<"\n3. Delete element from front";
		cout<<"\n4. Delete element from rear";
		cout<<"\n5. Size of queue:";
		cout<<"\n6. Display the Queue:";
		cout<<"\n7. Exit";
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
     			cout<<"\nEnter integer: ";
     			cin>>a;
      			d1.push_front(a);
    			break;
  
 			case 2:
     			cout<<"\nEnter integer: ";
     			cin>>a;
     			d1.push_back(a);
     			break;
     			
      		case 3:
     			cout<<"\nElement deleted from front";
     			d1.pop_front();
    			break;
     
 			case 4:
      			cout<<"\nElement deleted from rear";
      			d1.pop_back();
      			break;
      
  			case 5:
      			cout<<"\nSize of dequeue: "<<d1.size();
      			break;
      
 			case 6:
     			cout<<"\nElements in queue are: ";
     			for(i=d1.begin();i!=d1.end();i++)
     			{
     				cout<<*i;
     			}
     			break;
     		
			case 7:	
     			cout<<"\nExiting...";
     			break;
     		
			default:
				cout<<"\nInvalid choice";

        }
    }while(choice!=7);
 return 0;
}
