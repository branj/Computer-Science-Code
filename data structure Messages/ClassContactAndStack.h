//Class list header file
//tasklist.h


class Contact
{
   public:
   //Constructors
   Contact();
   ~Contact();
   
   //Accepts data types from client to populate Contact instance.
   int populate(char* contacttype, char* tyme, char* emailnumber, char* con);
   
   //Used when working from inside the Contact class
   int store(Contact & putinstack);
   
   //Displays a contact
   int Display(); 
   
   
   private:
   char * contact;
   char * time;
   char * emailornumber;
   char * contactinfo;
};
     
   
   
struct node
{
  Contact * array;
  node * next;
};



class Stack
{
      public:
      //Constructor/Destructor       
      Stack();
      ~Stack();
      
      //Adds a new task to the list
      int Push (Contact & addthis); 
      
      int Display(); 
      
      //Removes top of the stack
      int Pop();
      
      //Finds the top
      int Peek();

      private:
              
      node * head;
      int top;
      int maxsize;
     
};
