#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAX 80
class Test
{
public:
	static int N;
	int Roll;
	char Name[20];
	char Subject[20];
	int Marks;
	char Attendance;
	Test();
		void Add();
		void Display();         
};

int Test::N=0;
Test::Test()
{
  Roll=-1;
  strcpy(Name,"default");
  strcpy(Subject,"DSA");
  Marks=-1;
  Attendance='A';  
}

void Test::Add()
{
 int flag;
 cout<<"\n\t Enter Roll Number : ";
 cin>>Roll;
 cout<<"\n\t Enter Name        : ";
 cin>>Name;
 cout<<"\n\t Enter Subject     : ";
 cin>>Subject;
 cout<<"\n\t Enter Attendance  : ";
 cin>>Attendance;
 do{
	 if(Attendance=='P'||Attendance=='p')
 	{ 
  		cout<<"\n\t Enter Marks       : ";
  		cin>>Marks;
  		try{
  			if(Marks>10)
  			{
  				throw Marks;
  				flag=1;
			}
			else
			{
				flag=0;
			}
			}
		catch(int ex)
		{
			cout<<"\n\tMarks must be 10 or below 10";
		}
	}
	 else
 	{
	   	Marks = -1;
 	}  
	}while(flag==1); 
}
void Test::Display()
{
	cout<<"\n\t"<<Roll<<"\t"<<Name<<"\t"<<Subject<<"\t"<<Attendance;
 	if(Attendance=='P'||Attendance=='p')
 	{
  		cout<<"\t"<<Marks;
 	}
 	else
 	{
  		cout<<"\t"<<"NA";
 	}  
}

int main()
{
 int choice,x,arr[20];
 char ch;
 float avg;
 int i,j;
 int M[51]={0};
 Test objTest[MAX];
do
{
 cout<<"\n\t 1. Add student record";
 cout<<"\n\t 2. Display list";
 cout<<"\n\t 3. Display highest marks";
 cout<<"\n\t 4. Display lowest marks";
 cout<<"\n\t 5. Display absent students";
 cout<<"\n\t 6. Display avereage score of whole class";
 cout<<"\n\t 7. Display marks scored by most of the students";
 cout<<"\n\t 8. Exit";
 cout<<"\n\t Enter choice: ";
 cin>>choice;
switch(choice)
{
 case 1:
	objTest[Test::N].Add();
 	Test::N = Test::N + 1;
 	break;
 case 2:
 	cout<<"\n\t_________________________________________";
 	cout<<"\n\t                                     ";
 	cout<<"\n\t Roll\tName\tSubject\tAttendance\tMarks";
 	cout<<"\n\t_________________________________________";
 	for(i=0;i<Test::N;i++)
 	{
  		objTest[i].Display();
 	}
 	cout<<"\n\t_________________________________________";
 	break;
 case 3:
 	x=objTest[0].Marks;
 	for(i=1;i<Test::N;i++)
 	{
  		if(x < objTest[i].Marks && (objTest[i].Attendance=='P'||objTest[i].Attendance=='p'))
  		{
   			x = objTest[i].Marks;
 	 	}
 	}
 	cout<<"\n\t Highest Score is "<<x;
 	break;
 case 4:
 	x=objTest[0].Marks;
 	for(i=1;i<Test::N;i++)
 	{
 		if(x > objTest[i].Marks && (objTest[i].Attendance=='P'||objTest[i].Attendance=='p'))
 		{
  			x = objTest[i].Marks;
 		}
 	}
 	cout<<"\n\t Lowest Score is "<<x;
 	break;
case 5:
	cout<<"\n\t_________________________________________";
	cout<<"\n\t Roll\tName\tSubject\tAttendance\tMarks";
 	cout<<"\n\t_________________________________________";
 	for(i=0;i<Test::N;i++)
 	{
  		if(objTest[i].Attendance=='A'||objTest[i].Attendance=='a')
  		{
   		objTest[i].Display();
  		} 
 	}
 	cout<<"\n\t_________________________________________";
 	break;
 case 6:
 	avg=0;
 	x=0;
 	for(i=0;i<Test::N;i++)
 	{
  		if(objTest[i].Attendance=='p'||objTest[i].Attendance=='P')
  		{
   		avg = avg + objTest[i].Marks;
   		x++;
  		}
 	}
 	if(x==0)
 	{
  		cout<<"\t record not found";
 	}
 	else
 	{
  		avg = avg/x;
  		cout<<"\n\t Avereage Score of the class is "<<avg;
 	}
 	break;
case 7:
	int m[80],temp,arr[10];
 	for(i=0;i<Test::N;i++)
 	{
  		if(objTest[i].Attendance=='p'||objTest[i].Attendance=='P')
	  	{
   			m[i]=objTest[i].Marks;          
  		}
 	}
 	for(i=0;i<=10;i++)
 	{
 		arr[i]=0;
	}
	for(i=0;i<50;i++)
 	{
 		for(j=1;j<=10;j++)
 		{
			if(j==m[i])
			{
				arr[j]++;
			}
 		}
 	}
	int maxi,ind;
	maxi=arr[1];
	for(j=2;j<=10;j++)
	{ 
		if(arr[j]>maxi)
		{
			maxi=arr[j];
			ind=j;
		}
	}
 	cout<<"\n\t"<<maxi<<" students scored: "<<ind<<"/10";   
 	break;
 case 8:
 	exit(0);
 	break;
default:
	cout<<"\n\t Invalid choice";
 }
}while(choice!=8);
 return 0; 
}
