#include "classes.h"

static struct termios old, owo;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  owo = old; /* make new settings same as old settings */
  owo.c_lflag &= ~ICANON; /* disable buffered i/o */
  owo.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &owo); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

void GenMat(char (&Mat)[MIN_LVL][MAX_LVL])
{
    for(int i=0; i<MIN_LVL; i++){
        for(int j=0; j<MAX_LVL; j++){
            Mat[i][j]=' ';
        }
    }
    for(int i=0; i<MIN_LVL; i++)
    {
        if(i==0 || i==MIN_LVL-1)
        {
            for(int j=0; j<MAX_LVL; j++)
            {
                Mat[i][j]='X';
            }
        }
        else
        {
            Mat[i][0]='X';
            Mat[i][MAX_LVL-1]='X';
        }
    }
}

void PrintMat(char (&Mat)[MIN_LVL][MAX_LVL])
{
    int cont;
    for(int i=0; i<MIN_LVL; i++){
        cont=0;
        for(int j=0; j<MAX_LVL; j++){
            cout<<Mat[i][j];
            cont++;
            if(cont==MAX_LVL)
                cout<<endl;
        }
    }
}

void Gameplay(char (&Mat)[MIN_LVL][MAX_LVL], Player &P)
{
    cout<<"Use W to move up, S to move down, D to move right, A to move left"<<endl;
    P.setP(Mat, P);
    char c;
    char last;
    while(1)
    {
        if((P.getPi()==0 || P.getPi()==MIN_LVL-1)||(P.getPj()==0||P.getPj()==MAX_LVL-1))
        {
            cout<<"Please do not reach the end of the map!"<<endl;
            P.RevertLastMoveP(Mat, P, last);
            PrintMat(Mat);
        }
        else
        {
            c=getch();
            last=c;
            P.MoveP(Mat, P, c);
            if(c=='b')
                break;
            PrintMat(Mat);
        }
    }
}