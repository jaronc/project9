#include <iostream>
#include "queue.h"

int main()
{
  Queue Kappa;
  if(Kappa.empty())
    cout << "empt" << endl;
  for(int i = 0; i < 10; i++)
    {
      if(!Kappa.enqueue(i))
	cout << "full" << endl;
    }
  if(Kappa.full())
    cout << "Keppo" << endl;
  Queue Kappa2(Kappa);
  cout << Kappa;
  cout << Kappa2;
  if(Kappa == Kappa2)
    {
      cout << "yes" << endl;
    }
  
}
