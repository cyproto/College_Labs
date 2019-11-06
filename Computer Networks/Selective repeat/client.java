import java.lang.System;
import java.net.*;
import java.io.*;

public class client {
	static Socket connection;

	public static void main(String a[]) throws SocketException 
	{
		try 
		{
			int v[] = new int[8];
			int n = 0;
			InetAddress addr = InetAddress.getByName("Localhost");
			System.out.println(addr);
			connection = new Socket(addr, 4200);
			DataOutputStream out = new DataOutputStream(connection.getOutputStream());
			DataInputStream in = new DataInputStream(connection.getInputStream());
			int p = in.read();
			System.out.println("No of frames are:" + p);
			System.out.print("Data: ");
			for (int i = 0; i < p; i++) 
			{
				v[i] = in.read();
				System.out.print("\t"+v[i]);
			}
			System.out.println();
			v[5] = -1;//generate error.
			for (int i = 0; i < p; i++)
			{
					System.out.println("Received frame is: " + v[i]);

			}
			for (int i = 0; i < p; i++)
				if (v[i] == -1) 
				{
					System.out.println("Request to retransmit packet no "+(i+1)+" again.");
					n = i;
					out.write(n);
					out.flush();
				}
				System.out.println();
				v[n] = in.read();
				System.out.println("Data in retransmitted frame is: " + v[n]);
		}
		catch (Exception e) {
		System.out.println(e);
		}
	}
}