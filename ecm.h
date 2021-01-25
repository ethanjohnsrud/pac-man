
//Enemy Control Manager

void ecm()
{
//Reevaluate maxenemies
      if(mode=="easy")
	maxenemies = level;
      else if(mode=="hard")
	maxenemies = level * 5;
      else    //normal
	maxenemies = level + level + 1;

        if(maxenemies>=25)
	  maxenemies = 25;
	  

	//Generate new enemies
	bool oneenemycreated = true;
	if(tries%5==0 && !bonustime)
	  oneenemycreated = false;


	for(int i = 0; i< maxenemies; i++)
	  {
	    if((enemies[i].active == false) && (!oneenemycreated) && (board[12][39]==s) && ((i%5==1) || (i%5==3) || (i%5==0)))
	      {
		if(stats)
		  cerr << "Creating Enemy: " << i + 1 << endl;
		resetenemy(i);
		enemies[i].previous = s;
		enemies[i].ey=12;
		enemies[i].ex=39;
		enemies[i].active = true;
		oneenemycreated = true;
	      }
  
	    if((enemies[i].active == false) && (!oneenemycreated) && (board[12][42]==s) && ((i%5==2) || (i%5==4) || (i%5==0)))
	      {
		if(stats)
		  cerr << "Creating Enemy: " << i + 1 << endl;
		resetenemy(i);
		enemies[i].previous = s;
		enemies[i].ey=12;
		enemies[i].ex=42;
		enemies[i].plays=0;
		enemies[i].active = true;
		oneenemycreated = true;
	      }
	  }

	//Scatter mode vs chase mode adjustments:
	scatterset();

	//Move Current Enemies:
	for(int i(0);i<maxenemies; i++)
	  {
	    if(enemies[i].active) 
	      {
		if(stats)
		  cerr << endl << "Enemy " << i+1 << " is active." << endl;

		//Replace Enemy location
		board[enemies[i].ey][enemies[i].ex] = enemies[i].previous;

	  
		//Calculate Enemy Move
		//  enemymove(enemies[i].ey,enemies[i].ex);  //Random Movement

		presetmove(i);    //Five Type Direct Chasing Movement
		    
		if(enemies[i].active)
		  {
		    //Copy Enemy location
		    enemies[i].previous = board[enemies[i].ey][enemies[i].ex];
		    //Placing Enemy
		    board[enemies[i].ey][enemies[i].ex] = currentenemycharacter;
		  }
		else if(stats)
		  cerr << "Enemy " << i+1 << " is not active for movement execution." << endl;
	      }
	    else if(stats)
	      cerr << endl << "Enemy " << i+1 << " is not active for movement calculation nor movement execution." << endl;

	  }
  
	return;
}


//Calculate Enemy Type:
//Move Current Enemies:
//Enemies %5 == 0 == always chase charater
//Enemies %5 == 1 == goes to upper left and then chases one space left of charater
//Enemies %5 == 2 == goes to lower right and then chases one space right of charater
//Enemies %5 == 3 == goes to lower left and then chases one space below charater
//Enemies %5 == 4 == goes to upper right and then chases one space above charater
void presetmove(int enemyid)
{
  if(stats)
    cerr << "Before Enemy move calculation enemy " << enemyid +1 << " has plays: " << enemies[enemyid].plays << endl;
  
  int type = enemyid % 5;

  if(enemies[enemyid].active)
    enemies[enemyid].tries++;      //Enemy turns since being created

  if(bonustime && enemies[enemyid].tries <= 50)  //Cancels Preddetermined moves if bonus mode is activated.
    enemies[enemyid].tries = 50;

  if(bonustime && (enemies[enemyid].tries%2==0))     //Enemies go slower(skip every other turn) in bonus mode.
    return;
  
  switch(type)
    {
    case 0:
      if(enemies[enemyid].plays < mod0scatterplays)
	{
	  if(presetexecute(enemyid, (mod0[enemies[enemyid].plays])))
	    enemies[enemyid].plays++;
	}
      else
	{
	  directchase(enemyid, cx, cy);
	  enemies[enemyid].plays++;
	}
      break;
    case 1:
      if(enemies[enemyid].plays < mod1scatterplays && enemies[enemyid].tries < 50)
	{
	  if(presetexecute(enemyid, (mod1[enemies[enemyid].plays])))
	    enemies[enemyid].plays++;
	}
      else
	{
	  int test = cx - horizontaloffset;
	  directchase(enemyid, test, cy);
	  enemies[enemyid].plays++;
	}
      break;
    case 2:
      if(enemies[enemyid].plays < mod2scatterplays && enemies[enemyid].tries < 50)
	{
	  if(presetexecute(enemyid, (mod2[enemies[enemyid].plays])))
	    enemies[enemyid].plays++;
	}
      else
	{
	  int test = cx + horizontaloffset;
	  directchase(enemyid, cx, test);
	  enemies[enemyid].plays++;
	}
      break;
    case 3:
      if(enemies[enemyid].plays < mod3scatterplays && enemies[enemyid].tries < 50)
	{
	  if(presetexecute(enemyid, (mod3[enemies[enemyid].plays])))
	    enemies[enemyid].plays++;
	}
      else
	{
	  int test = cy + verticleoffset;
	  directchase(enemyid, cx, test);
	  enemies[enemyid].plays++;
	}
      break;
    case 4:
      if(enemies[enemyid].plays < mod4scatterplays && enemies[enemyid].tries < 50)
	{
	  if(presetexecute(enemyid, (mod4[enemies[enemyid].plays])))
	    enemies[enemyid].plays++;
	}
      else
	{
	  int test = cy - verticleoffset; 
	  directchase(enemyid, test, cy);
	  enemies[enemyid].plays++;
	}
      break;
    default:
      cerr << "ERROR IN CALCULATING PRESET ENEMY TYPE.\n\n";
      break;
    }

  return;
}




//Calculate Pre-set Plays:
bool presetexecute(int enemyid, char move)
{
  if(stats)
    cerr << "Enemy: " << enemyid + 1 << " is attempting to execute preset move: " << move << endl;

  int  test;
  switch(move)
    {
    case 'w':
      test = enemies[enemyid].ey-1;
      if(enemyallowed(test, enemies[enemyid].ex))
	{
	  enemies[enemyid].ey = test;
	  return true;
	}
      break;
    case 's':
      test = enemies[enemyid].ey+1;
      if(enemyallowed(test, enemies[enemyid].ex))
	{
	  enemies[enemyid].ey = test;
	  return true;
	}
      break;
    case 'a':
      test = enemies[enemyid].ex-3;
      if(enemyallowed(enemies[enemyid].ey, test))
	{
	  enemies[enemyid].ex = test;
	  return true;
	}
      break;
    case 'd':
      test = enemies[enemyid].ex+3;
      if(enemyallowed(enemies[enemyid].ey, test))
	{
	  enemies[enemyid].ex = test;
	  return true;
	}
      break;
    default:
      cerr << "ERROR IN CALCULATING PRESET ENEMY MOVE.\n\n";
      break;
    }

  return false; 
}	


void scatterset()
{
  if(stats && scattermode)
    cerr << "Enemy Scatter Mode: " << scattercount << endl;
  else if(stats)
    cerr << "Enemy Chase Mode: " << scattercount << endl;
  
  //Scatter mode vs chase mode adjustments:
  if(scattercount == 0)
    {
      if(mode=="easy")
	{
	  if(scattermode)
	    {
	      scattercount = easychase;
	      scattermode = false;
	    }
	  else
	    {
	      scattercount = easyscatter;
	      scattermode = true;
	    }
	}
      else if(mode=="hard")
	{
	  if(scattermode)
	    {
	      scattercount = hardchase;
	      scattermode = false;
	    }
	  else
	    {
	      scattercount = hardscatter;
	      scattermode = true;
	    }
	}
      else    //normal
	{
	  if(scattermode)
	    {
	      scattercount = normalchase;
	      scattermode = false;
	    }
	  else
	    {
	      scattercount = normalscatter;
	      scattermode = true;
	    }
	}
    }        

  if(!bonustime)
    scattercount--;


  return;
}
