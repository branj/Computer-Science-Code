#include <iostream>
using namespace std;
int service();
float initial();
float tip(int, float);
void percentage (float &);
void total(float, float&);



int main ()
{
    float a;
    float c; 
    float g;
    float q;
    
    
    c = initial();
    a = service();
    percentage (a);
    total (c, a); 
    cout << "According to your information you should tip: $" << a;
    cin >> q; 

     
    
    
    
    
    return 0;
    
}

float initial()
{
      float total;
      cout << "Please enter the price of your meal:";
      cin  >> total; 
      return total;
}
      

int service()
{
    int b;
     cout << "So, how good was your server today?\n\n"
          << "1. Great!\n"
          << "2. Alright.\n"
          << "3. Horrible.\n";
     cin  >> b;
     
     return b; 
}

void percentage (float &f)
{
     if (f == 1) 
     {
        f = .2;
        }
     else if (f == 2)
     {
          f = .15;
          }
     else if (f == 3)
     {
          f = .1;
          }
}

void total (float g, float &f)
{
     f = g * f; 
}
     
