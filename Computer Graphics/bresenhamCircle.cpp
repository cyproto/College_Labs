#include<graphics.h>
#include<iostream>
using namespace std;
class pt
{
	protected:int xco,yco,color;
	public:
	pt() 
 	{
 		xco=0;yco=0;color=15;
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
		putpixel(xco,yco,color);
 	}
};
class dcircle:public pt
{
	private:
			int r;
	public:
		dcircle():pt() 
		{
			r=10;
		}
		void setCircle(int x,int y,int rad, int color)
		{
			pt::setco(x,y);
			pt::setcolor(color);
			r=rad;
		}
		void drawCir(int rad)
		{
			int q;
			int x1,y1;
			x1 = 0; 
			y1 = rad;
			q = 3-(rad*2);
			while(x1<=y1)
 			{ 
	 			if(q<=0) 
 				q = q+(4*x1)+6;
  				else 
  				{ 
	  				q += 4*(x1-y1)+10;
  				 	y1--; 
  		  		} 
  				x1++; 
  				display(x1,y1,xco,yco); 
			} 
  		} 
  		void display (int x1,int y1,int x,int y) 
  		{ 
	  		putpixel(x1+x,y1+y,color); 
 			putpixel(x1+x,y-y1,color); 
			putpixel(x-x1,y1+y,color); 
			putpixel(x-x1,y-y1,color); 
			putpixel(x+y1,y+x1,color);
			putpixel(x+y1,y-x1,color);
			putpixel(x-y1,y+x1,color);
			putpixel(x-y1,y-x1,color); 
     	} 
};

int main()
{
	int gd = DETECT, gm, left=200, top=100, right=200, bottom=200, x=300, y=150, radius=50, color;
	int ch, x1, y1;
	char a;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	dcircle cir;
	do
	{
	cout<<"\nMenu:";
	cout<<"\n1.Bresenham's circle";
	cout<<"\n2.Exit.";
	cout<<"\nEnter choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cleardevice();
			cout<<"\n Enter x co-ordinate:";
			cin>>x1;
			cout<<"\n Enter y co-ordinate:";
			cin>>y1;
			cout<<"\n Enter radius:";
			cin>>radius;
			cout<<"\n Enter color:(Integer value: 1 to 15)";
			cin>>color;
			cir.setCircle(x1,y1,radius,color);
			cir.drawCir(radius);
		    break;
		
		case 2:
			cout<<"\nExiting...\n";
			exit(0);
		    break;
	} 
 	}while(ch!=2);
	delay(3000);
	getch();
	closegraph();
	return 0;
}