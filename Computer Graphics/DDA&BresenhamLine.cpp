#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
class abc
{
	int x1,y1,x2,y2;
	int dx,dy,p,x,y;
public:
	void DDA()
	{
		float xinc,yinc,s,x,y,dx,dy;
		cout<<"\nEnter the x1 and y1 coordinates";
		cin>>x1>>y1;
		cout<<"\nEnter the x2 and y2 coordinates";
		cin>>x2>>y2;
		dx=x2-x1;
		dy=y2-y1;
		x=x1;
		y=y1;
		putpixel(x,y,BLUE);
		if(dx>dy)
			s=dx;
		else
			s=dy;
		xinc=dx/s;
		yinc=dy/s;
		for(int i=1;i<=s;i++)
		{	
			x=x+xinc;
			y=y+yinc;
			x1=(int)x+0.5;
			y1=(int)y+0.5;
			putpixel(x1,y1,BLUE);
		}
	}
	void bresenham()
	{
		cout<<"\nEnter x1 and y1 coordinates";
		cin>>x1>>y1;
		cout<<"\nEnter x2 and y2 coordinates";
		cin>>x2>>y2;
		dx=x2-x1;
		dy=y2-y1;
		p=2*dy-dx;
		x=x1,y=y1;
		putpixel(x,y,RED);
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
			putpixel(x1,y1,RED);
		}	
	}
	
};	
int main()
{
	abc a;
	int n;
	char ans;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	do
	{
		
		cout<<"\nMenu:";		
		cout<<"\n1.DDA Algorithm";
		cout<<"\n2.Bresenham's Line Algorithm";
		cout<<"\n3.Exit";
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{		
			case 1:
				cleardevice();
				a.DDA();
				break;

			case 2:
				cleardevice();
				a.bresenham();
				break;

			case 3:
				cout<<"\nExiting...\n";
				exit(0);

			default:
				cout<<"\nInvalid Choice";
		}
	}
	while(n!=3);
	getch();
	closegraph();
	return 0;
}	