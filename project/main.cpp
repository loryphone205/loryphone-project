/*Lorenzo Vaccaro, matricola 0327000594, progetto PCE */
#include "header.h"

using namespace std;

int main()
{
    char Mat[MIN_LVL][MAX_LVL];
    int P_i, P_j;
    bool cond=true;
    while(cond==true)
    {
        cout<<"Please choose player position: (<19) (<79)"<<endl;
        cin>>P_i;
        cin>>P_j;
        if((P_i>=19 || P_i<=0)||(P_j>=79||P_j<=0))
        {
            cout<<"Please enter a valid number"<<endl;
            cond=true;
        }
        else
        {
            GenMat(Mat);
            Gameplay(Mat, P_i, P_j);
            cond=false;
        }
    }
}