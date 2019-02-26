#include <iostream>
using namespace std;
#define size 10
class stack
{
    int top;
    char stk[size];
public:
    stack()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stack::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stack::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stack::isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stack::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stack s1;
    char exp[20],choice,ch;
    int i=0;
    do
    {
    cout << "\nWell Formness of Parenthesis: " << endl; 
    cout<<"\nEnter the expression to check whether it is in well form or not : "<<endl;
    cin>>exp;
    try
	{
    if((exp[0]=='(')||(exp[0]=='[')||(exp[0]=='{'))
    {
    	while(exp[i]!='\0')
        {
            ch=exp[i];
            switch(ch)
            {
            case '(':s1.push(ch);
            break;
            
            case '[':s1.push(ch);
            break;
            
            case '{':s1.push(ch);
            break;
            
            case ')':s1.pop();
            break;
            
            case ']':s1.pop();
            break;
            
            case '}':s1.pop();
            break;
            
            }
            i=i+1;
        }
    	if(s1.isempty())
    	{
	        cout<<"\nExpression is well parenthesized.\n";
	    }
	    else
	    {
	        cout<<"\nExpression is NOT well parenthesized.\n";
	    }
	}
    else
    {
    	cout<<"\nInvalid Expression.\n";
        throw exp[0];   
    }
	}
    catch(char a)
    {
    	cout<<"\nEnter again.\n";
	}
    cout<<"\nContinue?(Y|y or N|n)"<<endl;
    cin>>choice;
    }while(choice=='y' || choice=='Y');
    return 0;
}
