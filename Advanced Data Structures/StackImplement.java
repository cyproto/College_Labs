import java.util.*;
class arrayStack
{
    protected int arr[];
    protected int top, size, len;
    public arrayStack(int n)
    {
        size = n;
        len = 0;
        arr = new int[size];
        top = -1;
    }
    public boolean isEmpty()
    {
        return top == -1;
    }
    public boolean isFull()
    {
        return top == size -1 ;        
    }
    public int getSize()
    {
        return len ;
    }
    public int peek()
    {
        if( isEmpty() )
            throw new NoSuchElementException("Underflow.");
        return arr[top];
    }
    public void push(int i)
    {
        if(top + 1 >= size)
            throw new IndexOutOfBoundsException("Overflow.");
        if(top + 1 < size )
            arr[++top] = i;
        len++ ;
    }
    public int pop()
    {
        if( isEmpty() )
            throw new NoSuchElementException("Underflow.");
        len-- ;
        return arr[top--]; 
    }    
    public void display()
    {
        System.out.print("\nStack = ");
        if (len == 0)
        {
            System.out.print("Empty\n");
            return ;
        }
        for (int i = top; i >= 0; i--)
            System.out.print(arr[i]+" ");
        System.out.println();
    }    
}
public class StackImplement
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);        
        System.out.println("Enter Size of Integer Stack: ");
        int n = scan.nextInt();
        arrayStack stk = new arrayStack(n);
        int choice;
		do{
            System.out.println("\nStack Operations: ");
            System.out.println("1. Push.");
            System.out.println("2. Pop.");
            System.out.println("3. Top Element.");
            System.out.println("4. Check if empty.");
            System.out.println("5. Check if full.");
            System.out.println("6. Size of stack.");
			System.out.println("7. Exit.");
            choice = scan.nextInt();
            switch (choice)
            {
            case 1 : 
                System.out.println("Enter integer element to push: ");
                try 
                {
                    stk.push( scan.nextInt() );
                }
                catch (Exception e)
                {
                    System.out.println("Error : " + e.getMessage());
                }                         
                break;
				
            case 2 : 
                try
                {
                    System.out.println("Popped Element = " + stk.pop());
                }
                catch (Exception e)
                {
                    System.out.println("Error : " + e.getMessage());
                }    
                break;                         
				
            case 3 :         
                try
                {
                    System.out.println("Top Element = " + stk.peek());
                }
                catch (Exception e)
                {
                    System.out.println("Error : " + e.getMessage());
                }
                break;                         
				
            case 4 : 
                 	System.out.println("Empty status = " + stk.isEmpty());
                break;                
				
            case 5 :
                	System.out.println("Full status = " + stk.isFull());
                break;                 
				
            case 6 : 
                  	System.out.println("Size = " + stk.getSize());
                break;                         
				
			case 7:
					System.out.println("Exiting...");
					break;
					
            default : 
                  	System.out.println("Wrong Entry \n ");
                break;
            }
            stk.display();            
        } while (choice != 7);                 
    }
}