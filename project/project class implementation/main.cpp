/*Lorenzo Vaccaro, matricola 0327000594, progetto PCE */
#include "fun_in.h"

using namespace std;

int main()
{
    char Mat[MIN_LVL][MAX_LVL];
    int I,J;
    Player P1;
    bool cond=true;
    while(cond==true)
    {
        cout<<"Please choose player position: (<19) (<79)"<<endl;
        cin>>I;
        cin>>J;
        if((I>=19 || I<=0)||(J>=79||J<=0))
        {
            cout<<"Please enter a valid number"<<endl;
            cond=true;
        }
        else
        {
            P1.setPi(I);
            P1.setPj(J);
            GenMat(Mat);
            Gameplay(Mat, P1);
            cond=false;
        }
    }
}