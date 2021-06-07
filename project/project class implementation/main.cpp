/*Lorenzo Vaccaro, matricola 0327000594, progetto PCE */
#include "fun_in.h"

using namespace std;

int main()
{
    char Mat[MIN_LVL][MAX_LVL];
    int I,J;
    int n;
    Player P1;
    Enemy *e;
    cout<<"how many enemies do you want to have: ";
    cin>>n;
    cout<<endl;
    e=new Enemy[n];
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
            for(int i=0; i<n; i++)
            {
                e[i].setEi(Random(1, MIN_LVL-2));
                e[i].setEj(Random(1, MAX_LVL-2));
            }
            GenMat(Mat);
            Gameplay(Mat, P1, e, n);
            cond=false;
        }
    }
}