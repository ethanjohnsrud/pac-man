void levelup()
{
  if(stats)
    cerr << "Executing levelup for level " << level + 1 << endl;
  dead = false;
  tries = 0;
  level++;
  coinsremaining=startcoins;
  cy=15;
  cx=39;
  setnewboard();
 
  //Reset Enemies
  resetallenemies();
  
  return;
}

void died()
{
  if(stats)
    cerr << "Executing died method for death " << lives << endl;

  if(lives==1)    //Allow Final board to be printed.
    {
      lives--;
      return;
    }
  //Cancel Bonustime
  bonustime = false;
  currentenemycharacter = normalenemycharacter;
  bonusplays = -1;

  //Reset Enemies
  resetallenemies();
  
  //Reset Character
  tries = 0;
  lives--;

  board[cy][cx]  = s;

  cy=15;
  cx=39;

  board[cy][cx] = character;

  return;
}
  
void bonus()
{
  if(bonusplays<0)
    {
      currentenemycharacter = bonusenemycharacter;
      
      if(mode=="easy")
	bonusplays=easybonusplays;
      else if(mode=="hard")
	bonusplays=hardbonusplays;
      else     //normal
	bonusplays=normalbonusplays;
    }

    bonusplays--;

  if(bonusplays<=0)
    {
      bonustime = false;
      currentenemycharacter = normalenemycharacter;
      bonusplays = -1;
    }
  
  return;
}

void scorepoints(int r, int c)
{

  //Score Pionts:
  if(board[r][c]==d)
    {
      score++;
      coinsremaining--;
    }
  else if(board[r][c]=='O')
    {
      bonustime = true;
      score=score+50;
      coinsremaining--;
    }

  return;
}

bool flipsides(int& r, int& c)
{
  if(board[r][c]=='<')
    {
      board[cy][cx]=s;
      r = 13; 
      c = 78;
    }
  else if(board[r][c]=='>')
     {
      board[cy][cx]=s;
      r = 13;
      c = 3;
    }
  else
    return false;
  
  return true;
}

bool allowed(int& r, int& c)
{
  flipsides(r,c);

  if(stats)
    cerr << "Charater testing location x = " << c << " y = " << r << " --no response is denied." << endl;
  
  if(board[r][c]==h)
    return false;
  else if(board[r][c]==v)
    return false;
  else if(r==12 && (c==39 || c==42))
    return false;
  else if((board[r][c]==currentenemycharacter) && (currentenemycharacter == normalenemycharacter))
    {
      if(attempt)
	{
	  dead = true;
	}
      return false;     
    }
  else if((board[r][c]==currentenemycharacter) && (currentenemycharacter == bonusenemycharacter))
    {  
      int enemyid = findenemy(r,c);
      if(enemyid != -1)
	{
	  //Score Bonus Points:
	  score=score+200;
	  resetenemy(enemyid);
	}
      else
	{
	  dead = true;
	  return false;
	}
    }

  if(stats)
    cerr << "Character testing location approved!" << endl;

  scorepoints(r,c);

  return true;
}


void move()
{
  tries++;
  int py = cy;  //Previous y
  int px = cx;    //Previous x
  int test;

  if(stats)
    cerr << "Character Previous x: " << cx << endl << "Character Previous y: " << cy << endl;

  switch(play)
    {
    case 'a':
      {
	test = cx-3;
	if(allowed(cy,test))
	  cx=test;
	else
	  {
	    invalidplay();
	    return;
	  }
	break;
      }
    case 'd':
      {
	test = cx+3;
	if(allowed(cy,test))
	  cx=test;
	else
	  {
	    invalidplay();
	    return;
	  }
	break;
      }
    case 'w':
      {
	test = cy-1;
	if(allowed(test,cx))
	  cy=test;
	else
	  {
	    invalidplay();
	    return;
	  }
	break;
      }
    case 's':
      {
	test = cy+1;
	if(allowed(test,cx))
	  cy=test;
	else
	  {
	    invalidplay();
	    return;
	  }
	break;
      }
    default:
      {
	invalidplay();
	return;
      }
    }
  
  if(stats)
    cerr << "New x: " << cx << endl << "New y: " << cy << endl;

  //Place Character on Board:
  if(stats)
    cerr << "\nPlacing Character; before at previous loation (" << px << ',' << py << "): _" << board[py][px] << "_.\n";
  board[py][px]=s;
  if(stats)
    cerr << "Placed space at previous location: _" << board[py][px] << "_.\n";
  board[cy][cx]=character;
  if(stats)
    cerr << "Placed Character at new loation (" << cx << ',' << cy << "): _" << board[cy][cx] << "_.\n";

  return;
}


void invalidplay()    //Doesn't allow user to forfeit play
{
  attempt = true;  //For not accidently running into an enemy

  if(!dead)
    {
      if(stats)
	cerr << "**Invalid Play: " << play << endl;
      cin.ignore(100,'\n');
      cout << "Enter Play: ";
      cin >> play;
      move();
    }
  
  return;
}
  
