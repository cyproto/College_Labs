#include<iostream>
#include<conio.h>
using namespace std;
class complex {
	private:
		float i,r;
	public:
		friend ostream &operator<<(ostream &output, const complex &o);
		friend istream &operator>>(istream &input, complex &o);
		complex() {
			i=0;
			r=0;
		}
		complex operator +(complex a2) {
			complex a;
			a.r = r + a2.r;
			a.i = i + a2.i;
			return a;
		}
		complex operator *(complex a2) {
			complex a;
			a.r=(r*a2.r) - (i*a2.i);
			a.i=(r*a2.i) + (i*a2.r);
			return a;
		}
};

ostream &operator<<(ostream &output, const complex &o) {
	output<<"complex no. is: "<<o.r<<"+" <<o.i<<"i"<<endl;
	return output;
}


istream &operator>>(istream &input, complex &o) {
	cout<<"\n1] Enter the real part of the complex no:"<<endl;
	input>>o.r;
	cout<<"2] Enter the imaginary part of the complex no:"<<endl;
	input>>o.i;
	return input;
}

int main() {
	complex a,b,c;
	int choice;
	char ch;	
	do {
		cout<<"\n1.Addition of complex no"<<endl;
		cout<<"2.Multiplication of two complex no"<<endl;
		cout<<"Enter choice:"<<endl;
		cin>>choice;
		switch(choice) {

			case 1:
				cout<<"\nEnter the first complex no:"<<endl;
				cin>>a;
				cout<<a;
				cout<<"\nEnter the second complex no:"<<endl;
				cin>>b;
				cout<<b;
				c = a + b;
				cout<<"\nAddition of "<<c;
				break;
			case 2:
				cout<<"\nEnter the first complex no:"<<endl;
				cin>>a;
				cout<<a;
				cout<<"\nEnter the second complex no:"<<endl;
				cin>>b;
				cout<<b;
				c = a * b;
				cout<<"\nMultiplication of two complex no is"<<c;
				break;

			default:
				cout<<"Invalid"<<endl;
		}
		cout<<"\nContinue? (Y/y or N/n)"<<endl;
		cin>>ch;
	} while(ch=='Y' || ch=='y');
	
	getch();
	return 0;

}
