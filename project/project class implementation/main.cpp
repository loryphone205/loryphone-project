/*Lorenzo Vaccaro, matricola 0327000594, progetto PCE */
#include "fun_in.h"

using namespace std;

int main()
{
    char Mat[MIN_LVL][MAX_LVL];
    int I,J;
    int n;
    int NL;
    int cont=0;
    Player P1;
    Enemy *e;
    cout<<"How many levels do you want to play:";
    cin>>NL;
    cout<<endl;
    cout<<"how many enemies do you want to have: ";
    cin>>n;
    cout<<endl;
    bool cond=true;
    while(cond==true)
    {
        cout<<"Please choose player position (<19) (<79):";
        cin>>I;
        cin>>J;
        cout<<endl;
        if((I>=19 || I<=0)||(J>=79||J<=0))
        {
            cout<<"Please enter a valid number"<<endl;
            cond=true;
        }
        else
        {   
            cout<<"Use W to move up, S to move down, D to move right, A to move left"<<endl;
            cout<<"Press 'b' to stop the game"<<endl;
            cout<<"Reach the Stairs 'S' on the map to end the game"<<endl;
            for(int k=0; k<NL; k++)
            {
                e=new Enemy[n];
                P1.setPi(I);
                P1.setPj(J);
                for(int i=0; i<n; i++)
                {
                    e[i].setEi(Random(1, MIN_LVL-2));
                    e[i].setEj(Random(1, MAX_LVL-2));
                }
                GenMat(Mat);
                Gameplay(Mat, P1, e, n);
                cont++;
                cond=false;
            }
        }
    }
    cout<<" & You won!"<<endl;
}