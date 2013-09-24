/*
 * This program grabs all the results on a Yelp page in no particular order
 * Edward Chen
 */

import java.io.*;
import java.net.*;
import org.jsoup.*;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class ResultScript {

	public static void main(String[] args) {
		try {
			/** Printing out HTML Source Code ***
			
			Document doc = 
			Jsoup.connect("http://www.yelp.com/search?cflt=food&find_loc=ucla#find_desc&attrs=RestaurantsPriceRange2.1,RestaurantsPriceRange2.2").get();
			String yelp = doc.html();
	        PrintStream out = new PrintStream(new FileOutputStream("yelp_results.txt"));
	        out.println(yelp);
	        out.close();
	        System.out.print("done");
	        **/
			Document doc = 
					Jsoup.connect("http://www.yelp.com/search?cflt=food&find_loc=ucla#find_desc&attrs=RestaurantsPriceRange2.1,RestaurantsPriceRange2.2").get();	
			// Selects media story division
			Elements yelp = doc.select("div.media-story");
			//Opens the text file to store the data
			PrintStream out = new PrintStream(new FileOutputStream("yelp_results.txt"));
			// Loop through all businesses on page and gather their titles
			for (Element business: yelp){
			   	Elements h3 = business.select("h3.search-result-title");
			   	out.println(h3.text());
			}
			out.close();
			System.out.print("done");
		} 
		catch (MalformedURLException e) { 
		    // new URL() failed
		    // ...
		} 
		catch (IOException e) {   
		    // openConnection() failed
		    // ...
		}
	}

}
