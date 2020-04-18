#include "grader.h"
#include "cluedo.h"
#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    int x = 1,y = 1,z = 1;
    while(true)
    {
        int r = Theory(x,y,z);
        if(r==0) return;
        if(r==1) x++;
        else if(r==2) y++;
        else z++;
    }
}
