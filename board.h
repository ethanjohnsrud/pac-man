//[y][x]  [row][column]
//char board[27][28];

int y(1); //row
int x(1); //column


void printcoin(int r, int c)
{
  board[r][c]=d;
  board[r][c+1]=s;
  board[r][c+2]=s;
  return;
}

void setnewboard()
{
  //Clear Board with Spaces:
  for(y=0; y<27; y++)
    {
      for(x=0;x<84;x++)
	{
	  board[y][x]=s;
	}
    }
  
  //Boarder
  for(x=0;x<82;x++)
    {
      board[0][x]=h;
      board[26][x]=h;
    }
  for(y=1;y<26;y++)
    {
      board[y][0]=v;
      board[y][1]=s;
      board[y][2]=s;
     }

//First Row
  y=1;
  x=3;
  while(x<37)
    {
      printcoin(y,x);
      x = x + 3;
    }
  board[y][39]=v;
  board[y][40]=s;
  board[y][41]=s;

//Second row
  y=2;
  x=6;
  while(x<16)
    {
      board[y][x]=h;
      x=x+1;
    }
  x=21;
  while(x<34)
    {
      board[y][x]=h;
      x=x+1;
    }
  printcoin(y,3);
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  printcoin(y,36);
  board[y][39]=v;
  board[y][40]=s;
  board[y][41]=s;

//Third row
  y=3;
  x=7;
  while(x<15)
    {
      board[y][x]=s;
      x=x+1;
    }
  x=22;
  while(x<33)
    {
      board[y][x]=s;
      x=x+1;
    }
  board[y][6]=v;
  board[y][15]=v;
  board[y][21]=v;
  board[y][33]=v;
  board[y][34]=s;
  board[y][35]=s;
  printcoin(y,3);
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  printcoin(y,36);
  board[y][39]=v;
  board[y][40]=s;
  board[y][41]=s;

//Fourth row
  y=4;
  x=6;
  while(x<16)
    {
      board[y][x]=h;
      x=x+1;
    }
  x=21;
  while(x<34)
    {
      board[y][x]=h;
      x=x+1;
    }
  printcoin(y,3);
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  printcoin(y,36);
  board[y][39]=h;
  board[y][40]=h;
  board[y][41]=h;

  //Fifth Row
  y=5;
  x=3;
  while(x<40)
    {
      printcoin(y,x);
      x = x + 3;
    }

  //Sixth row
  y=6;
  x=6;
  while(x<16)
    {
      board[y][x]=h;
      x=x+1;
    }
  x=21;
  while(x<25)
    {
      board[y][x]=h;
      x=x+1;
    }
    x=30;
  while(x<42)
    {
      board[y][x]=h;
      x=x+1;
    }
  printcoin(y,3);
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  printcoin(y,27);

  //Seventh row
  y=7;
  x=6;
  while(x<16)
    {
      board[y][x]=h;
      x=x+1;
    }
  x=31;
  while(x<42)
    {
      board[y][x]=h;
      x=x+1;
    }
  printcoin(y,3);
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  printcoin(y,27);
  board[y][6]=v;
  board[y][15]=v;
  board[y][21]=v;
  board[y][22]=s;
  board[y][23]=s;
  board[y][24]=v;
  board[y][30]=v;
  board[y][39]=s;
  board[y][40]=s;
  board[y][41]=s;

  //Eighth row
  y=8;
  x=3;
  while(x<40)
    {
      printcoin(y,x);
      x=x+3;
    }
  board[y][21]=v;
  board[y][22]=s;
  board[y][23]=s;
  board[y][24]=v;
  board[y][39]=v;
  board[y][40]=s;
  board[y][41]=s;

//Nineth row
  y=9;
  x=1;
  while(x<34)
    {
      board[y][x]=h;
      x++;
    }
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  board[y][21]=v;
  board[y][22]=s;
  board[y][23]=s;
  board[y][24]=s;
  board[y][34]=s;
  board[y][35]=s;
  printcoin(y,36);
  board[y][39]=v;
  board[y][40]=s;
  board[y][41]=s;

  //Tenth row
  y=10;
  x=1;
  while(x<15)
    {
      board[y][x]=s;
      x++;
    }
x=25;
  while(x<33)
    {
      board[y][x]=h;
      x++;
    }
  board[y][15]=v;
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  board[y][21]=v;
  board[y][22]=s;
  board[y][23]=s;
  board[y][33]=v;
  board[y][34]=s;
  board[y][35]=s;
  printcoin(y,36);
  board[y][39]=h;
  board[y][40]=h;
  board[y][41]=h;

//Eleventh row
  y=11;
  x=1;
  while(x<15)
    {
      board[y][x]=s;
      x++;
    }
x=27;
  while(x<40)
    {
      printcoin(y,x);;
      x=x+3;
    }
  board[y][15]=v;
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  board[y][21]=v;
  board[y][22]=s;
  board[y][23]=s;
  board[y][24]=v;
  board[y][25]=s;
  board[y][26]=s;

  //Tweleth row
  y=12;
  x=1;
  while(x<38)
    {
      board[y][x]=h;
      x++;
    }
  board[y][16]=s;
  board[y][17]=s;
  printcoin(y,18);
  board[y][25]=s;
  board[y][26]=s;
  printcoin(y,27);
  board[y][38]=s;
  board[y][39]=s;
  board[y][40]=s;
  board[y][41]=s;

//Thirteenth row - Middle Row
  y=13;
  x=3;
  while(x<28)
    {
      printcoin(y,x);
      x=x+3;
    }
x=31;
  while(x<42)
    {
      board[y][x]=s;
      x++;
    }
  board[y][30]=v;

  
  //Reflect Horizontal:
  int r=42;
 for(y=0;y<14;y++)
   {
     r=42;
     for(x=39;x>-1;x--)
       {
	 board[y][r]=board[y][x];
	 r++;
       }
   }

//Reflect Verticle:
 r=14;
 for(y=12;y>-1;y--)
  {
    for(x=0;x<82;x++)
      {
	board[r][x]=board[y][x];
      }
    r++;
  }

 //Special Sets:
 y=14;
 for(x=36;x<46;x++)
   {
     board[y][x]=h;
   }
 board[13][0]='<';
 board[13][81]='>';
 board[2][3]='O';
 board[2][78]='O';
 board[24][3]='O';
 board[24][78]='O';

 //Place Character:
 board[cy][cx] = character;
 
 //Reset Enemies:
 resetallenemies();
 
 return;
}

