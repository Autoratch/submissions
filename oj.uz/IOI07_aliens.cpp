#include <bits/stdc++.h>
using namespace std;

long long n,x,y,m;

bool examine(long long x,long long y)
{
    if(x>n or x<1 or y>n or y<1) return false;
    cout << "examine " << x << ' ' << y << '\n';
    cout << flush;
    string s;
    cin >> s;
    if(s=="true") return true;
    else return false;
}

long long solve(int ax,int ay)
{
    long long mul = 1;
    while(examine(x+ax*mul,y+ay*mul)) mul*=2;
    long long l = mul/2,r = mul;
    while(l<r)
    {
        long long m = (l+r+1)/2;
        if(examine(x+ax*m,y+ay*m)) l = m;
        else r = m-1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x >> y;

    long long lf = solve(-1,0),rg = solve(1,0),up = solve(0,1),dn = solve(0,-1);
    m = lf+rg+1;
    x-=lf,y-=dn;

    while(examine(x-m,y-m)) x-=m,y-=m;
    while(examine(x-m*2,y)) x-=m*2;
    while(examine(x,y-m*2)) y-=m*2;

    cout << "solution " << x+m*2+m/2 << ' ' << y+m*2+m/2;
    cout << flush;
}
