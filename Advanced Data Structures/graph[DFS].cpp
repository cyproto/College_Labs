#include<iostream>
using namespace std;
class Graph
{
	int vertex_total,visit[10],adj_mtx[10][10];
	struct node
	{
		int vertex;
		node *adj;
	}*head[10],*temp;
	public :
		void init_visited();
		int create();
		void display_Adj_mtx();
		void display_Adj_list();
		void dfs(int);
};

void Graph::init_visited()
{
	for(int i=0 ; i<vertex_total ; i++)
		visit[i]=0;
}

int Graph::create()
{
	int i,j,v1,v2;
	char ch;
	node *New;
	cout<<"\nEnter total number of vertices in graph: ";
	cin>>vertex_total;
	for(i=0 ; i<vertex_total ; i++)
	{
		head[i] = NULL;
		for(j=0 ; j<vertex_total ; j++)
		{
			adj_mtx[i][j]=0;
		}
	}	
	do
	{
		cout<<"Enter edge: \n";
		cin>>v1>>v2;
		if(v1 >= vertex_total || v2 >= vertex_total)
		{
			cout<<"\n -->> Error...(max vertex no. ( 0 - "<<vertex_total-1<<") )";
		}
		else
		{
			New = new node;
			New->vertex = v2;
			New->adj = NULL;
			temp = head[v1];
			if(temp == NULL)
				head[v1] = New;
			else
			{
				while(temp->adj != NULL)
				temp = temp->adj;
				temp->adj = New;	
			}
			New = new node;
			New->vertex = v1;
			New->adj = NULL;
			temp = head[v2];
			if(temp == NULL)
				head[v2] = New;
			else
			{
				while(temp->adj != NULL)
				temp = temp->adj;
				temp->adj = New;	
			}
			adj_mtx[v1][v2] = 1;
			adj_mtx[v2][v1] = 1;	
		}
		cout<<"\nAdd another edge? (Y|y or N|n): ";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
	
	return vertex_total;
}

void Graph::display_Adj_mtx()
{
	int i,j,k;
	k=0;
	cout<<"\nAdjacency matrix: \n\n";
	cout<<"\t\t";
	for(i=0;i<vertex_total;i++)
	{
		cout<<i<<"\t";
	}
	cout<<"\n\t\t-----------------------";
	for(i=0 ; i<vertex_total ; i++)
	{
		cout<<"\n\n";
		cout<<k++<<"\t|";
			
		for(j=0 ; j<vertex_total ; j++)
		{			
			cout<<"\t"<<adj_mtx[i][j];
		}		
	}
	cout<<endl;
}

void Graph::display_Adj_list()
{
	int i,j;
	cout<<"\nVertex no: \tAdjacent vertices: ";
	for(i=0 ; i<vertex_total ; i++)
	{		
		cout<<"\n v"<<i<<" \t:\t";
		temp = head[i];
		while(temp != NULL)
		{
			cout<<temp->vertex<<"\t";
			temp=temp->adj;
		}
	}	
}

void Graph::dfs(int v1)
{
	int v2;
	cout<<"\t"<<v1;
	visit[v1]=1;
	for(v2=0 ; v2<vertex_total ; v2++)
	{
		if(adj_mtx[v1][v2]==1  &&  visit[v2]==0)
		{
			dfs(v2);
		}
	}

}

int main()
{
	int ch,v,i,vertex_total;
	Graph gph;
	do
	{
		cout<<"\n\n1. Create graph \n2. Display Adjacency matrix \n3. Display list representation \n4. DFS \n5. Exit \nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				vertex_total = gph.create();
				break;
				
			case 2:
				gph.display_Adj_mtx();
				break;
				
			case 3:
				gph.display_Adj_list();
				break;
				
			case 4:				
				cout<<"\nStart from vertex no? ";
				cin>>v;			
				cout<<endl;		
				gph.init_visited();
				gph.dfs(v);				
				break;
				
			case 5:
					cout<<"\nExiting...";
					break;
					
			default:
				cout<<"Invalid choice...";			
		}
	}while(ch != 5);
	return 0;
}
