void whichexception(int enemyid)
{
        //Enemy Exception Moves:
  cerr << "Remember: 0 is false & 1 is true\n";
  cerr << "Enemy: " << enemyid +1 << endl;
  cerr << "Last Enemy Move: " << enemies[enemyid].lastmovesuccessful << endl;
  cerr << "Execution Moves: " << enemies[enemyid].exceptionmoves << endl;

  if(enemies[enemyid].exceptionmoves == 0)
    cerr << "*First Exception Call.\n\n";
  else
    {
      cerr << "1: " << enemies[enemyid].exception1 << endl;
      cerr << "2: " << enemies[enemyid].exception2 << endl;
      cerr << "3: " << enemies[enemyid].exception3 << endl;
      cerr << "4: " << enemies[enemyid].exception4 << endl;
      cerr << "5: " << enemies[enemyid].exception5 << endl;
      cerr << "6: " << enemies[enemyid].exception6 << endl;
      cerr << "7: " << enemies[enemyid].exception7 << endl;
      cerr << "8: " << enemies[enemyid].exception8 << endl;
      cerr << "9: " << enemies[enemyid].exception9 << endl;
      cerr << "10: " << enemies[enemyid].exception10 << endl;
      cerr << "11: " << enemies[enemyid].exception11 << endl;
      cerr << "12: " << enemies[enemyid].exception12 << endl;
      cerr << "13: " << enemies[enemyid].exception13 << endl;
      cerr << "14: " << enemies[enemyid].exception14 << endl;
      cerr << "15: " << enemies[enemyid].exception15 << endl;
      cerr << "16: " << enemies[enemyid].exception16 << endl;
      cerr << "17: " << enemies[enemyid].exception17 << endl;
      cerr << "18: " << enemies[enemyid].exception18 << endl;
      cerr << "19: " << enemies[enemyid].exception19 << endl;
      cerr << "20: " << enemies[enemyid].exception20 << endl;
      cerr << "21: " << enemies[enemyid].exception21 << endl;
      cerr << "22: " << enemies[enemyid].exception22 << endl;
      cerr << "23: " << enemies[enemyid].exception23 << endl;
      cerr << "24: " << enemies[enemyid].exception24 << endl;
      cerr << "25: " << enemies[enemyid].exception25 << endl;
      cerr << "26: " << enemies[enemyid].exception26 << endl << endl;
    }
  
 return;
}
 
//ENEMY targeting Move Exceptions:
//If add an exception, must declare in enemy class in Constants.h.
//Also default to false in enemy class constructor, resetallenemies(), resetenemy(), and bottom of enemymoveexceptions().
void enemymoveexceptions(int enemyid, int targetx, int targety)
{
  if(stats)
    whichexception(enemyid);  

  //Exception 1:
  if(enemies[enemyid].exception1 || (enemies[enemyid].ey == 1 && enemies[enemyid].ex == 36))
    {
      enemies[enemyid].exception1 = true;
      const char exception[10] = {'s','s','s','s','d','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex))   //Exception still needed.
	{
	  if(presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception1 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 2:
  else if(enemies[enemyid].exception2 || (enemies[enemyid].ey == 1 && enemies[enemyid].ex == 45))
    {
      enemies[enemyid].exception2 = true;
      const char exception[10] = {'s','s','s','s','a','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception2 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 3:
  else if(enemies[enemyid].exception3 || (enemies[enemyid].ey == 8 && enemies[enemyid].ex == 27))
    {
      enemies[enemyid].exception3 = true;
      const char exception[10] = {'d','d','d','s','s','s','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception3 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 4:
  else if(enemies[enemyid].exception4 || (enemies[enemyid].ey == 8 && enemies[enemyid].ex == 54))
    {
      enemies[enemyid].exception4 = true;
      const char exception[10] = {'a','a','a','s','s','s','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception4 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 5:
  else if(enemies[enemyid].exception5 || (enemies[enemyid].ey == 8 && enemies[enemyid].ex == 36))
    {
      enemies[enemyid].exception5 = true;
      const char exception[10] = {'a','a','a','w','w','w','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception5 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 6:
  else if(enemies[enemyid].exception6 || (enemies[enemyid].ey == 8 && enemies[enemyid].ex == 45))
    {
      enemies[enemyid].exception6 = true;
      const char exception[10] = {'d','d','d','w','w','w','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception6 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 7:
  else if(enemies[enemyid].exception7 || (enemies[enemyid].ey == 11 && enemies[enemyid].ex == 27))
    {
      enemies[enemyid].exception7 = true;
      const char exception[10] = {'s','s','a','a','a','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception7 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 8:
  else if(enemies[enemyid].exception8 || (enemies[enemyid].ey == 11 && enemies[enemyid].ex == 54))
    {
      enemies[enemyid].exception8 = true;
      const char exception[10] = {'s','s','d','d','d','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception8 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 7:
  else if(enemies[enemyid].exception7 || (enemies[enemyid].ey == 11 && enemies[enemyid].ex == 27))
    {
      enemies[enemyid].exception7 = true;
      const char exception[10] = {'s','s','a','a','a','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception7 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 8:
  else if(enemies[enemyid].exception8 || (enemies[enemyid].ey == 11 && enemies[enemyid].ex == 54))
    {
      enemies[enemyid].exception8 = true;
      const char exception[10] = {'s','s','d','d','d','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception8 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 9:
  else if(enemies[enemyid].exception9 || (enemies[enemyid].ey == 15 && enemies[enemyid].ex == 27))
    {
      enemies[enemyid].exception9 = true;
      const char exception[10] = {'w','w','a','a','a','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception9 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 10:
  else if(enemies[enemyid].exception10 || (enemies[enemyid].ey == 15 && enemies[enemyid].ex == 54))
    {
      enemies[enemyid].exception10 = true;
      const char exception[10] = {'w','w','d','d','d','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception10 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 11:
  else if(enemies[enemyid].exception11 || (enemies[enemyid].ey == 18 && enemies[enemyid].ex == 36))
    {
      enemies[enemyid].exception11 = true;
      const char exception[10] = {'a','a','a','s','s','s','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception11 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 12:
  else if(enemies[enemyid].exception12 || (enemies[enemyid].ey == 18 && enemies[enemyid].ex == 45))
    {
      enemies[enemyid].exception12 = true;
      const char exception[10] = {'d','d','d','s','s','s','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety >= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception12 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 13:
  else if(enemies[enemyid].exception13 || (enemies[enemyid].ey == 18 && enemies[enemyid].ex == 27))
    {
      enemies[enemyid].exception13 = true;
      const char exception[10] = {'d','d','d','w','w','w','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception13 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 14:
  else if(enemies[enemyid].exception14 || (enemies[enemyid].ey == 18 && enemies[enemyid].ex == 54))
    {
      enemies[enemyid].exception14 = true;
      const char exception[10] = {'a','a','a','w','w','w','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex) && (targety <= enemies[enemyid].ey))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception14 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 15:
  if(enemies[enemyid].exception15 || (enemies[enemyid].ey == 25 && enemies[enemyid].ex == 36))
    {
      enemies[enemyid].exception15 = true;
      const char exception[10] = {'w','w','w','w','d','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx >= enemies[enemyid].ex))   //Exception still needed.
	{
	  if(presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception15 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 16:
  else if(enemies[enemyid].exception16 || (enemies[enemyid].ey == 25 && enemies[enemyid].ex == 45))
    {
      enemies[enemyid].exception16 = true;
      const char exception[10] = {'w','w','w','w','a','N'};
      if((exception[enemies[enemyid].exceptionmoves] != 'N') && (targetx <= enemies[enemyid].ex))   //Exception still needed.
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception16 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 17:
  else if(enemies[enemyid].exception17 || (enemies[enemyid].ey == 8 && enemies[enemyid].ex == 3) || (enemies[enemyid].ey == 13 && enemies[enemyid].ex == 3) || (enemies[enemyid].ey == 18 && enemies[enemyid].ex == 3))
    {
      enemies[enemyid].exception17 = true;
      const char exception[10] = {'d','d','d','d','d','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N')
	{
	  if( presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception17 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 18:
  else if(enemies[enemyid].exception18 || (enemies[enemyid].ey == 8 && enemies[enemyid].ex == 78) || (enemies[enemyid].ey == 13 && enemies[enemyid].ex == 78) || (enemies[enemyid].ey == 18 && enemies[enemyid].ex == 78))
    {
      enemies[enemyid].exception18 = true;
      const char exception[10] = {'a','a','a','a','a','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N')
	{
	  if(presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]))
	    {
	      enemies[enemyid].exceptionmoves++;
	    }
	}
      else
	{
	  enemies[enemyid].exception18 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 19:
  else if(enemies[enemyid].exception19 || (enemies[enemyid].ex == targetx && (targety > enemies[enemyid].ey) && (targetx == 6 || targetx == 9 || targetx == 21 || targetx == 24 || targetx == 27 || targetx == 36 || targetx == 39 || targetx == 48 || targetx == 51 || targetx == 66 || targetx == 69)))    //Target below and on same verticle line, solve by going left.
    {
      enemies[enemyid].exception19 = true;
      int testD = enemies[enemyid].ey + 1;
      const char exception[10] = {'a','a','a','a','a','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(testD, enemies[enemyid].ex))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'s');

	  enemies[enemyid].exception19 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 20:
  else if(enemies[enemyid].exception20 || (enemies[enemyid].ex == targetx && (targety > enemies[enemyid].ey) && (targetx == 12 || targetx == 15 || targetx == 30 || targetx == 33 || targetx == 42 || targetx == 45 || targetx == 54 || targetx == 57 || targetx == 60 || targetx == 72 || targetx == 75)))    //Target below and on same verticle line, solve by going Right.
    {
      enemies[enemyid].exception20 = true;
      int testD = enemies[enemyid].ey + 1;
      const char exception[10] = {'d','d','d','d','d','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(testD, enemies[enemyid].ex))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'s');

	  enemies[enemyid].exception20 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 21:
  else if(enemies[enemyid].exception21 || (enemies[enemyid].ex == targetx && (targety < enemies[enemyid].ey) && (targetx == 6 || targetx == 9 || targetx == 21 || targetx == 24 || targetx == 27 || targetx == 36 || targetx == 39 || targetx == 48 || targetx == 51 || targetx == 66 || targetx == 69)))    //Target above and on same verticle line, solve by going left.
    {
      enemies[enemyid].exception21 = true;
      int testU = enemies[enemyid].ey - 1;
      const char exception[10] = {'a','a','a','a','a','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(testU, enemies[enemyid].ex))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'w');

	  enemies[enemyid].exception21 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 22:
  else if(enemies[enemyid].exception22 || (enemies[enemyid].ex == targetx && (targety < enemies[enemyid].ey) && (targetx == 12 || targetx == 15 || targetx == 30 || targetx == 33 || targetx == 42 || targetx == 45 || targetx == 54 || targetx == 57 || targetx == 60 || targetx == 72 || targetx == 75)))    //Target above and on same verticle line, solve by going Right.
    {
      enemies[enemyid].exception22 = true;
      int testU = enemies[enemyid].ey - 1;
      const char exception[10] = {'d','d','d','d','d','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(testU, enemies[enemyid].ex))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'w');

	  enemies[enemyid].exception22 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 23:
  else if(enemies[enemyid].exception23 || (enemies[enemyid].ey == targety && (targetx > enemies[enemyid].ex) && (targety == 2 || targety == 6 || targety == 7 || targety == 8 || targety == 9 || targety == 14 || targety == 15 || targety == 16 || targety == 22 || targety == 23)))    //Target right and on same horizontal line, solve by going up.
    {
      enemies[enemyid].exception23 = true;
      int testR = enemies[enemyid].ex + 3;
      const char exception[10] = {'w','w','w','w','w','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(enemies[enemyid].ey, testR))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'d');

	  enemies[enemyid].exception23 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 24:
  else if(enemies[enemyid].exception24 || (enemies[enemyid].ey == targety && (targetx > enemies[enemyid].ex) && (targety == 3 || targety == 4 || targety == 10 || targety == 11 || targety == 12 || targety == 13 || targety == 17 || targety == 18 || targety == 19 || targety == 20 || targety == 24)))    //Target right and on same horizontal line, solve by going down.
    {
      enemies[enemyid].exception24 = true;
      int testR = enemies[enemyid].ex + 3;
      const char exception[10] = {'s','s','s','s','s','s'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(enemies[enemyid].ey, testR))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'d');

	  enemies[enemyid].exception24 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 25:
  else if(enemies[enemyid].exception25 || (enemies[enemyid].ey == targety && (targetx < enemies[enemyid].ex) && (targety == 2 || targety == 6 || targety == 7 || targety == 8 || targety == 9 || targety == 14 || targety == 15 || targety == 16 || targety == 22 || targety == 23)))    //Target left and on same horizontal line, solve by going up.
    {
      enemies[enemyid].exception25 = true;
      int testL = enemies[enemyid].ex - 3;
      const char exception[10] = {'w','w','w','w','w','N'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(enemies[enemyid].ey, testL))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'a');

	  enemies[enemyid].exception25 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  //Exception 26:
  else if(enemies[enemyid].exception26 || (enemies[enemyid].ey == targety && (targetx < enemies[enemyid].ex) && (targety == 3 || targety == 4 || targety == 10 || targety == 11 || targety == 12 || targety == 13 || targety == 17 || targety == 18 || targety == 19 || targety == 20 || targety == 24)))    //Target left and on same horizontal line, solve by going down.
    {
      enemies[enemyid].exception26 = true;
      int testL = enemies[enemyid].ex - 3;
      const char exception[10] = {'s','s','s','s','s','s'};
      if(exception[enemies[enemyid].exceptionmoves] != 'N' && !enemyallowed(enemies[enemyid].ey, testL))
	{
	  presetexecute(enemyid, exception[enemies[enemyid].exceptionmoves]);

	  enemies[enemyid].exceptionmoves++;     //Max 5 tries, then cancels exception.

	}
      else
	{
	  presetexecute(enemyid,'a');

	  enemies[enemyid].exception26 = false;
	  enemies[enemyid].exceptionmoves = 0;
	  enemies[enemyid].lastmovesuccessful = true;
	}
      return;
    }
  else
    {
      cerr << endl << "ERROR enemyexceptionmove() called INCORRECTLY.\n";
      cerr << "Enemy " << enemyid +1 << " Failed move for unknown reason.\n";
      cerr << "     Enemy X: " << enemies[enemyid].ex << "   Enemy Y: " << enemies[enemyid].ey << endl;
      cerr << "          Target X: " << targetx << "   Targey Y: " << targety << endl;
      cerr << ".......... Resetting Exceptions for Enemy: " << enemyid +1 << " ..........." << endl << endl;
      
      //Enemy Exception Moves:
      enemies[enemyid].lastmovesuccessful = true;
      enemies[enemyid].exceptionmoves = 0;

      enemies[enemyid].exception1 = false;
      enemies[enemyid].exception2 = false;
      enemies[enemyid].exception3 = false;
      enemies[enemyid].exception4 = false;
      enemies[enemyid].exception5 = false;
      enemies[enemyid].exception6 = false;
      enemies[enemyid].exception7 = false;
      enemies[enemyid].exception8 = false;
      enemies[enemyid].exception9 = false;
      enemies[enemyid].exception10 = false;
      enemies[enemyid].exception11 = false;
      enemies[enemyid].exception12 = false;
      enemies[enemyid].exception13 = false;
      enemies[enemyid].exception14 = false;
      enemies[enemyid].exception15 = false;
      enemies[enemyid].exception16 = false;
      enemies[enemyid].exception17 = false;
      enemies[enemyid].exception18 = false;
      enemies[enemyid].exception19 = false;
      enemies[enemyid].exception20 = false;
      enemies[enemyid].exception21 = false;
      enemies[enemyid].exception22 = false;
      enemies[enemyid].exception23 = false;
      enemies[enemyid].exception24 = false;
      enemies[enemyid].exception25 = false;
      enemies[enemyid].exception26 = false;

    }

  return;
}

