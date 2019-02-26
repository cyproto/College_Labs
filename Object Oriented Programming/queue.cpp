#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int  a;
	queue<int>q1;
	int ch;
	char c;
	do
	{
	  cout<<"\n\n1. Insert int."<<endl;
	  cout<<"2. Delete int."<<endl;	
	  cout<<"3. Display last int."<<endl;
	  cout<<"4. Display first int."<<endl;
	  cout<<"5. Size of queue."<<endl;
	  cout<<"6. Exit"<<endl;
	  cin>>ch;
	  switch(ch)
	  {
        case 1:
	    	cout<<"Enter integer: ";
	        cin>>a;
	        q1.push(a);
	        break;			
	 	case 2:
	        a=q1.front();
	        cout<<a<<" deleted"<<endl;
	        q1.pop();
	        break;
	 	case 3:
	        cout<<"\nLast element is "<<q1.back();
	        break;
        case 4:
            cout<<"\nFirst element is "<<q1.front();
            break; 
    	case 5:
	        cout<<"\nSize of queue is: "<<q1.size();
	        break;
		case 6:
			cout<<"Exiting...";
			break;
		default:
			cout<<"Invalid choice.";
	   }
	}while(ch!=6);	
	return 0;
}

