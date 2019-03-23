#include<graphics.h>
#include<iostream>
using namespace std;
int maxx,maxy;
float xxx[4][2];
void line1(float x2,float y2)
{
	line(xxx[0][0],xxx[0][1],x2,y2);
	xxx[0][0]=x2;
	xxx[0][1]=y2;
}
void bezier(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
	float xab,yab,xbc,ybc,xcd,ycd;
	float xabc,yabc,xbcd,ybcd;
	float xabcd,yabcd;
	if(n==0)
	{
		line1(xb,yb);
		line1(xc,yc);
		line1(xd,yd);
	}
	else
	{	
		xab=(xxx[0][0]+xb)/2;
		yab=(xxx[0][1]+yb)/2;
		xbc=(xb+xc)/2;
		ybc=(yb+yc)/2;
		xcd=(xc+xd)/2;
		ycd=(yc+yd)/2;
		xabc=(xab+xbc)/2;
		yabc=(yab+ybc)/2;
		xbcd=(xbc+xcd)/2;
		ybcd=(ybc+ycd)/2;
		xabcd=(xabc+xbcd)/2;
		yabcd=(yabc+ybcd)/2;
		n=n-1;
		bezier(xab,yab,xabc,yabc,xabcd,yabcd,n);
		bezier(xbcd,ybcd,xcd,ycd,xd,yd,n);
	}
}
int main()
{
	int i;
	float temp1,temp2;
	int gd,gm=VGAMAX;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	xxx[0][0]=100;
	xxx[0][1]=200;
	setcolor(0);
	bezier(150,50,200,50,250,200,8);
	xxx[0][0]=250;
	xxx[0][1]=200;
	setcolor(0);	
	bezier(300,350,350,350,400,200,8);
	getch();
	closegraph();
}
