#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

#include "Constants.h"

//Note: Method Calls in main are in an intetional Order, that the previous affects some aspect of the following.
int main()
{
  setnewboard(); 
 
  while(lives!=0)
    {
      print();

      cout << "Enter Play: ";
      cin >> play;
      cout << endl;
      if(play == '?')
	{
	  stats = true;
	  clearscreen = false;
	  cerr << "Statistics for the remainder of the game have been activated and clearscreen has been deactivated.\n";
	  cout << "Enter Play: ";
	  cin >> play;
	  cout << endl;
	  move();
	}
      else
	move();

      playcount++;
      
      attempt = false;  //Prevents user for accidently colliding with an enemy from multiple inputs in the queue.
      
      if(clearscreen)
	{
	  clearscreen = false;
	  print();  //Shows Your Play
	  clearscreen = true;
	}
      else if(stats)
	print();
      
      if(bonustime)
	bonus();

      if(coinsremaining==0)
	levelup();

      ecm();     //Enemy Control Manager
     
      if(dead)
	died();

      if(coinsremaining==0)
	levelup();
          
    }

  print();     //Final Board.
  cout << endl << endl;
  cout << "You died your final death.\n\n";
  cout << "Thanks for playing!\n\n";
  cout << "Game Termination....\n";

  
  return 0;
}
