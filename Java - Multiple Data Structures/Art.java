//Serdar Numanoglu
//Cs 202 , Program #5
//Base class:Art.java

import java.io.*;
import java.util.*;

public  class Art implements Cloneable
{
	protected String artistName;
	protected String date; //start date
	protected String mediaType; //painting , photograph or sculpture
	protected String availability; // is it sold or shown

	//Default Const
	public Art()
	{
		artistName = "No task number yet";
		date = "No name yet";
		mediaType = "No type yet";
		availability = "No info yet";
	}

	//CONSTRUCTOR WITH args
	public Art(String initialArtistName, String initialDate, String initialMediaType,
				String initialAvailability)
	{
		artistName = initialArtistName;
		date = initialDate;
		mediaType = initialMediaType;
		availability = initialAvailability;
	}

	public void setArtistName(String artistName)
	{
		this.artistName = artistName;
	}

	public void setDate(String date)
	{
		this.date = date;
	}

	public void setMediaType(String mediaType)
	{
		this.mediaType = mediaType;
	}

	public void setAvailability(String availability)
	{
		this.availability = availability;
	}

	public boolean compareMedia(Art obj)
	{
		if (mediaType.equals(obj.mediaType))
		{
					return true; //if they are equal
				}
				else
				{System.out.println("farkli");
					return false; //if they are NOT equal
				}
	}

    public void display()
    {
		System.out.println("Task Number: " + artistName);
	    System.out.println("Task Name: " + date);
		System.out.println("This task is assigned for: " + mediaType);
		System.out.println("Task information: " + availability);
	    System.out.println();

    }


    public boolean equals(Art obj) //check if the objects are equal or NOT
    {
		//I am not comparing the task number, I am comparing if the tasks are the same.
	   return ((this.artistName.equalsIgnoreCase(obj.artistName))
	           && (this.date.equalsIgnoreCase(obj.date))
			   && (this.mediaType.equalsIgnoreCase(obj.mediaType))
			   && (this.availability.equalsIgnoreCase(obj.availability)));
	}

	protected Art clone()
	{
		Art obj = new Art();

		obj.artistName = artistName;
		obj.date = date;
		obj.mediaType = mediaType;
		obj.availability = availability;

		return obj;
	}


}
//end of Art class

//Derived class from Art CLASS
abstract class ArtAbtstract extends Art
{

	public abstract void print();

}

class Painting extends ArtAbtstract
{
	public Painting(String initialArtistName, String initialDate, String initialMediaType,
					String initialAvailability)
	{
			artistName = initialArtistName;
			date = initialDate;
			mediaType = initialMediaType;
			availability = initialAvailability;
	}

	public void print()
	{
		display();
		System.out.println("Painting art is on Wed and Sunday...");
	}
}

class Photograph extends ArtAbtstract
{
	public Photograph(String initialArtistName, String initialDate, String initialMediaType,
					  String initialAvailability)
	{
		artistName = initialArtistName;
		date = initialDate;
		mediaType = initialMediaType;
		availability = initialAvailability;
	}

	public void print()
	{
		display();
		System.out.println("Black and White Photography");
	}
}

class Sculpture extends ArtAbtstract
{
	public Sculpture(String initialArtistName, String initialDate, String initialMediaType,
						String initialAvailability)
	{
		artistName = initialArtistName;
		date = initialDate;
		mediaType = initialMediaType;
		availability = initialAvailability;
	}

	public void print()
	{
		display();
		System.out.println("Clay and Metal sculpture are shown ... On Sundays");
	}
}

