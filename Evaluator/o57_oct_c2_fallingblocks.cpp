#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
int s[4][N];

void update(int t,int idx,int val)
{
    while(idx<=n)
    {
        s[t][idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(int t,int idx)
{
    if(idx<0) return 0;
    int val = 0;
    while(idx>0)
    {
        val+=s[t][idx];
        idx-=(idx & -idx);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    while(m--)
    {
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1)
        {
            if(read(1,x)==read(1,x-1)) update(2,x,1);
            if(read(1,y)==read(1,y+1)) update(3,y+1,1);
            update(1,x,1);
            update(1,y+1,-1);
            if(read(1,x)==read(1,x-1)) update(3,x,-1);
            if(read(1,y)==read(1,y+1)) update(2,y+1,-1);
        }
        else if(t==2) cout << read(1,x) << ' ' << read(1,y) << '\n';
        else cout << read(1,x) << ' ' << read(1,y) << ' ' << read(2,y)-read(2,x) << ' ' << read(3,y)-read(3,x) << '\n'; 
    }
}
