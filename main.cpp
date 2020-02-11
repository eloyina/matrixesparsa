#include <iostream>
#include "MatrizEsp.h"
using namespace std;

int main()
{
    MatrizEsp<int,30,40> M;

    for(int i=0;i<30;i++)
       M.Add(1,i,i);
    M.print();

    return 0;
}
