#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int age;
	float income;
	char city[20],vehicle[10];
	char ch;
	do
		{
			bool flag=0;
			do
			{
			cout<<"\nEnter age: ";
			cin>>age;
			try
			{
				if(age<18 || age>55)
				{
					flag=1;
					throw age;
				}
				else
				{
					cout<<"Age is: "<<age<<endl;
					flag=0;
				}
			}
			catch(int exp)
			{
				cout<<"Enter age between 18 and 55!"<<endl;
			}
			}while(flag==1);
			
			flag=0;
			do
			{
			cout<<"\nEnter income: ";
			cin>>income;
			try
			{
				if(income<50000 || income>100000)
				{
					flag=1;
					throw income;
				}
				else
				{
					cout<<"Income is: "<<income<<endl;
					flag=0;
				}
			}
			catch(float exp)
			{
				cout<<"Enter income between 50,000 to 1,00,000!"<<endl;
			}
			}while(flag==1);
			
			flag=0;
			do
			{
			cout<<"\nEnter city: ";
			cin>>city;
			try
			{
				if(strcmp(city,"Pune")==0 || strcmp(city,"Mumbai")==0 || strcmp(city,"Banglore")==0 || strcmp(city,"Chennai")==0)
				{
					cout<<"City is: "<<city<<endl;
					flag=0;
				}
				else
				{
					flag=1;
					throw city;
				}
			}
			catch(char exp[20])
			{
				cout<<"Enter only Mumbai, Pune, Banglore or Chennai as city"<<endl;
			}
			}while(flag==1);
			
			flag=0;
			do
			{	
			cout<<"\nEnter the type of vehicle(car/bike): ";
			cin>>vehicle;
			try
			{
				if(strcmp(vehicle,"car")==0)
				{
					cout<<"Vehicle is a: "<<vehicle<<endl;
					flag=0;
					
				}
				else
				{
					flag=1;
					throw vehicle;	
				}
			}
			catch(char exp[20])
			{
				cout<<"Enter car as a vehicle!"<<endl;	
			}
			}while(flag==1);
				
		cout<<"\nContinue?(Y/y or N/n)"<<endl;
		cin>>ch;
}while(ch=='y'||ch=='Y');

return 0;
}

