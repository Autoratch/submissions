#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int a,b,c,d;
int res[N],re[N];
vector<bool> pr(N,true);
int mx = -1,x,y;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> c >> d;

    pr[0] = pr[1] = false;

    for(int i = 2;i < N;i++)
    {
        if(!pr[i]) continue;
        for(int j = 2;j*i < N;j++) pr[i*j] = false,re[i*j] = i;
    }

    for(int i = 2;i < N;i++)
    {
        if(pr[i]) res[i] = 1;
        else res[i] = res[i/re[i]]+1;
    }

    for(int i = 1;i < N;i++) if(b/i>(a-1)/i and d/i>(c-1)/i)
    {
        int hx = (b/i)*i,hy = (d/i)*i;
        if(res[i]>mx) mx = res[i],x = hx,y = hy;
        else if(res[i]==mx and hx+hy>x+y) x = hx,y = hy;
        else if(res[i]==mx and hx+hy==x+y and hx>x) x = hx,y = hy;
    }

    cout << x << ' ' << y;
}
