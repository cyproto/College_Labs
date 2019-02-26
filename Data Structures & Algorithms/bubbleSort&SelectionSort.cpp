#include<iostream>
using namespace std;
class selection
{
	public:
    	void select();
    	void bubble();
};

void selection::select()
{  
	float a[100],temp;
    int n,i,j,min_index;
    cout<<"\nEnter count of array elements to be entered: ";
    cin>>n;
    cout<<"\nEnter "<<n<<" array elements: ";
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
    cout<<"\nGiven array elements are: ";
    for(i=0;i<n;i++)
    {
    	cout<<"\t"<<a[i];
    }
    for(i=0;i<n-1;i++)
    	{
    		min_index=i;
     		for(j=i+1;j<n;j++)
      		{
	       		if(a[j]<a[min_index])
	       		{
	         		min_index=j;
    	        }
        	}
        	temp=a[min_index];
	        a[min_index]=a[i];
	        a[i]=temp;
    	}   
   cout<<"\n\nSorted array: ";
   for(j=0;j<n;j++)
    {
     	cout<<"\t"<<a[j];
	}
}
void selection::bubble()
{
    float a[100];
    int n,i,j;
    float temp;
    cout<<"\nEnter the number of elements in the array: ";
    cin>>n;
    cout<<"\nEnter the array elements: ";
    for(i=0;i<n;i++)
    {
	    cin>>a[i];
    }
    cout<<"\nGiven array elements are: ";
    for(i=0;i<n;i++)
    {
   		cout<<"\t"<<a[i];
    }
    cout<<"\n\nSorted array: ";
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-1;j++)
        {
       		if(a[j]>a[j+1])
       		{
         		temp=a[j];
  				a[j]=a[j+1];
         		a[j+1]=temp;
      		}
     	}
    }
   for(j=0;j<n;j++)
   {
     	cout<<"\t"<<a[j];
    }
}
     
int main()
{
    selection s;
    char ans;
    int ch;
    do
    {
    	cout<<"\n\nMenu:";
		cout<<"\n1.Selection sort.";
      	cout<<"\n2.Bubble sort";
      	cout<<"\n3.Exit.";
      	cout<<"\nEnter choice:"<<endl;
      	cin>>ch;
      	switch(ch)
      	{
       		case 1:
	            s.select();
	            break;
		    case 2:
	            s.bubble();
	            break; 
	        case 3:
	        	cout<<"\nExiting...";
	        	break;
	        default:
    	        cout<<"\nInvalid choice";
	            break;
        }
    }while(ch!=3);
return 0;
}
