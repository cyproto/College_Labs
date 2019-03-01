package rect; 
import java.util.*; 
public class ShapeArea 
{ 
	public void circleArea() 
	{ 
		Scanner s=new Scanner(System.in); 
		System.out.println("Enter radius of circle"); 
		int r=s.nextInt(); 
		System.out.println("Area of circle="+(3.14*r*r)); 
	} 
	 
	public void rectArea() 
	{ 
		Scanner s=new Scanner(System.in); 
		System.out.println("Enter length of rectangle"); 
		int l=s.nextInt(); 
		System.out.println("Enter breadth of rectangle"); 
		int b=s.nextInt(); 
		System.out.println("Area of rectangle="+(l*b)); 
	} 
	public void triangleArea() 
	{ 
		Scanner s=new Scanner(System.in); 
		System.out.println("Enter base of triangle"); 
		int b=s.nextInt(); 
		System.out.println("Enter height of triangle"); 
		int h=s.nextInt(); 
		System.out.println("Area of triangle="+(0.5*h*b)); 
	} 
}