#include<iostream>
using namespace std;
class matrix
{
  private:
          int A[8][8],B[8][8],C[8][8],ra,ca,rb,cb,i,j,k;
  public:
         void getdata();
         void add();
         void sub();
         void mult();
         void diagonal_add();
         void transpose();
         void uppertri();
};
void matrix::getdata()
{

  cout<<"\nEnter no. of rows and columns for 1st matrix: "<<endl;
  cin>>ra>>ca;
  cout<<"\nEnter "<<ra*ca<<" elements for 1st matrix: "<<endl;
  for(i=0;i<ra;i++)
  {
      for(j=0;j<ca;j++)
      {
         cin>>A[i][j];         
      }
  }       
  cout<<"\nEnter no. of rows and columns for 2st matrix: "<<endl;
  cin>>rb>>cb;
  cout<<"\nEnter "<<rb*cb<<" elements for 2nd matrix: "<<endl;
  for(i=0;i<rb;i++)
  {
      for(j=0;j<cb;j++)
      {
         cin>>B[i][j];         
      }
  }       
}
void matrix::add()
{
try
{	
	if(ra==rb&&ca==cb)
	{
 		for(i=0;i<ra;i++)
  		{
     		for(j=0;j<ca;j++)
     		{
        		C[i][j]=A[i][j]+B[i][j];
     		}
  		}
  		cout<<"------------------------------------------------------------------------------------------";
  		cout<<"\nAddition of two matrices is: "<<endl;
  		cout<<"------------------------------------------------------------------------------------------\n";
  		for(i=0;i<ra;i++)
  		{
    		for(j=0;j<ca;j++)
    		{
      			cout<<C[i][j]<<"\t";
    		}
    		cout<<endl;
  		}
  		cout<<"------------------------------------------------------------------------------------------\n";
	}
  	else
  	{
  		throw ra;
	}
}
  catch(int q)
  {
  	cout<<"------------------------------------------------------------------------------------------";
  	cout<<"\nBoth matrices should have same dimentions for matrix addition. Enter matrices again.";
  	cout<<"------------------------------------------------------------------------------------------\n";
  	getdata();	
  }
}
void matrix::sub()
{
try
{	
	if(ra==rb&&ca==cb)
	{
 		 for(i=0;i<ra;i++)
		 {
     		for(j=0;j<ca;j++)
     		{
        		C[i][j]=A[i][j]-B[i][j];
     		}
  		 }
	cout<<"------------------------------------------------------------------------------------------";
	cout<<"\nSubtraction of two matrices is: "<<endl;
	cout<<"------------------------------------------------------------------------------------------\n";
  	for(i=0;i<ra;i++)
  	{
	    for(j=0;j<ca;j++)
	    {
			cout<<C[i][j]<<"\t";
    	}
    	cout<<endl;
  	}
	cout<<"------------------------------------------------------------------------------------------\n";  
	}
	else
	{
		throw ra;
	}
}
	catch(int exc)
	{
	cout<<"\nBoth matrices should have same dimentions for matrix subtraction. Enter matrices again.";
  	getdata();	
	}
}
void matrix::mult()
{
for(i=0;i<8;i++)
  		{
    		for(j=0;j<8;j++)
    		{
    			C[i][j]=0;
			}
		}
try
{	
	if(ca==rb)
	{
		for(i=0;i<ra;i++)
  		{
    		for(j=0;j<cb;j++)
    		{
      			for(k=0;k<ca;k++)
      			{		
        			C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
      			}
    		}
  		}
  	cout<<"------------------------------------------------------------------------------------------";
	cout<<"\nMultiplication of two matrix is: "<<endl;
	cout<<"------------------------------------------------------------------------------------------\n";
  	for(i=0;i<ra;i++)
  	{
	    for(j=0;j<cb;j++)
	    {
		    cout<<C[i][j]<<"\t";
    	}
    	cout<<endl;
  	}
	cout<<"------------------------------------------------------------------------------------------\n"; 
	}
	else
	{
		throw ra;
	}
}
catch(int exc)
{
	cout<<"------------------------------------------------------------------------------------------";
	cout<<"\n1st matrix should have same number of columns as 2nd matrix's rows. Enter matrics again.";
	cout<<"------------------------------------------------------------------------------------------\n";
}
}
void matrix::diagonal_add()
{
  int sum=0,r1,c1;
  cout<<"\nEnter Rows and Columns for given matrix "<<endl;
  cin>>r1>>c1;
  cout<<"\nEnter elements of matrix"<<endl;  
  for(i=0;i<r1;i++)
  {
      for(j=0;j<c1;j++)
      {
         cin>>A[i][j];         
      }
  }
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c1;j++)
    {
      if(i==j)
      {
        sum=sum+A[i][j];
      }
    }
  }
	cout<<"------------------------------------------------------------------------------------------";
   	cout<<"\nAddition of diagonal elements is: "<<sum<<endl; 
   	cout<<"------------------------------------------------------------------------------------------\n";
}              
void matrix::transpose()
{
  int r1,c1;
  cout<<"\nEnter Rows and Columns for given matrix "<<endl;
  cin>>r1>>c1;
  cout<<"\nEnter elements of matrix"<<endl;  
  for(i=0;i<r1;i++)
  {
      for(j=0;j<c1;j++)
      {
         cin>>A[i][j];         
      }
  }
  cout<<"------------------------------------------------------------------------------------------";
  cout<<"\nTranspose of given matrix"<<endl;
  cout<<"------------------------------------------------------------------------------------------\n";
  for(i=0;i<r1;i++)
  {
     for(j=0;j<c1;j++)
     {
        cout<<A[j][i]<<"\t";
     }   
     cout<<endl;
  }
  cout<<"------------------------------------------------------------------------------------------\n";
}  
void matrix::uppertri()
{
    int r1,c1;
  cout<<"\nEnter Rows and Columns for given matrix "<<endl;
  cin>>r1>>c1;
  cout<<"\nEnter elements of matrix"<<endl;  
  for(i=0;i<r1;i++)
  {
      for(j=0;j<c1;j++)
      {
         cin>>A[i][j];         
      }
  }
  int ans=1;
  for(i=0;i<r1;i++)
  {
     for(j=0;j<c1;j++)
     {
       if(A[i][j]==0 && j<i)
       {
        ans=0;
       }
     }
  }
    if (ans==1)
    {
    	cout<<"------------------------------------------------------------------------------------------";
    	cout<<"\nIt is NOT an upper triangular matrix."<<endl;
    	cout<<"------------------------------------------------------------------------------------------\n";
    }
    else
    {
    	cout<<"------------------------------------------------------------------------------------------";
    	cout<<"\nIt is an upper triangular matrix."<<endl;
    	cout<<"------------------------------------------------------------------------------------------\n";
    }
      
}  
   
    
int main()
{
   matrix obj;
   int ch;
   char op='y';
   do
   {
   	cout<<"------------------------------------------------------------------------------------------";
    cout<<"\nSelection Menu: "<<endl;
    cout<<"------------------------------------------------------------------------------------------";
    cout<<"\n1.Addition. \n2.Subtraction. \n3.Multiplication. \n4.Addition of diagonal elements. \n5.Transpose. \n6.Upper triangular or not."<<endl;
    cout<<"Enter choice: "<<endl;
    cout<<"------------------------------------------------------------------------------------------\n";
    cin>>ch;
    switch(ch)
    {
    	case 1:
            obj.getdata();
            obj.add();
            break;
      	case 2:
            obj.getdata();
            obj.sub();
            break;    
      	case 3:
            obj.getdata();
            obj.mult();
            break;
      	case 4:
            obj.diagonal_add();
            break;
      	case 5:
            obj.transpose();
            break;
      	case 6:
            obj.uppertri();
            break;    
	  	case 7:
	  	 cout<<"\nExiting...";
		 break;                         
      	default:
      		cout<<"------------------------------------------------------------------------------------------";
            cout<<"\nInvalid choice. Enter again!"<<endl;
            cout<<"------------------------------------------------------------------------------------------";
    }
   }while(ch!=7);
   return 0;
}
