#include <iostream>

using namespace std;
class PersonalRecord
{
	protected:char name[10];
		  char dob[10];
		  char Bgrp[5] ;
		  char gender[10];
		  char address[80];
	public: 
		void get_Personal_data();
		void disp_Personal_data();
		

};
void PersonalRecord::get_Personal_data()
{
	cout<<"\n--------------------------------------------------";
	cout<<"\nEnter Name: ";
	cin>>name;
	cout<<"\nEnter Date of Birth(DD/MM/YY): ";
	cin>>dob;
	cout<<"\nEnter Blood group: ";
	cin>>Bgrp;			
	cout<<"\nEnter Gender: ";
	cin>>gender;			
	cout<<"\nEnter Address: ";
	cin>>address;
	cout<<"\n--------------------------------------------------";
}
void PersonalRecord::disp_Personal_data()
{
	cout<<"\n--------------------------------------------------";
	cout<<"\nName\tDOB\tBlood Group\tGender\tAddress"<<endl;
	cout<<name<<"\t"<< dob<<"\t"<<Bgrp<<"\t\t"<<gender<<"\t"<<address<<endl;
	cout<<"--------------------------------------------------";
}
class ProfessionalRecord
{
	protected: 
			char CurrentWorkplace[80];	
		   	float Experience;
	        char doj[10];
		   	int Emp_id;
	public: 
			void get_Professional_data();
			void disp_Professional_data();
		
};
void ProfessionalRecord::get_Professional_data()
{
	cout<<"\n--------------------------------------------------";
	cout<<"\nEnter Employee Id: ";
	cin>>Emp_id;
	cout<<"\nEnter Name of Organization: ";
	cin>>CurrentWorkplace;
	cout<<"\nEnter Date of Joining(DD/MM/YY): ";
	cin>>doj;
	cout<<"\nEnter Experience (Years): ";
	cin>>Experience;		
	cout<<"\n--------------------------------------------------";
}
void ProfessionalRecord::disp_Professional_data()
{
	cout<<"\n------------------------------------------------------------------";
	cout<<"\nEmployee Id\t Organization Name\tDOJ\tExperience"<<endl;
	cout<<Emp_id<<"\t\t"<<CurrentWorkplace<<"\t\t\t"<< doj<<"\t"<<Experience<<endl;
	cout<<"------------------------------------------------------------------";
}
class AcademicRecord
{
	protected:float Tenth;
		float Twelth;
		float Degree;
		char University[50];
	public: void get_Academic_data();
		void disp_Academic_data();
	
};
void AcademicRecord::get_Academic_data()
{
	cout<<"\n--------------------------------------------------";
	cout<<"\nEnter SSC Percentage: ";
	cin>>Tenth;
	cout<<"\nEnter HSS Percentage: ";
	cin>>Twelth;
	cout<<"\nEnter Degree Percentage: ";
	cin>>Degree;
	cout<<"\nEnter name of University: ";
	cin>>University;
	cout<<"\n--------------------------------------------------";
}
void AcademicRecord::disp_Academic_data()
{
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\nSSC Percentage\t HSC Percentage\t Degree Percentage\t University"<<endl;
	cout<<Tenth<<"\t\t"<<Twelth<<"\t\t\t"<< Degree<<"\t\t"<<University<<endl;
	cout<<"------------------------------------------------------------------------------";
}
class Bio_data : public AcademicRecord,public PersonalRecord,public ProfessionalRecord 
{
	public: 
		void disp_biodata()
		{
			disp_Personal_data();
			disp_Professional_data();
			disp_Academic_data();
		}	
};

int main()
{
	int i;
	char ch;
	Bio_data p;				
	cout<<"\nEnter Personal Information of Employee: ";
	p.get_Personal_data();
	cout<<"\nEnter Professional Information of Employee: ";
	p.get_Professional_data();
	cout<<"\nEnter Academic Information of Employee: ";
	p.get_Academic_data();
	do
	{
	cout<<"\n1.Personal Data"<<endl;
	cout<<"2.Professional Data"<<endl;
	cout<<"3.Academic Data"<<endl;
	cout<<"4.Whole Bio-data"<<endl;
	cout<<"5.Exit"<<endl;
	cout<<"Enter choice:\t";
	cin>>i;
	switch(i)
	{
		case 1: 
				cout<<"\n----Personal Data----"<<endl;
			 	p.disp_Personal_data();
				break;
		case 2:
				cout<<"\n----Professional Data----"<<endl;
			 	p.disp_Professional_data();
				break;
		case 3: 
				cout<<"\n----Academic Data----"<<endl;
				p.disp_Academic_data();
				break;
		case 4:
				cout<<"\n----Bio-data of Employee----"<<endl;
				p.disp_biodata();
				break;
		case 5:
				cout<<" Exiting...";
				break;

	}
	}while(i!=5);	
return 0;
}
