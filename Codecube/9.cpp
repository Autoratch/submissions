#include <bits/stdc++.h>
using namespace std;

int k,n;
string s;
char a[20][1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> s;
    n = s.length();

    if(k==1){ cout << s; return 0; }

    int x = k-1,y = 0,t = 0,ax = -1,ay = 0,mxy = 0;
    for(int i = 0;i < n;i++)
    {
        a[x][y] = 'X';
        mxy = max(mxy,y);
        if(t<k-1) x+=ax,y+=ay,t++;
        else
        {
            if(ax!=0) ax = 0,ay = 1;
            else if(x==0) ax = 1,ay = 0;
            else ax = -1,ay = 0;
            x+=ax,y+=ay;
            t = 1;
        }
    }

    x = 0,y = 0;
    int id = 0;
    while(id<n)
    {
        if(a[x][y]=='X') 
        {
            a[x][y] = s[id];
            id++;
        }
        y++;
        if(y>mxy) x++,y = 0;
    }

 
    x = k-1,y = 0,t = 0,ax = -1,ay = 0,mxy = 0;
    string ans;
    for(int i = 0;i < n;i++)
    {
        ans+=a[x][y];
        mxy = max(mxy,y);
        if(t<k-1) x+=ax,y+=ay,t++;
        else
        {
            if(ax!=0) ax = 0,ay = 1;
            else if(x==0) ax = 1,ay = 0;
            else ax = -1,ay = 0;
            x+=ax,y+=ay;
            t = 1;
        }
    }

    cout << ans;
}
