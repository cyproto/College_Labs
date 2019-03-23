#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int xmax,ymax,xmid,ymid;
class pt
{
	protected : int xco,yco,color;
	public :
	pt()
	{
		xco=0;
		yco=0;
		color=0;
	}
	void setco(int x,int y)
	{
		xco=x;
		yco=y;
	}
	void setcolor(int c)
	{
		color=c;
	}
	void draw()
	{
		putpixel(xco,yco,0);
	}
};
class dline:public pt
{
	private:int x2,y2;
	public:
	dline():pt()
	{
		 x2=0;
		y2=0;
	}
	void setline(int x,int y,int xx,int yy)
	{
		pt::setco(x,y);
		x2=xx;
		y2=yy;
	}
	void drawl(int color)
	{
		float x,y,dx,dy,length;
		int i;
		pt::setcolor(color);
		dx=abs(x2-xco);
		dy=abs(y2-yco);
		if(dx>=dy)
		{
			length=dx;
		}
		else
		{
			length=dy;
		}
		
		dx=(x2-xco)/length;
		dy=(y2-yco)/length;
		x=xco+0.5;
		y=yco+0.5;
		i=1;
		
		while(i<=length)
		{
			pt::setco(x,y);
			pt::draw();
			x=x+dx;
			y=y+dy;
			i=i+1;
		}
		
		pt::setco(x,y);
		pt::draw();
	}
};
class dcircle
{
	private:int xo,yo;
	public:
	dcircle()
	{
		xo=0;
		yo=0;
	}
	void setoff(int xx,int yy)
	{
		xo=xx;
		yo=yy;
	}
	void drawc(float x, float y,int r)
	{
		float x1,y1,x2,y2,startx,starty,epsilon;
		int i,val;
		
		x1=r*cos(0);
		y1=r*sin(0);
		startx=x1;
		starty=y1;
		
		i=0;
		do
		{
			val=pow(2,i);
			i++;
		}while(val<r);
		epsilon=1/pow(2,i-1);
		
		do
		{
			x2=x1+y1*epsilon;
			y2=y1-epsilon*x2;
			putpixel(xo+x+x2,yo-(y+y2),0);
			
			x1=x2;
			y1=y2;
		}while((y1-starty)<epsilon||(startx-x1)>epsilon);
	}
};

void drawFig(int x1,int y1,int x2,int y2,int x3,int y3)
{
	dline l1;
	l1.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
	l1.drawl(15);
	l1.setline(x2+xmid,ymid-y2,x3+xmid,ymid-y3);
	l1.drawl(15);
	l1.setline(x3+xmid,ymid-y3,x1+xmid,ymid-y1);
	l1.drawl(15);
}

int main()
{
	int gd,gm=VGAMAX; gd=DETECT;
	int x1,x2,y1,y2,x3,y3;
	
	dline l;
	dcircle cr;
	
	cout<<"\n Enter the co-ordinates of triangle:(Suggested values 100,100,200,100,150,200)";
	cout<<"\n Enter the x1:";cin>>x1;
	cout<<"\n Enter the y1:";cin>>y1;
	cout<<"\n Enter the x2:";cin>>x2;
	cout<<"\n Enter the y2:";cin>>y2;
	cout<<"\n Enter the x3:";cin>>x3;
	cout<<"\n Enter the y3:";cin>>y3;
	double a,b,c;
	a=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	b=sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
	c=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	
	float xc=((a*x1)+(b*x2)+(c*x3))/(a+b+c);
	float yc=((a*y1)+(b*y2)+(c*y3))/(a+b+c);
	float inradius=0.5*sqrt(((b+c-a)*(c+a-b)*(a+b-c))/(a+b+c));
	float cir_radius=(a*b*c)/(4*((a+b+c)*(0.5))*inradius);
	 
	float A=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
	float B=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
	float C=acos(((b*b)+(a*a)-(c*c))/(2*b*a));
	
	float XC=((x1*sin(2*A))+(x2*sin(2*B))+(x3*sin(2*C)))/(sin(2*A)+sin(2*B)+sin(2*C));
	float YC=((y1*sin(2*A))+(y2*sin(2*B))+(y3*sin(2*C)))/(sin(2*A)+sin(2*B)+sin(2*C));
	
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	cleardevice();
	xmax=getmaxx();
	ymax=getmaxy();
	
	xmid=xmax/2;
	ymid=ymax/2;

	setcolor(0);
	line(xmid,0,xmid,ymax);
	line(0,ymid,xmax,ymid);
	
	drawFig(x1,y1,x2,y2,x3,y3);
	cr.setoff(xmid,ymid);
	cr.drawc(xc,yc,inradius);
	cr.drawc(XC,YC,cir_radius);
	getch();
	closegraph();
	return 0;
}