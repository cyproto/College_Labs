#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
  ofstream outfile;
  char file[30];
  cout<<"Enter the file name:"<<endl;
  cin>>file;

  outfile.open(file);
  string data;
  cout<<"Enter the data end it with '^e'"<<endl;
  while(getline(cin,data) ) 
   {
	if(data == "^e")
	{
	  break;
	}  
	outfile<<data<<endl;
 }
  outfile.close();
  
  ifstream infile;
  string data1;
  infile.open(file);
  cout<<"\nFile name is: "<<file<<endl;
  cout<<"\nFile contents are: "<<endl;
  while(getline(infile,data1))
{  
  cout<<data1<<endl;  
}
 infile.close();
return 0;
}

