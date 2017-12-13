///A Simple Web Server (WebServer.java)

package http.server;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
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
public class WebServerBackup2 {

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
				PrintWriter out = new PrintWriter(remote.getOutputStream());
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
						if (str.substring(0, 3).equals("GET") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1"))
						{
							getManage(demande, out, outBin);
						}
						else if (str.substring(0, 4).equals("HEAD") && str.substring(str.length()-"HTTP/1.1".length(), str.length()).equals("HTTP/1.1"))
						{
							headManage(demande, out);
						}
					}


					out.flush();
					outBin.flush();
					remote.close();
				} 
			}
			catch (Exception e) {
				System.out.println("Error: " + e);
			}
		}
	}



	protected void getManage(String demande, PrintWriter out, PrintStream outBin) 
	{
		String extension = null;
		for (int i = demande.length()-1; i > 0; i--)
		{
			if (demande.charAt(i) == '.')
			{
				extension = demande.substring(i+1,demande.length());
				break;
			}
		}
		if ( extension == null )
		{
			extension = "txt";
		}

		if ( extension.equals("html") || extension.equals("txt")  || extension.equals("js") )
		{

			try (BufferedReader br = new BufferedReader(new FileReader("H:\\Mes documents\\3IF\\eclipse\\tpReseauHTTP\\src\\" + demande)))
			{	//header http
				out.println("HTTP/1.0 200 OK");
				out.println("Content-Type: text/html");
				out.println("Server: Bot");
				//plus le header
				out.println("");

				//send the file
				StringBuffer sb = new StringBuffer();
				String line = br.readLine();
				while( line != null )
				{
					sb.append(line + "<br />");
					line = br.readLine();
				}
				out.println(sb);
			} catch (IOException e)
			{ //404
				out.println("HTTP/1.0 404 Not Found");
				out.println("Content-Type: text/html");
				out.println("");
				out.println("<p>Ceci est une 404 :/ </p>");
			}
		}

		else if (extension.equals("jpg") || extension.equals("png"))
		{
			try
			{
				Path p = FileSystems.getDefault().getPath("H:\\Mes documents\\3IF\\eclipse\\tpReseauHTTP\\src\\", demande);
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
				out.println("HTTP/1.0 404 Not Found");
				out.println("Content-Type: text/html");
				out.println("");
				out.println("<p>Ceci est une 404 :/ </p>");
			}
		}
	}

	protected void headManage(String demande, PrintWriter out) 
	{
		try (BufferedReader br = new BufferedReader(new FileReader("H:\\Mes documents\\3IF\\eclipse\\tpReseauHTTP\\src\\" + demande)))
		{	//header http
			out.println("HTTP/1.0 200 OK");
			out.println("Content-Type: text/html");
			out.println("Server: Bot");
		} catch (IOException e)
		{	//404
			out.println("HTTP/1.0 404 Not Found");
			out.println("Content-Type: text/html");
		}
	}



	/**
	 * Start the application.
	 * 
	 * @param args
	 *            Command line parameters are not used.
 */
public static void main(String args[]) {
	WebServerBackup2 ws = new WebServerBackup2();
	ws.start();
}
}
