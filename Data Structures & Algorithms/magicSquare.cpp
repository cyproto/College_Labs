#include<iostream>
using namespace std;
int main()
{
	int col, row, flag1, flag2, diagSum, colSum, rowSum;
	char choice;
	do{
	do{
	cout<<"\nEnter number of rows: ";
	cin>>row;
	cout<<"\nEnter number of columns: ";
	cin>>col;
	flag1=0;
	try{
		if(row!=col)
		{
			flag1=1;
			throw row;
		}
		}
	catch(int exc)
	{
		cout<<"\nRows and columns should be equal! Enter again.\n";
	}
	}while(flag1==1);
	int matrix[row][col];
	cout<<"\nEnter "<<row*col<<" matrix elements:";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>matrix[i][j];
			cout<<"\t\t\t";
		}
	}
	cout<<"\nMatrix entered is: ";
	for(int i=0;i<row;i++)
	{
		cout<<"\n";
		for(int j=0;j<col;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
	}
	diagSum=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i==j)
			{
				diagSum=diagSum+matrix[i][j];		
			}
		}
	}
	for (int i=0;i<row;i++) 
	{
		colSum=0;
		for (int j=0;j<col;j++)
 		{
			colSum = colSum + matrix[i][j];
		}
		if (diagSum == colSum)
 		{
		 	flag2 = 1;
		}
		else 
		{
 			flag2 = 0;
			break;
		}
	}
	for (int i=0;i<row;i++) 
	{
		rowSum = 0;
		for (int j=0;j<col;j++) 
		{
			rowSum = rowSum + matrix[j][i];
		}
		if (diagSum == rowSum)
 		{
		 	flag2 = 1;
		}
		else
 		{
 			flag2 = 0;
			break;
		}
	}
	if(flag2==1)
	{
		cout<<"\nGiven matrix is a magic square.";
	}
	else
	{
		cout<<"\nGiven matrix is a NOT magic square.";
	}
	cout<<"\nExit?(Y|y or N|n)"<<endl;
	cin>>choice;
	}while(choice=='N'||choice=='n');
}

