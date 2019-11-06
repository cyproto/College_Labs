import java.io.*;
import java.net.*;
import java.math.*;
import java.util.*;

class client
{
	public static void main(String args[])throws IOException
	{
		InetAddress addr=InetAddress.getByName("Localhost");
		System.out.println(addr);
		Socket connection=new Socket(addr,5000);
		BufferedInputStream in=new BufferedInputStream(connection.getInputStream());
		DataOutputStream out=new DataOutputStream(connection.getOutputStream());
		Scanner scr=new Scanner(System.in);
		System.out.println(" client is Connected to server" + addr);
		System.out.println("Enter the number of frames to be requested to the server");
		int c=scr.nextInt();
		out.write(c);
		out.flush();
		System.out.println("Enter the type of transmission, [Without error/With error(Enter 0|1)]:");
		int choice=scr.nextInt();
		out.write(choice);
		int check=0;
		int i=0;
		int j=0;
		if(choice==0)
		{
			for(j=0;j<c;++j)
			{
				i=in.read();
				System.out.println("Received frame no: "+i);
				System.out.println("Sending acknowledgement for frame no: "+i);
				out.write(i);
				out.flush();
			}
			out.flush();
		}
		else
		{
			for(j=0;j<c;++j)
			{
				i=in.read();
				if(i==check)
				{
					System.out.println("Received frame no: "+i);
					System.out.println("Sending acknowledgement for frame no: "+i);
					out.write(i);
					++check;
				}
				else
				{
					--j;
					System.out.println("Discarded frame no: "+i);
					System.out.println("Sending negative acknowledgement");
					out.write(-1);
				}
				out.flush();
			}
		}
	in.close();
	out.close();
	}
}