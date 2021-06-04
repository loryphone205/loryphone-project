#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1,78);
    for(int i=0; i<10; i++)
    {
        cout<<" "<<distr(gen);
    }
}