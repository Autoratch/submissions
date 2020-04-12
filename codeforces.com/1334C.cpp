#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int t,n;
pair<long long,long long> a[N];
long long x[N],y[N],o[N];
bool dead[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> x[i] >> y[i],dead[i] = 0,o[i] = x[i];
        for(int i = 1;i <= n;i++)
        {
            long long z;
            if(i<n) z = x[i+1];
            else z = x[1];
            a[i] = {x[i]-min(y[i],z),i};
        }
        long long ans = 0,mn = LLONG_MAX;
        x[1]-=y[n];
        for(int i = 1;i <= n;i++)
        {
            int id = i;
            if(x[id]>0) ans+=x[id];
            else x[id] = 0;
            int ne = id+1; if(ne>n) ne = 1;
            if(i<n) x[ne]-=y[id];
            id = ne;
        }
        for(int i = 1;i <= n;i++)
        {
            mn = min(mn,o[i]-x[i]);
        }
        cout << ans+mn << '\n';
        /*
        for(int i = 1;i <= n;i++)
        {
            int id = a[i].second;
            if(dead[id]) continue;
            ans+=x[id],x[id] = 0;
            while(!dead[id])
            {
                if(x[id]>0) break;
                die++,dead[id] = true;
                int ne = id+1;
                if(ne>n) ne = 1;
                x[ne]-=y[id]; 
                id = ne;
            }
            if(die==n) break;
        }*/
    }
}
