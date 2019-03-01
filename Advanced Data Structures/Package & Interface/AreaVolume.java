import java.util.*; 
import rect.ShapeArea; 
class AreaVolume implements Volume 
{ 
	public void cylinder() 
	{ 
		Scanner s=new Scanner(System.in); 
		System.out.println("Enter radius of cylinder"); 
		int r=s.nextInt(); 
		System.out.println("Enter height of cylinder"); 
		int h=s.nextInt(); 
		System.out.println("volume of cylinder="+(3.14*h*r*r)); 
	} 
	public void cube() 
	{ 
		Scanner s=new Scanner(System.in); 
		System.out.println("Enter side of cube"); 
		int si=s.nextInt(); 
		System.out.println("volume of cube="+(si*si*si)); 
	} 
	public void cone() 
	{ 
		Scanner s=new Scanner(System.in); 
		System.out.println("Enter radius of cone"); 
		int r=s.nextInt(); 
		System.out.println("Enter height of cone"); 
		int h=s.nextInt(); 
		System.out.println("volume of cone="+(0.33*3.14*h*r*r)); 
	} 
	public static void main(String args[]) 
	{ 
		AreaVolume av=new AreaVolume(); 
		Volume v;	//reference variable of interface volume 
		ShapeArea a = new ShapeArea();	//reference variable of base class 
		 
		a.circleArea(); 
		a.rectArea(); 
		a.triangleArea(); 
		v=av;		//runtime polymorphism 
		v.cylinder(); 
		v.cube(); 
		v.cone(); 
	} 
} 
