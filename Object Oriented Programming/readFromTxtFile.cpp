//Requires a text file in same dir as the program. Eg. here it requires "abc.txt" with some content in it.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ifstream fin;
  fin.open("abc.txt");
  char line[80];
  int count=0;
  cout<<"\nLines the aren't starting with character 'A':";
  while(!fin.eof())
  {
     fin.getline(line,80);
     if(line[0]!='A')
     {
		cout<<"\n"<<line;
        count++;
     }
  }
  cout<<"\n\nCount: "<<count;
  fin.close();
  return 0;
}


