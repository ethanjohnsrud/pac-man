 bool enemyallowed(int& r, int& c)
 {
   flipsides(r,c);

   if(stats)
     cerr << "Testing location for enemy at x = " << c << " y = " << r << " --no response is denied." << endl;
   
   if(board[r][c]==h)
     return false;
   else if(board[r][c]==v)
     return false;
   else if((r==12 || r==13)  && (c==39 || c==42))
     return false;
   else if(board[r][c]==normalenemycharacter)
     return false;
   else if(board[r][c]==bonusenemycharacter)
     return false;
   else if((board[r][c]==character) && bonustime)
     return false;
   else if(board[r][c]==character)
     {
       dead = true;
       return false;
     }

   if(stats)
     cerr << "Testing location approved!" << endl;
   
   return true;
 }

int findenemy(int& ty, int& tx)
{
  for(int i=0; i<maxenemies; i++)
    {
      if((enemies[i].ey == ty) && (enemies[i].ex == tx))
	return i;
    }

  return -1;
}

void resetallenemies()
{
  for(int i(0); i < 25; i++)
    {
      if(stats)
	cerr << "Deleting Enemy: " << i + 1 << " of " << maxenemies << endl;
      board[enemies[i].ey][enemies[i].ex] = enemies[i].previous;
      enemies[i].plays = 0;
      enemies[i].tries = 0;
      enemies[i].active = false;

      //Enemy Exception Moves:
      enemies[i].lastmovesuccessful = true;
      enemies[i].exceptionmoves = 0;
      enemies[i].exception1 = false;
      enemies[i].exception2 = false;
      enemies[i].exception3 = false;
      enemies[i].exception4 = false;
      enemies[i].exception5 = false;
      enemies[i].exception6 = false;
      enemies[i].exception7 = false;
      enemies[i].exception8 = false;
      enemies[i].exception9 = false;
      enemies[i].exception10 = false;
      enemies[i].exception11 = false;
      enemies[i].exception12 = false;
      enemies[i].exception13 = false;
      enemies[i].exception14 = false;
      enemies[i].exception15 = false;
      enemies[i].exception16 = false;
      enemies[i].exception17 = false;
      enemies[i].exception18 = false;
      enemies[i].exception19 = false;
      enemies[i].exception20 = false;
      enemies[i].exception21 = false;
      enemies[i].exception22 = false;
      enemies[i].exception23 = false;
      enemies[i].exception24 = false;
      enemies[i].exception25 = false;
      enemies[i].exception26 = false;

    }
  return;
}

void resetenemy(int i)
{
  if(stats)
    cerr << "Deleting Enemy: " << i + 1 << " of " << maxenemies << endl;
  if(enemies[i].active)
    board[enemies[i].ey][enemies[i].ex] = enemies[i].previous;
  enemies[i].plays = 0;
  enemies[i].tries = 0;
  enemies[i].active = false;

      //Enemy Exception Moves:
      enemies[i].lastmovesuccessful = true;
      enemies[i].exceptionmoves = 0;
      enemies[i].exception1 = false;
      enemies[i].exception2 = false;
      enemies[i].exception3 = false;
      enemies[i].exception4 = false;
      enemies[i].exception5 = false;
      enemies[i].exception6 = false;
      enemies[i].exception7 = false;
      enemies[i].exception8 = false;
      enemies[i].exception9 = false;
      enemies[i].exception10 = false;
      enemies[i].exception11 = false;
      enemies[i].exception12 = false;
      enemies[i].exception13 = false;
      enemies[i].exception14 = false;
      enemies[i].exception15 = false;
      enemies[i].exception16 = false;
      enemies[i].exception17 = false;
      enemies[i].exception18 = false;
      enemies[i].exception19 = false;
      enemies[i].exception20 = false;
      enemies[i].exception21 = false;
      enemies[i].exception22 = false;
      enemies[i].exception23 = false;
      enemies[i].exception24 = false;
      enemies[i].exception25 = false;
      enemies[i].exception26 = false;

      return;
}


//Random Enemy Movment:
void enemymove(int& ey, int& ex)
 {
   int test;
   int rnum;
   bool up =true;
   bool down =true;
   bool left =true;
   bool right =true;
   srand(time(0));
   
   while(up || down || left || right)
     {
       rnum = rand() % 4;
       if(up && rnum==0)
	 {
	   test = ey-1;
	   if(enemyallowed(test, ex))
	     {
	       ey=test;
	       return;
	     }
	   else
	     up = false; 
	 }
       else if(down && rnum==1)
	 {
  	   test = ey+1;
   	   if(enemyallowed(test, ex))
	     {
	       ey=test;
	       return;
	     }
	   else
	     down = false; 
  	 }
       else if(left && rnum==2)
	 {
	   test = ex-3;
	   if(enemyallowed(ey, test))
	     {
	       ex=test;
	       return;
	     }
	   else
	     left = false; 
	 }
       else if(right && rnum==3)
	 {
	   test = ex+3;
	   if(enemyallowed(ey, test))
	     {
	       ex=test;
	       return;
	     }
	   else
	     right = false; 
	 }
     }
  
   return;
 }


//Intentional Enemy Movment:
void directchase(int enemyid, int targetx, int targety)
{
  int test;
  int rnum;
  bool horizontal = true;
  bool verticle = true;
  srand(time(0));
   
  //Within Offset Spaces, always target Character Directly, and always for scattermode and bonustime:
   if(bonustime || scattermode || ((abs(enemies[enemyid].ex - cx) <= horizontaloffset) || (abs(enemies[enemyid].ey - cy) <= verticleoffset)))
    {
      targetx = cx;
      targety = cy;
    }
  
   if(stats)
     {
       cerr << "Enemy " << enemyid +1 << " location x: " << enemies[enemyid].ex << endl << "Enemy " << enemyid + 1 << "location y: " << enemies[enemyid].ey << endl;
       cerr << "Enemy " << enemyid +1 << " target x: " << targetx << endl << "Enemy " << enemyid + 1 << "target y: " << targety << endl;
     }

   if(!enemies[enemyid].lastmovesuccessful)
     {
      if(stats)
	cerr << endl << "Continuing Executing Exception moves for Enemy: " << enemyid +1 << endl;

      enemymoveexceptions(enemyid, targetx, targety);
       return;
     }
  
   
  while(horizontal || verticle)
    {
      rnum = rand() % 2;
      //Horizontal Test to go right:
      if(horizontal && (rnum==0))
	{
	  if(((enemies[enemyid].ex < targetx) && (!bonustime && !scattermode)) || ((enemies[enemyid].ex > targetx) && (bonustime || scattermode)))
	    {
	      test = enemies[enemyid].ex+3;
	      if(enemyallowed(enemies[enemyid].ey, test))
		{
		  enemies[enemyid].ex=test;
		  return;
		}
	      else
		horizontal = false; 
	    }
	  //Left
	  else if(((enemies[enemyid].ex > targetx) && (!bonustime && !scattermode)) || ((enemies[enemyid].ex < targetx) && (bonustime || scattermode)))
	    {
	      test = enemies[enemyid].ex-3;
	      if(enemyallowed(enemies[enemyid].ey, test))
		{
		  enemies[enemyid].ex=test;
		  return;
		}
	      else
		horizontal = false; 
	    }
	  //None/Same:
	  else
	    {
	      if(bonustime || scattermode)
		{
		  rnum = rand() % 2;
		  if(rnum==0)
		    {
		      test = enemies[enemyid].ex+3;
		      if(enemyallowed(enemies[enemyid].ey, test))
			{
			  enemies[enemyid].ex=test;
			  return;
			}
		    
		      test = enemies[enemyid].ex-3;
		      if(enemyallowed(enemies[enemyid].ey, test))
			{
			  enemies[enemyid].ex=test;
			  return;
			}
		    }
		  else
		    {
		      test = enemies[enemyid].ex-3;
		      if(enemyallowed(enemies[enemyid].ey, test))
			{
			  enemies[enemyid].ex=test;
			  return;
			}
		      test = enemies[enemyid].ex+3;
		      if(enemyallowed(enemies[enemyid].ey, test))
			{
			  enemies[enemyid].ex=test;
			  return;
			}
		    }

		}
	      
	      horizontal = false;
	    }
	}

      //Verticle Test to go up:
      if(verticle && (rnum==1))
	{
	  if(((enemies[enemyid].ey > targety) && (!bonustime && !scattermode)) || ((enemies[enemyid].ey < targety) && (bonustime || scattermode)))
	    {
	      test = enemies[enemyid].ey-1;
	      if(enemyallowed(test, enemies[enemyid].ex))
		{
		  enemies[enemyid].ey=test;
		  return;
		}
	      else
		verticle = false; 
	    }
	  //Down
	  else if(((enemies[enemyid].ey < targety) && (!bonustime && !scattermode)) || ((enemies[enemyid].ey > targety) && (bonustime || scattermode)))
	    {
	      test = enemies[enemyid].ey+1;
	      if(enemyallowed(test, enemies[enemyid].ex))
		{
		  enemies[enemyid].ey=test;
		  return;
		}
	      else
		verticle = false; 
	    }
	  //None/Same:
	  else
	    {
	      if(bonustime || scattermode)
		{
		  rnum = rand() % 2;
		  if(rnum==0)
		    {
		      test = enemies[enemyid].ey-1;
		      if(enemyallowed(test, enemies[enemyid].ex))
			{
			  enemies[enemyid].ey=test;
			  return;
			}
		      test = enemies[enemyid].ey+1;
		      if(enemyallowed(test, enemies[enemyid].ex))
			{
			  enemies[enemyid].ey=test;
			  return;
			}
		    }
		  else
		    {
		      test = enemies[enemyid].ey+1;
		      if(enemyallowed(test, enemies[enemyid].ex))
			{
			  enemies[enemyid].ey=test;
			  return;
			}
		      test = enemies[enemyid].ey-1;
		      if(enemyallowed(test, enemies[enemyid].ex))
			{
			  enemies[enemyid].ey=test;
			  return;
			}
		    }
		}
	      
	      verticle = false;
	    }
	}

    }


  if(!bonustime && !scattermode)     //Allow enemy to get stuck during bonustime and scattermode.
    {
      if(stats)
	cerr << endl << "Executing Exception move for Enemy: " << enemyid +1 << endl;

      enemies[enemyid].lastmovesuccessful = false;

      enemymoveexceptions(enemyid, targetx, targety);
      return;
    }
  
  return;
}

