#include <iostream>			
using namespace std;		

void add(double x,double y)		
{
	double resultadd;

	resultadd = x + y;
	
	cout<<"\n\tAnswer of addition is: " << resultadd << endl;
}

void sub(double x,double y)		
{
	double resultsub;

	resultsub = x - y;
	
	cout<<"\n\tAnswer of substraction is : " << resultsub << endl;
}

void mul(double x,double y)		
{
	double resultmul;

	resultmul = x * y;
	
	cout<<"\n\tAnswer of multiplication is : " << resultmul << endl;
}

void div(double x,double y)		
{
	double resultdiv;

	resultdiv = x / y;
	
	cout<<"\n\tAnswer of division is : " << resultdiv << endl;
}

int main()

{

	double a,b,c;
	char oprt,stop;
	void add(double,double);	
	void sub(double,double);	
	void mul(double,double);	
	void div(double,double);		

	do {
		cout<<"\n\n\tEnter First number , Operator and Second number. ";
		cout<<"\n\n\tUse format as <firstNo operator(+|-|*|/) secondNo> Eg.'2+1,6-4': "<<endl<<endl<<"\t";
		cin>>a>>oprt>>b;
		switch(oprt)				
		{

			case '+':
					add(a,b);	
					break;
	
			case '-':
					sub(a,b);	
					break;

			case '*':
					mul(a,b);	
					break;
			case '/':
					div(a,b);	
					break;
			default:
					cout<<"\n\tInvalid operator";

		}					
		cout<< "\n\tContinue ? (Y/y or N/n)" <<endl<<"\t";
		cin>> stop;
	}while(stop == 'y');	

return 0;
}
