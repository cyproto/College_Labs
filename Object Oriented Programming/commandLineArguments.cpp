#include <fstream>
#include <iostream>
#include <string.h>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[])
 {
  if(argc<4)
  {
    cout<<"Insufficient number of arguments on command line\nUsage: '<program_name> <word to be replaced> <new word to be replaced with old> <file_name>'";
    exit (1);
  }
string data,newdata;
fstream fin;
cout<<"Find string \""<<argv[1]<<"\" and replace with \""<<argv[2]<<"\" in file\" "<<argv[3]<<" \"\n";
cout<<"Contents of file before replacing: \n";     
fin.open(argv[3],ios::in);
	if(!fin)
		{
			cout<<"Error opening file.";
			return 1;
		}
		while(fin)
		{
			getline(fin,data);
			cout<<data<<endl;
		}
fin.close();
fin.open(argv[3],ios::in);
newdata="";
if(!fin)
	{
	    cout << "Unable to open file";
		exit(1);
	}
while(fin)
	{
		getline(fin,data);
		int b;
		int a =(int) data.find(argv[1],0);
		while (a != string::npos)
		{
			data.replace(a,strlen(argv[1]),argv[2]);
			a =(int) data.find(argv[1],(a+1));
		}
		newdata=newdata+data+"\n";
	}
fin.close();
fin.open(argv[3],ios::out);
	if(!fin)
		{
			cout<<"Error opening file";
			return 1;
		}
	fin<<newdata;
	cout<<"Replacement successful.\n";
fin.close();
cout<<"Contents of file after replacing: \n";
fin.open(argv[3],ios::in);
if(!fin)
{
	cout<<"error opening file";
	return 1;
}
while(fin)
{
	getline(fin,data);
	cout<<data<<endl;
}
fin.close();
return 0;
}
