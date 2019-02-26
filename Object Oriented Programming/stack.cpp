#include<iostream>
#include<stack>
using namespace std;
int main()
	{
		stack<int>s;
		int a;
		int ch;
		do
			{
				cout<<"\n\n1. Push";
				cout<<"\n2. Pop";
				cout<<"\n3. Display topmost element";
				cout<<"\n4. Exit"<<"\n(1/2/3/4)"<<endl;
				cin>>ch;
        switch(ch)
 	       {
    	    case 1:
				cout<<"\n Enter integer to be pushed: ";
    			cin>>a;
		        s.push(a);
		        cout<<" "<<a<<" pushed.";
		        break;
	        case 2:
				if(!s.empty())
			    {	
				    cout<<" "<<s.top()<<" popped.";
					s.pop();
        		}
        		else
        			cout<<"\n Stack is empty.";
        		break;
        	case 3:
				if(!s.empty())
        		{
        			cout<<" Top most integer on the stack is "<<s.top();
        		}
        		else
        			cout<<"\n Stack is empty.";
        		break;
        	case 4:
        		cout<<"\n Exiting ...";
				break;	
			default:
				cout<<"Invalid choice.";
        	}
        }while(ch!=4);
    return 0;
	}

