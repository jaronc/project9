#include <iostream>
#include "stack.h"

int main()
{
  Stack Kappa(5);
  if(Kappa.empty())
    cout << "empt" << endl;
  Kappa.push('a');
  Kappa.push('b');
  Kappa.push('c');
  Kappa.push('d');
  Kappa.push('e');
  if(Kappa.full())
    cout << "Keppo" << endl;
  Stack Kappa2(Kappa);
  cout << Kappa;
  cout << Kappa2;
  if(Kappa == Kappa2)
    {
      cout << "yes" << endl;
    }
  char woo;
  Kappa.pop(woo);
  cout << Kappa << woo << endl;
  Kappa.clear();
  if(Kappa.empty())
    {
      cout << "empt" << endl;
    }
  Kappa.push('d');
  Kappa.pop(woo);
  cout << Kappa;
  
}
