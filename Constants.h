//Gameplay Conditions:
bool stats = false;
string mode = "normal";
bool dead = false;
bool bonustime = false;
bool clearscreen = true;


//Game Stats:
int lives = 3;
int level = 1;
int score = 0;
int startcoins = 265; //Set to 265
int coinsremaining = startcoins;    
int playcount = 1;  //Plays
int tries = 0; //Like plays, but resets when die or level up.


//board.h:
     //[y][x]
     //[row][column]
char board[27][82];
const char v('|');
const char h('-');
const char d('.');
const char s(' ');

void printcoin(int r, int c);
void setnewboard();


//printboard.h:
void print();


//controls.h:
bool attempt = false;   //Prevents user from accidently colliding with an enemy from multiple queue entries.
    //Character:
     const char character = 'C';
     char play; //input
     int cy = 15;   //Current y (row) position.
     int cx = 39;   //Current x (column) position.

void levelup();
void died();
void bonus();
void scorepoints();
bool flipsides(int& r, int& c);
bool allowed(int& r, int& c);
void move();
void invalidplay();    //Doesn't allow user to forfeit play.

//enemy.h:
     //Enemy Character:
     const char normalenemycharacter = 'M';
     const char bonusenemycharacter = 'B';
     char currentenemycharacter = normalenemycharacter;

int maxenemies;
int enemyid;

     //Bonus Plays:
     int bonusplays = -1;
     const int easybonusplays = 30;
     const int normalbonusplays = 15;
     const int hardbonusplays = 10;

bool enemyallowed(int& r, int& c);

int findenemy(int& ty, int& tx);

      //Delete or Reset Enemies:
      void resetallenemies();
      void resetenemy(int i);

      //Random Enemy Movement
      void enemymove(int& ey, int& ex);

     //Intentional Direct Enemy Chasing:
             //Offset Chase:
              const int horizontaloffset = 12;  //Must be divisable by three
              const int verticleoffset = 4;

      void directchase(int enemyid, int targetx, int targety);

class enemy
{
 public:
  bool active;
  int ey;
  int ex;
  char previous;
  int plays;
  int tries;
  
  //Enemyexceptionmoves:
  bool lastmovesuccessful;
  int exceptionmoves;
  bool exception1;
  bool exception2;
  bool exception3;
  bool exception4;
  bool exception5;
  bool exception6;
  bool exception7;
  bool exception8;
  bool exception9;
  bool exception10;
  bool exception11;
  bool exception12;
  bool exception13;
  bool exception14;
  bool exception15;
  bool exception16;
  bool exception17;
  bool exception18;
  bool exception19;
  bool exception20;
  bool exception21;
  bool exception22;
  bool exception23;
  bool exception24;
  bool exception25;
  bool exception26;
   
  enemy()
    {
      active = false;
      ey=12;
      ex=39;
      previous = s;
      plays = 0;
      tries = 0;

      //Enemyexceptionmoves:
      lastmovesuccessful = true;
      exceptionmoves = 0;
      exception1 = false;
      exception2 = false;
      exception3 = false;
      exception4 = false;
      exception5 = false;
      exception6 = false;
      exception7 = false;
      exception8 = false;
      exception9 = false;
      exception10 = false;
      exception11 = false;
      exception12 = false;
      exception13 = false;
      exception14 = false;
      exception15 = false;
      exception16 = false;
      exception17 = false;
      exception18 = false;
      exception19 = false;
      exception20 = false;
      exception21 = false;
      exception22 = false;
      exception23 = false;
      exception24 = false;
      exception25 = false;
      exception26 = false;

    }

  ~enemy() = default;

};


//Enemies:
enemy enemies[25];


//Enemy Control Manager: ecm.h:
void ecm();
void presetmove(int enemyid);

     //Enemy Preset Scatter Plays:  of %5
     //Enemies %5 == 0 == always chase charater
     const int mod0scatterplays = 1;
     char mod0[mod0scatterplays] = {'w'};

     //Enemies %5 == 1 == goes to upper left and then chases one space left of character
     const int mod1scatterplays = 22;
     char mod1[mod1scatterplays] = {'w','a','w','w','w','a','a','a','w','w','w','a','a','a','a','a','a','a','a','w','w','w'};

     //Enemies %5 == 2 == goes to lower right and then chases one space right of character
     const int mod2scatterplays = 32;
     char mod2[mod2scatterplays] = {'w','d','d','d','d','s','s','s','s','a','a','a','s','s','s','d','d','d','s','s','s','d','d','d','d','d','d','d','d','s','s','s'};

     //Enemies %5 == 3 == goes to lower left and then chases one space below character
     const int mod3scatterplays = 32;
     char mod3[mod3scatterplays] = {'w','a','a','a','a','s','s','s','s','d','d','d','s','s','s','a','a','a','s','s','s','a','a','a','a','a','a','a','a','s','s','s'};

     //Enemies %5 == 4 == goes to upper right and then chases one space above character
     const int mod4scatterplays = 22;
     char mod4[mod4scatterplays] = {'w','d','w','w','w','d','d','d','w','w','w','d','d','d','d','d','d','d','d','w','w','w'};


bool presetexecute(int enemyid, char move);

//SCATTER MODES:
bool scattermode = false; //Enemies behave like bonus enemies, default when false is chase mode.

void scatterset();

int scattercount = 0;
const int easychase = 20;
const int easyscatter = 7;
const int normalchase = 20;
const int normalscatter = 5;
const int hardchase = 20;
const int hardscatter = 3;


//exceptions.h
     //Enemy Directional Exception Handeling:
     //Refer to PDF map of Moves, and 'N' indicates end of exception.
void whichexception(int enemyid);
void enemymoveexceptions(int enemyid, int targetx, int targety);


//Files:
#include "board.h"
#include "printboard.h"
#include "controls.h"
#include "enemy.h"
#include "exceptions.h"
#include "ecm.h"
