///A Simple Web Server (WebServer.java)

package http.server;

import java.io.BufferedReader;
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
 * @author Jeff Heaton
 * @version 1.0
 */
public class WebServerBACKUP {

	String chemin = "H:\\progReseau\\tpReseauHTTP\\src\\";
	
	/**
	 * WebServer constructor.
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
						String demande = str.substring("GET /".length(), str.length()-" HTTP/1.1".length());
						if (str.substring(0, 3).equals("GET") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1")) {
							getManage(demande, outBin);
						}
						else if (str.substring(0, 4).equals("HEAD") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1")) {
							headManage(demande, outBin);
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



	protected void getManage(String demande, PrintStream outBin)
	{
		try
		{
			Path p = FileSystems.getDefault().getPath(chemin, demande);
			byte [] fileData = Files.readAllBytes(p);
			// header
			outBin.println("HTTP/1.0 200 OK");
			outBin.println("Content-Type: image");
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

	protected void headManage(String demande, PrintStream outBin) 
	{
		System.out.println("On entre dans HEAD manage ()");
		try
		{
			Path p = FileSystems.getDefault().getPath(chemin, demande);
			byte [] fileData = Files.readAllBytes(p);
			// header
			outBin.println("HTTP/1.0 200 OK");
			outBin.println("Content-Type: image");
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
