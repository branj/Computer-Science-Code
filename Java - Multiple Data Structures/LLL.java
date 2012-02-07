////////////////////////LLL CLASS//////////////////////////////////////////
public class LLL
{
	private LLLnode head;

	public LLL()
	{
		head = null;
	}

	public void add(Art dataArt)
	{
		LLLnode temp = new LLLnode();
		LLLnode current;// = new LLLnode();
		LLLnode previous; //= new LLLnode();

		temp.setData(dataArt); //copy the data

		if( head == null)
		{System.out.println("null");
			head = temp;
			//temp.next is already NULL so no need to assigned to null
		}
		else	//insert at head
		{
			if (head.compare(dataArt))//?????????????head.data.compareMedia(dataArt)
			{System.out.println("nfff");
				temp.setNext(head);
				head = temp;
			}
			else
			{
				current = head.getNext();
				previous = head;

				while( !((current.getNext() == null) && current.compareMedia(dataArt)) )
				{
					previous = current;
					current.setNext(current);
				}
//System.out.println("nfff");
				previous.setNext(temp);
				temp.setNext(current);
			}
		}
	}

	 public void display()
	 {
		 LLLnode temp ;
		 temp = head;
System.out.println("E");
		 while (temp != null)
	     {System.out.println("EMPTY");
           	temp.display();
          	temp.setNext(temp);
      	 }

	 }

public void yarak()
{
	System.out.println("amina koyim ");
}

public static void main(String[] args)
	 {
			 LLL head = new LLL();
			 LLL x = new LLL();


			 Art obj, obj1,obj2;
				obj = new Art("Mike","01/01/01","Painting","shown");

		obj1 = new Art("Mike","01/01/01","Painting","shown");//Art("Mustafa","02/02/02","Photograph","sold");
		obj2 = new Art("Ozzy","03-03-03", "Sculpture","shown");

		System.out.println("here is after creating the LLL");
		head.add(obj);
		head.add(obj1);
		head.add(obj2);
		head.display();




	 }

}