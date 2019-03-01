#include<iostream>
using namespace std;
typedef struct 
{
  	int roll;
    char name[25];
    int m1,m2,m3;
}stud;

stud s;
void display(FILE *);
int search(FILE *,int);
int main() 
{
    int i, n, key, ch;
    FILE *fp;
	char ans;
    cout<<"\nEnter number of records: ";
    cin>>n;
    cout<<"\n-------------------------------------";
    fp=fopen("stud.txt","w");
    for (i=0;i<n;i++) 
	{
		cout<<"\nEnter info of student "<<i+1;
    	cout<<"\n\nRoll number: ";
    	cin>>s.roll;
    	cout<<"\nName: "; 
    	cin>>s.name;
    	cout<<"\nMarks in subject 1: ";
    	cin>>s.m1;
    	cout<<"\nMakrs in subject 2: ";
    	cin>>s.m2;
    	cout<<"\nMarks in subject 3: ";
    	cin>>s.m3;
    	cout<<"\n-------------------------------------";
		fwrite(&s,sizeof(s),1,fp);
    }
    fclose(fp);
    fp=fopen("stud.txt","r");
    do 
	{	
		cout<<"\n\n1. Display \n2. Search \n3.Exit";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch) 
		{
    		case 1: 	
				cout<<"\nList: \n";
    			display(fp);
    			break;
    			
    		case 2: 	
				cout<<"\nEnter roll no of the student to be searched: ";
				cin>>key;
				if(search(fp, key)) 
				{
    				cout<<"\nRoll\tName\tMarks 1\tMarks 2\tMarks 3\n";
					cout<<s.roll<<"\t"<<s.name<<"\t"<<s.m1<<"\t"<<s.m2<<"\t"<<s.m3<<endl;
    			} 
				else
				{
	   				cout<<"\nRecord not found;";
				}
   				break;
   				
	  			case 3: 	
				cout<<"\nExiting...";
				break;
					
    		default:  
				cout<<"\nInvalid Option.\n";
    	}
	}while(ch!=3);
	fclose(fp);
return 0;
}

void display(FILE *fp) 
{
    rewind(fp);
	cout<<"\nRoll\tName\tMarks 1\tMarks 2\tMarks 3";
	cout<<"\n--------------------------------------------------------------\n";
    while(fread(&s,sizeof(s),1,fp))
	{	
		cout<<s.roll<<"\t"<<s.name<<"\t"<<s.m1<<"\t"<<s.m2<<"\t"<<s.m3<<endl;
	}
}

int search(FILE *fp, int key) 
{
   	rewind(fp);
   	while(fread(&s,sizeof(s),1,fp))
	{
		if( s.roll == key) 
		{
			return 1;
		}
	}
    		return 0;
}
