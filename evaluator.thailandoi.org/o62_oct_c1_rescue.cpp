#include "rescuelib.h"
#include "rescuelib.cpp"
#include <bits/stdc++.h>
using namespace std;

int R,C;
int ul,ur,ll,lr,x,y;
int bx,by,cur;

void bsearchr(int a,int b,int c,int d)
{
    // a-->c b-->d
    while(a<c or b<d) 
    {
        int x = (a+c)/2,y = (b+d)/2;
        if(drop_robot(x,y)!=-1) c = x,d = y;
        else if(a==c) b = y+1;
        else a = x+1;
    }
    bx = a,by = b;
}

void bsearchl(int a,int b,int c,int d)
{
    // a-->c b-->d
    while(a<c or b<d)
    {
        int x = (a+c+1)/2,y = (b+d+1)/2;
        if(drop_robot(x,y)!=-1) a = x,b = y;
        else if(a==c) d = y-1;
        else c = x-1;
    }
    bx = a,by = b;
}

int main()
{
    get_size(R,C);
    ul = drop_robot(1,1),ur = drop_robot(1,C),ll = drop_robot(R,1),lr = drop_robot(R,C);
    if(ul>-1 and ur>-1) x = (ul+ur-C+1)/2+1,y = ul+2-x;
    else if(ul>-1 and ll>-1) y = (ul+ll-R+1)/2+1,x = ul+2-y;
    else if(ur>-1 and lr>-1) y = C-((ur+lr-R+1)/2),x = ur-(C-y)+1;
    else if(ll>-1 and lr>-1) x = R-((ll+lr-C+1)/2),y = ll-(R-x)+1;
    if(x or y){ answer(x,y); return 0; }
    if(ul>-1)
    {
        bsearchl(1,1,1,C);
        cur = drop_robot(bx,by);
        x = (ul+cur-by+1)/2+1,y = ul+2-x;
    }
    else if(ur>-1)
    {
        bsearchr(1,1,1,C);
        cur = drop_robot(bx,by);
        x = (ur+cur-(C-by))/2+1,y = C-(ur-(x-1));
    }
    else if(ll>-1)
    {
        bsearchl(R,1,R,C);
        cur = drop_robot(bx,by);
        x = R-(ll+cur-by+1)/2,y = ll-(R-x)+1;
    }
    else
    {
        bsearchr(R,1,R,C);
        cur = drop_robot(bx,by);
        x = R-(lr+cur-(C-by))/2,y = C-(lr-R+x);
    }
    answer(x,y);
}
