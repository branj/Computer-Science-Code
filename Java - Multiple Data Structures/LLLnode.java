//Serdar Numanoglu
//Cs 202 , Program #4
//CLLnode , node class for CLL
//CLLnode.java

import java.io.*;
import java.util.*;

public class LLLnode extends Art
{
	private LLLnode next;
	private Art data;

	public LLLnode()
	{
		next = null;
	}

	public LLLnode(Art newData, LLLnode newNext)
	{
		next = newNext;
		data = newData;
	}

	public void setData(Art obj)
	{
		data = new Art();

		data.artistName = obj.artistName;
		data.date = obj.date;
		data.mediaType = obj.mediaType;
		data.availability = obj.availability;
	}

	public void setNext(LLLnode newNode)
	{
		next = newNode;
	}

	public Art getData()
	{
		return data;
	}

	public LLLnode getNext()
	{
		return next;
	}

	public void display()
	{
		data.display();
	}

	public boolean compare(Art dataArt)
	{
		return this.data.compareMedia(dataArt);
	}

}

