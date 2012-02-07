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
    int store(Contact & putintable);

    int Edit();

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
    Contact * hasher;
    node * next;
};



class Table
{
public:
    //Constructor/Destructor
    Table();
    Table(int tablesize);
    ~Table();

    //Adds a new task to the list
    int insert(char * & key, Contact & addthis);
    int retrieve(char * key);


private:

    int maxsize;
    node ** ht; //pointer to my hash table to be



};
