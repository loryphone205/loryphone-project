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

int Random(int a, int b)
{
    uniform_int_distribution<> distr(a, b);
    return distr(gen);
}

Enemy *Resize(char (&Mat)[MIN_LVL][MAX_LVL], int &n, int &i, Enemy *e)
{
    int j=0;
    int k=0;
    Enemy *p;
    p = new Enemy [n-1];
    do
    {
        if(j==i)
        {
            j++;
        }
        else
        {
            p[k].setEi(e[j].getEi());
            p[k].setEj(e[j].getEj());
            p[k].setE(Mat, e[j]);
            j++;
            k++;
        }
    }
    while(j<n&&k<=j);
    n--;
    delete []e;
    return p;
}

Enemy *Reallocate(char (&Mat)[MIN_LVL][MAX_LVL], int &n, Enemy *e)
{
    int j=0;
    int k=0;
    Enemy *p;
    p = new Enemy [n];
    do
    {
        p[k].setEi(e[j].getEi());
        p[k].setEj(e[j].getEj());
        p[k].setE(Mat, e[j]);
        j++;
        k++;
    }while(j<n);
    delete []e;
    return p;
}

Enemy *CheckKill(char (&Mat)[MIN_LVL][MAX_LVL], Enemy *e, Player &P, int &c, int &n)
{
    for(int i=0; i<n; i++)
    {
        if ((P.getPi()==e[i].getEi())&&(P.getPj()==e[i].getEj()))
        {
            cout<<"You killed an enemy"<<endl;
            e=Resize(Mat, n, i, e);
            c++;
        }
    }
    return e;
}

void Gameplay(char (&Mat)[MIN_LVL][MAX_LVL], Player &P, Enemy *e, int n)
{
    int NKillsToDo=n;
    int cont=0;
    int s_i=Random(1, MIN_LVL-2);
    int s_j=Random(1, MAX_LVL-2);
    Mat[s_i][s_j]='S';
    cout<<"Use W to move up, S to move down, D to move right, A to move left"<<endl;
    cout<<"Press 'b' to stop the game"<<endl;
    cout<<"Reach the Stairs 'S' on the map to end the game"<<endl;
    P.setP(Mat, P);
    for(int i=0; i<n; i++)
    {
        e[i].setE(Mat, e[i]);
    }
    char c;
    while(1)
    {
        c=getch();
        P.MoveP(Mat, P, c);
        if(P.getPi()==s_i && P.getPj()==s_j)
        {
            if(cont==NKillsToDo)
            {
                cout<<"You Win!"<<endl;
                break;
            }
            else
            {
                cout<<"Please kill all the enemies to win!"<<endl;
                P.RevertLastMoveP(Mat, P, c);
                Mat[s_i][s_j]='S';
            }
        }
        e=CheckKill(Mat, e, P, cont, n);
        for(int i=0; i<n; i++)
        {   
            uniform_real_distribution<> distr(1,5);
            int ne=0;
            ne=distr(gen);
            e[i].MoveE(Mat, e[i], ne);
            if(e[i].getEi()==s_i && e[i].getEj()==s_j)
            {
                e[i].RevertLastMoveE(Mat, e[i], ne);
                Mat[s_i][s_j]='S';
            }
            if((P.getPi()==e[i].getEi())&&(P.getPj()==e[i].getEj()))
                Mat[P.getPi()][P.getPj()]='P';
        }
        e=CheckKill(Mat, e, P, cont, n);
        e=Reallocate(Mat, n, e);
        if(c=='b')
        {
            cout<<"You Win!"<<endl;
            break;
        }
        PrintMat(Mat);
    }
}