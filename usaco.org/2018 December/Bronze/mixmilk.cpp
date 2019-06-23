#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);

    int f[4],a[4];

    for(int i = 1;i <= 3;i++) cin >> f[i] >> a[i];

    for(int i = 0;i < 100;i++)
    {
        int x = i%3+1,y = x+1;
        if(y==4) y = 1;
        int ax = a[x];
        a[x]-=min(a[x],f[y]-a[y]);
        a[y]+=min(ax,f[y]-a[y]);
    }

    for(int i = 1;i <= 3;i++) cout << a[i] << '\n';
}
