///A Simple Web Server (WebServer.java)

package http.server;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;

/**
 * Example program from Chapter 1 Programming Spiders, Bots and Aggregators in
 * Java Copyright 2001 by Jeff Heaton
 * 
 * WebServer is a very simple web-server. Any request is responded with a very
 * simple web-page.
 * 
 * Web server updated by B3405 to manage GET, HEAD, DELETE and POST requests
 * 
 * @author Gregoire et Etienne
 * @version 2.0
 */
public class WebServer {
	String chemin = "H:\\progReseau\\tpReseauHTTP\\src\\";
	
	/**
	 * WebServer constructor.
	 * 
	 * This method handle the header of the request and call for the appropriate manager
	 */
	protected void start() {
		ServerSocket s;

		System.out.println("Webserver starting up on port 3000");
		System.out.println("(press ctrl-c to exit)");
		try {
			// create the main server socket
			s = new ServerSocket(3000);
		} catch (Exception e) {
			System.out.println("Error: " + e);
			return;
		}

		System.out.println("Waiting for connection");
		for (;;) {
			try
			{
				// wait for a connection
				Socket remote = s.accept();
				// remote is now the connected socket
				System.out.println("Connection, sending data.");
				BufferedReader in = new BufferedReader(new InputStreamReader(
						remote.getInputStream()));
				PrintStream outBin = new PrintStream(remote.getOutputStream());


				// read the data sent. We basically ignore it,
				// stop reading once a blank line is hit. This
				// blank line signals the end of the client HTTP
				// headers.
				String str = ".";
				while (!str.equals(""))
				{
					str = in.readLine();
					if (str.length() > "GET  HTTP/1.1".length())
					{
						String demande = " ";

						if (str.substring(0, 3).equals("GET") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1")) {
							demande = str.substring("GET /".length(), str.length()-" HTTP/1.1".length());
							String fileType = "Unknown";
							while (!str.equals("\r\n") && !str.equals("") && str != null)
							{
								str = in.readLine();
								System.out.println(str);
								if (str.length() >= "Content-Type: ".length())
								{
									if (str.substring(0, "Content-Type: ".length()).equals("Content-Type: "))
									{
										fileType = str.substring("Content-Type: ".length());
									}
								}
							}
							getManage(fileType, demande, outBin);
						}
						else if (str.substring(0, 4).equals("HEAD") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1")) {
							demande = str.substring("HEAD /".length(), str.length()-" HTTP/1.1".length());
							String fileType = "Unknown";
							while (!str.equals("\r\n") && !str.equals("") && str != null)
							{
								str = in.readLine();
								System.out.println(str);
								if (str.length() >= "Content-Type: ".length())
								{
									if (str.substring(0, "Content-Type: ".length()).equals("Content-Type: "))
									{
										fileType = str.substring("Content-Type: ".length());
									}
								}
							}
							headManage(fileType, demande, outBin);
						}
						else if (str.substring(0, 4).equals("POST") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1"))
						{
							int bodySize = 0;

							demande = str.substring("POST /".length(), str.length()-" HTTP/1.1".length());
							
							System.out.println("Premier while post");
							while (!str.equals("\r\n") && !str.equals("") && str != null)
							{
								str = in.readLine();
								System.out.println(str);
								if (str.length() >= "content-length: ".length())
								{
									if (str.substring(0, "content-length: ".length()).equals("content-length: "))
									{
										String tmp = str.substring("Content-length: ".length());
										bodySize = Integer.parseInt(tmp);
									}
								}
							}
							System.out.println("sortie du 1er while");
							
							str = "bah bravo Niels";
							
							char [] buf = new char [bodySize];

							for(int i=0; i< bodySize; i++) {
								
								buf[i] = (char) in.read();
							}
							System.out.println("sortie du 2nd while");
							postManage(demande, buf, outBin);
						}
						
						else if (str.substring(0, 6).equals("DELETE") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1"))
						{
							demande = str.substring("DELETE /".length(), str.length()-" HTTP/1.1".length());
							String fileType = "Unknown";
							while (!str.equals("\r\n") && !str.equals("") && str != null)
							{
								str = in.readLine();
								System.out.println(str);
								if (str.length() >= "Content-Type: ".length())
								{
									if (str.substring(0, "Content-Type: ".length()).equals("Content-Type: "))
									{
										fileType = str.substring("Content-Type: ".length());
									}
								}
							}
							deleteManage(fileType, demande, outBin);
						}
					}
					outBin.flush();
					remote.close();
				}
			}
			catch (Exception e) {
				System.out.println("Error: " + e);
				e.printStackTrace();
			}
		}
	}

	/**
	 * This method manage POST requests
	 * 
	 * @param demande A {@link String} that contain the access path to the requested file 
	 * @param corps A char [] that contain the body of the request
	 * @param outBin A {@link PrintStream} used to send the response of the request
	 */
	protected void postManage(String demande, char [] corps, PrintStream outBin)
	{
		System.out.println("On entre dans POST manage ()\n" + corps.toString());
		try
		{	
			FileOutputStream f = new FileOutputStream(demande, true);
			f.write(new String(corps).getBytes());
			f.close();
			outBin.println("HTTP/1.0 200 OK");
		} catch (Exception e)
		{ 	//404
			outBin.println("HTTP/1.0 404 Not Found");
			outBin.println("Content-Type: text/html");
			outBin.println("");
			outBin.println("<p>Ceci est une 404 :/ </p>");
		}
		System.out.println("On sort de POST manage ()");
	}

	/**
	 * 
	 * This method manage GET requests
	 * 
	 * @param fileType A {@link String} that contain the type of the requested file, if it is gave in the request
	 * @param demande A {@link String} that contain the access path to the requested file 
	 * @param outBin A {@link PrintStream} used to send the response of the request
	 */
	protected void getManage(String fileType, String demande, PrintStream outBin)
	{
		try
		{
			Path p = FileSystems.getDefault().getPath(chemin, demande);
			byte [] fileData = Files.readAllBytes(p);
			// header
			outBin.println("HTTP/1.0 200 OK");
			outBin.println("Content-Type: " + fileType);
			outBin.println("Server: Bot");
			// content
			outBin.println("");
			outBin.write(fileData);

		} catch (IOException e)
		{ 	//404
			outBin.println("HTTP/1.0 404 Not Found");
			outBin.println("Content-Type: text/html");
			outBin.println("");
			outBin.println("<p>Ceci est une 404 :/ </p>");
		}
	}
	
	/**
	 * 
	 * This method manage DELETE requests
	 * 
	 * @param fileType A {@link String} that contain the type of the requested file, if it is gave in the request
	 * @param demande A {@link String} that contain the access path to the requested file 
	 * @param outBin A {@link PrintStream} used to send the response of the request
	 */
	protected void deleteManage(String fileType, String demande, PrintStream outBin)
	{
		System.out.println("On entre dans DELETE manage ()");
		try
		{
			File f = new File(chemin+demande);
			f.delete();
			
			// header
			outBin.println("HTTP/1.0 200 OK");
			outBin.println("Content-Type: " + fileType);
			outBin.println("Server: Bot");
			outBin.println("");
		} catch (Exception e)
		{ 	//404
			outBin.println("HTTP/1.0 404 Not Found");
			outBin.println("Content-Type: text/html");
			outBin.println("");
		}
	}

	/**
	 * 
	 * This method manage HEAD requests
	 * 
	 * @param fileType A {@link String} that contain the type of the requested file, if it is gave in the request
	 * @param demande A {@link String} that contain the access path to the requested file 
	 * @param outBin A {@link PrintStream} used to send the response of the request
	 */
	protected void headManage(String fileType, String demande, PrintStream outBin) 
	{
		System.out.println("On entre dans HEAD manage ()");
		try
		{
			Path p = FileSystems.getDefault().getPath(chemin, demande);
			byte [] fileData = Files.readAllBytes(p);
			// header
			outBin.println("HTTP/1.0 200 OK");
			outBin.println("Content-Type: " + fileType);
			outBin.println("Server: Bot");
			outBin.println("");

		} catch (IOException e)
		{ 	//404
			outBin.println("HTTP/1.0 404 Not Found");
			outBin.println("Content-Type: text/html");
			outBin.println("");
		}
	}



	/**
	 * Start the application.
	 * 
	 * @param args
	 *            Command line parameters are not used.
	 */
	public static void main(String args[]) {
		WebServer ws = new WebServer();
		ws.start();
	}
}
