#include <bits/stdc++.h>
using namespace std;

int a,b,c,f[] = {0,1,2,0,2,1,0},ma = 3,mb = 2,mc = 2;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> c;

    for(int i = 0;i < 7;i++)
    {
        int w = min({a/ma,b/mb,c/mc});
        int la = a-ma*w,lb = b-mb*w,lc = c-mc*w;
        long long d = w*7;
        for(int j = i;;j = (j+1)%7)
        {
            if(f[j]==0){ if(la==0) break; else la--; }
            else if(f[j]==1){ if(lb==0) break; else lb--; }
            else{ if(lc==0) break; else lc--; }
            d++;
        }
        ans = max(ans,d);
    }

    cout << ans;
}
