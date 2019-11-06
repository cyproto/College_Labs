import java.io.*;
import java.net.*;
import java.util.*;
class server
{
	public static void main(String args[])throws IOException
	{
		System.out.println("server Waiting for connection....");
		InetAddress addr=InetAddress.getByName("Localhost");
		ServerSocket ss=new ServerSocket(5000);
		Socket client=new Socket();
		client=ss.accept();
		BufferedInputStream in=new BufferedInputStream(client.getInputStream());
		DataOutputStream out=new DataOutputStream(client.getOutputStream());
		System.out.println("Received request for sending frames");
		int p=in.read();
		boolean f[]=new boolean[p];
		int pc=in.read();
		System.out.println("Sending....");
		if(pc==0)
		{
			for(int i=0;i<p;++i)
			{
				System.out.println("Sending frame number "+i);
				out.write(i);
				out.flush();
				System.out.println("Waiting for acknowledgement");
				try
				{
					Thread.sleep(1000);
				}
				catch(Exception e){
					
				}
				int a=in.read();
				System.out.println("Received acknowledgement for frame "+i+" as "+a);
			}
			out.flush();
		}
		else
		{
			for(int i=0;i<p;++i)
			{
				if(i==2)
				{
					System.out.println("Sending frame no "+i);
					//don't actually send the frame 2 to generate an error
				}
				else
				{
					System.out.println("Sending frame no "+i);
					out.write(i);
					out.flush();
					System.out.println("Waiting for acknowledgement ");
					try
					{
						Thread.sleep(1000);
					}
					catch(Exception e){
						
					}
					int a=in.read();
					if(a!=255)
					{
						System.out.println("Received acknowledgement for frame no: "+i+" as "+a);
						f[i]=true;
					}
				}
			}
			for(int a=0;a<p;++a)
			{
				if(f[a]==false)
				{
					System.out.println("Resending frame "+a);
					out.write(a);
					out.flush();
					System.out.println("Waiting for acknowledgement ");
					try
					{
						Thread.sleep(1000);
					}
					catch(Exception e){
						
					}
					int b=in.read();
					System.out.println("Received acknowledgement for frame no: "+a+" as "+b);
					f[a]=true;
				}
			}
			out.flush();
		}
	in.close();
	out.close();
	ss.close();
	client.close();
	}
}