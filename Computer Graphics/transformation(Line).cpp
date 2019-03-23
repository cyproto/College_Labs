#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int pi[10];
double b[3][3]={1,0,0,0,1,0,0,0,1};
int c[1][1];
float a[1][1];

void matmul(float p[10])
{
    int i;
    for(i=0;i<9;i=i+2)
    {
		a[0][0]=p[i];
		a[0][1]=p[i];
		c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0];
		c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1];
		pi[i]=c[0][0];
		pi[i+1]=c[0][1];
	}
}
void nomul(float p[10])
{
	int i;
	for(i=0;i<9;i=i+2)
    {
		a[0][0]=p[i];
		a[0][1]=p[i];
		c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+0;
		c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+0;
		pi[i]=c[0][0];
		pi[i+1]=c[0][1];
	}
}
int main()
{
    int i,x,y,tx,ty,sx,sy,angle=10,xmax,ymax,xmid,ymid,op;
    int gd,gm=VGAMAX;gd=DETECT;
    float p1[10]={50,50,100,50,100,100,50,100,50,50};
    initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
    do
    {
		xmax=getmaxx();
		ymax=getmaxy();
		xmid=xmax/2;
		ymid=ymax/2;
		setcolor(0);
		line(xmid,0,xmid,ymax);
		line(0,ymid,xmax,ymid);
		setcolor(0);
		for(i=0;i<8;i=i+2)
		{
	    	line(p1[i]+xmid,ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]);
		}
		nomul(p1);
		setcolor(0);
		for(i=0;i<8;i=i+2)
		{
		    line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]);
		}
	    cout<<"\nMenu: ";
	    cout<<"\n1.Translation.";
	    cout<<"\n2.Rotation.";
	    cout<<"\n3.Scaling.";
	    cout<<"\n4.Exit.";
	    cout<<"\nEnter choice:";
	    cin>>op;
	    switch(op)
	    {
        	case 1: 
        	    	cout<<"\nEnter x translation: ";
		        	cin>>tx;
		        	cout<<"\n Enter y translation: ";
		        	cin>>ty;
		        	b[0][0]=1;
	            	b[0][1]=0;
		        	b[0][2]=0;
		        	b[1][0]=0;
		        	b[1][1]=1;
		        	b[1][2]=0;
		        	b[2][0]=tx;
		        	b[2][1]=ty;
		        	b[2][2]=1;		             
		        	cleardevice();
	            	break;         
        	
        	case 2:
            	    cout<<"\n Enter Rotation angle: ";
			        cin>>angle;
		        	b[0][0]=cos(angle*3.142/180);
		        	b[0][1]=sin(angle*3.142/180);
		        	b[0][2]=0;
		        	b[1][0]=-sin(angle*3.142/180);
		        	b[1][1]=cos(angle*3.142/180);
		        	b[1][2]=0;
		        	b[2][0]=0;
		        	b[2][1]=0;
		        	b[2][2]=1;
		        	cleardevice();
		        	break;

        	case 3:   
	            	cout<<"\n Enter x scaling: ";
	            	cin>>sx;		             
	            	cout<<"\n Enter y scaling: ";
	            	cin>>sy;
	            	b[0][0]=sx;
	            	b[0][1]=0;
	            	b[0][2]=0;
	            	b[1][0]=0;
	            	b[1][1]=sy;
	            	b[1][2]=0;
	            	b[2][0]=0;
	            	b[2][1]=0;
	            	b[2][2]=1;
	            	cleardevice();
	            	break;

	    	case 4:
	     			cout<<"\nExiting...\n";
		     		exit(0);
	     			break;

	     	default:	
	     			cout<<"\nInvalid";
   		}
		xmax=getmaxx();
		ymax=getmaxy();
		xmid=xmax/2;
		ymid=ymax/2;
		setcolor(0);
		line(xmid,0,xmid,ymax);
		line(0,ymid,xmax,ymid);
		setcolor(0);
		for(i=0;i<8;i=i+2)
		{
		    line(p1[i]+xmid,ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]);
		}
		matmul(p1);
		setcolor(0);
		for(i=0;i<8;i=i+2)
		{
	    	line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]);
		}	
	}while(op!=4);
getch();
closegraph();
return 0;
}
