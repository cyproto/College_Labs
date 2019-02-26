#include<iostream>  
 using namespace std;
 
 class polynomial  
 {  
  	int a,b,c,eval,x;  
	public:  
	friend ostream &operator << (ostream &output, const polynomial &o);
	friend istream &operator >> (istream &input, polynomial &o);	
	void evaluate()
         { int x,eval;
	cout<<"Enter the value of x: \t";
	cin>>x;
	eval= a*x*x+b*x+c;
          cout<<"\nValue of polynomial is "<<eval<<" if x is "<<x<<endl;
         }
	polynomial()
	{
		a=0;
		b=0;
		c=0;
	}  	
	polynomial operator+(polynomial p)  
  	{    
  		polynomial t;  
  		t.a=a+p.a;  
 		t.b=b+p.b;
		t.c=c+p.c;
		 
 		 return t;  
  	}  
 };  
	
	ostream &operator << (ostream &output, const polynomial &o)
	{
			
		output<<"polynomial is:\t" <<o.a<<"x^2 + "<<o.b<<"x + "<<o.c<<endl;
		return output;
		
	} 
	
	istream &operator >> (istream &input, polynomial &o)
	{
		cout <<" \n\tEnter the coeff. of x^2: "	;	
		input >> o.a;
		cout <<endl<<"\n\tEnter the coeff of x: ";
		input >> o.b;
		cout <<endl<<"\n\tEnter the constant term: ";
		input >> o.c;
		return input;
	}
	
int main()  
 {  
 	int op,val; 
 	char ch; 
 	polynomial firstPoly,secondPoly,sum,eval;  
 	do  
 	{   cout<<"\n1]Addition of two polynomial equations. \n"<<"2]Evaluate polynomial.\n";  
  		cout<<endl<<"Enter the choice :\t";  
  		cin>>op;  
  		switch(op)  
 		{  
  			case 1:  
					cout<< " \nFirst polynomial Number: ";       					
					cin>> firstPoly;
					cout<<"\nGiven "<<firstPoly;
					cout<<" \nSecond polynomial Number: ";       					
       		        cin>>secondPoly;					
					cout<<"\nGiven "<<secondPoly;
       				sum=firstPoly + secondPoly;  
       				cout<<"\nAddition of "<<sum; 
      		      	break; 				
  			case 2:  
					cout << "Polynomial Number:\t \n ";       		 				
					cin >>firstPoly;
					cout <<"\nGiven "<<firstPoly;
					firstPoly.evaluate();
       				cout<<"\n"; 
       		        break;
			default:	
					cout<<"Invalid\n";
					break;
  		}  
  		cout<<"\nContinue? (Y/y or N/n)\t";
  		cin>>ch;
  	}while(ch=='y'||ch=='Y');
  	
 return 0;
 } 
