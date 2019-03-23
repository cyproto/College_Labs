#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int bresenhm(int x1,int y1,int x2,int y2)
{
	int p,dx,dy,x,y;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	x=x1,y=y1;
	putpixel(x+320,240-y,0);
	while(x1<=x2)
	{	
		if(p<0)
		{
			x1=x1+1;
			y1=y1;
			p=p+2*dy;
		}
		else
		{
			x1=x1+1;
			y1=y1+1;
			p=p+2*(dy-dx);
		}
		putpixel(x1+320,240-y1,0);
	}
	return 0;
}

int thickline(int x1,int y1,int x2,int y2)
{
	int i,thkns;
	float wx,wy;
	cout<<"\nEnter the thickness\n";
	cin>>thkns;
	setcolor(0);
	line(x1,y1,x2,y2);
	
	if(((y2-y1)/(x2-x1))<1)
	{
		wy=(thkns-1)*sqrt(pow((x2-x1),2) + pow((y2-y1),2)) / (2*fabs(x2-x1));
		for(i=0;i<wy;i++)
		{
			line(x1+320,240-y1-i,x2+320,240-y2-i);
			line(x1+320,240-y1+i,x2+320,240-y2+i);
		}
	}
	else
	{
		wx=(thkns-1)*sqrt(pow((x2-x1),2) + pow((y2-y1),2)) / (2*fabs(y2-y1));
		for(i=0;i<wx;i++)
		{
			line(x1-i+320,240-y1,x2-i+320,240-y2);
			line(x1+i+320,240-y1,x2+i+320,240-y2);
		}
	}
	return 0;
}	

int dotted(int x1,int y1,int x2,int y2)
{
	float x,dx,y,dy,s;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	x=x1;
	y=y1;
	putpixel(x+320,240-y,0);
	if(dx>dy)
		s=dx;
	else
		s=dy;
		dx=dx/s;
		dy=dy/s;
	x = x1 + 0.5; 
   	y = y1 + 0.5; 
   	i = 1;
   	while (i <= s)   
   	{
   		if(i%1==1||i%3==1)
     		putpixel(x+320,240-y,0);
		x = x + dx;
    	y = y + dy;
     	i++;
   	}
	return 0;
}

int main()
{
	int x1,y1,x2,y2,mx,my,mx1,my1;
	int gd=DETECT,gm;
	int ch,y;
	cout<<"\nEnter x1 and y1 co-ordinates:\n";
	cin>>x1>>y1;
	cout<<"\nEnter x2 and y2 coordinates:\n";
	cin>>x2>>y2;
	do
	{
		cout<<"\n1.Enter x & y coordinates again.";
		cout<<"\n2.Display simple line";
		cout<<"\n3.Display thicc Line";
		cout<<"\n4.Display dotted Line";
		cout<<"\n5.Exit";
		cout<<"\nEnter choice: ";
		cin>>ch;
		initgraph(&gd,&gm,NULL);
		setbkcolor(WHITE);
		mx=getmaxx();
		my=getmaxy(); 
		mx1=(mx/2);
		my1=(my/2);
		setcolor(0);
		line(mx1,0,mx1,my);
		line(0,my1,mx,my1);
		switch(ch)
		{
			case 1:
				cout<<"\nEnter x1 and y1 co-ordinates:\n ";
				cin>>x1>>y1;
				cout<<"\nEnter x2 and y2 coordinates:\n ";
				cin>>x2>>y2;
				break;
			case 2: 
				bresenhm(x1,y1,x2,y2);
				break;
			case 3: 
				thickline(x1,y1,x2,y2);
				break;
			case 4: 
				dotted(x1,y1,x2,y2);
				break;
			case 5:
				cout<<"\nExiting...\n";
				break;
			default:
				cout<<"\nInvalid.";
		}
	}while(ch!=5);
	closegraph();
	return 0;		
}