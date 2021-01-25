void print()
{
  const int rowstoprint = 27;   //Max 27

  //Clear Page:
  if(clearscreen)
    {
      for(int i(0); i<50; i++)
	{
	  cout << endl;
	}
    }
  
  //Welcome:
  if(score==0)
    {
      cout << "***  WELCOME TO PACMAN  ***\n" << endl;
      cout << "Game Command Controls:\n";
      cout << "Left: a\n";
      cout << "Right: d\n";
      cout << "Up: w\n";
      cout << "Down: s\n";
      cout << endl << "Game Play Notes:\n";
      cout << "*Must press Enter to execute moves.\n";
      cout << "*If you wish Stats to be activated or disable clearscreen, enter 'stats' first.\n";
      cout << "*To activate statistics during game play, enter '?' as your play.\n";
      cout << endl;
      cout << "Difficulties: easy - normal - hard\n";
      cout << "Enter Difficulty: ";
      cin >> mode;

      if(mode == "stats")
	{
	  char ans;
	  cout << endl << endl << "Would you like stats to be activated? Y/N: ";
	  cin >> ans;
	  if(toupper(ans) == 'Y')
	    {
	      stats = true;
	      cout << "Game statistics has been activated for this game.\n\n";
	    }
	  else
	    cout << "Game statistics has will deactivated for this game.\n\n";
	   

	  cout << "Would you like clearscreen to be activated? Y/N: ";
	  cin >> ans;
	  if(toupper(ans) == 'N')
	    {
	      clearscreen = false;
	      cout << "Clearscreen has been deactivated for this game.\n\n";
	    }
	  else
	    cout << "Clearscreen has will activated for this game.\n\n";

	  cout << "Difficulties: easy - normal - hard\n";
	  cout << "Enter Difficulty: ";
	  cin >> mode;
	  
	  cout << endl << endl;
	}
    }
  
  //Print Bonus Time:
  if(bonustime)
    {
            cout << "** BONUS TIME ** Bonus Plays Remaining: " << bonusplays << " **\n" << endl;
    }
  //Print Dead:
  if(dead && !bonustime)
    {
            cout << "** You died ** You have " << lives << " lives remaining. **\n" << endl;
	    dead = false;
    }

  //Print Top Border
  for(x=0; x<86; x++)
    {
      cout << h;
    }
  cout << endl;

  cout << v << "  Play: " << playcount << "                            ";

  if(playcount-1<10)
    cout << "  ";
  else if(playcount-1<100)
    cout << " ";
  else
         cout << ""
	   ;
  cout << "LEVEL " << level << "                        ";

  if(level<10)
    cout << "  ";
  else if(level<100)
    cout << " ";
  else
    cout << "";


  if(score<10)
    cout << "  ";
  else if(score<100)
    cout << " ";
  else
    cout << "";

  cout << "Score: " << score;

  cout << "  " << v << endl << v << " ";

  //Print Middle Board
  for(y=0;y<(rowstoprint);y++)
    {
      for(x=0;x<82;x++)
	{
	  cout << board[y][x];
	}

      if(y==rowstoprint-1)
	cout << " " << v << endl;
      else
	cout << " " << v << endl << v << " ";

    }

  //Print Bottom Border
    cout << v << "  Lives Remaining: " << lives << "                                         ";

    if(coinsremaining<10)
      cout << "  ";
    else if(coinsremaining<100)
      cout << " ";
    else
      cout << "";

    cout << "Coins Remaining: " << coinsremaining;


    cout << "  " << v << endl;

    for(x=0; x<86; x++)
      {
	cout << h;
      }
    cout << endl;

    return;
}
