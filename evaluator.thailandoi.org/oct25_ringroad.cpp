#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,k,m;
int s[N],sum,par[N],dis[N];
vector<pair<int,int> > adj[N];

void update(int idx,int val)
{
    while(idx<=k)
    {
        s[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(int idx)
{
    int val = 0;
    while(idx>0)
    {
        val+=s[idx];
        idx-=(idx & -idx);
    }
    return val;
}

int cir(int a,int b)
{
    if(a>b) swap(a,b);
    int tmp = read(b-1)-read(a-1);
    return min(tmp,sum-tmp);
}

int dist(int a,int b)
{
    return abs(dis[a]-dis[b]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> m;

    for(int i = 1;i <= k;i++)
    {
        int x;
        cin >> x;
        sum+=x;
        if(i<k) update(i,x);
        par[i] = i;
    }

    for(int i = k+1;i <= n;i++)
    {
        int a = i,b,d;
        cin >> b >> d;
        par[a] = par[b];
        dis[a] = dis[b]+d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    while(m--)
    {
        int t;
        cin >> t;
        if(t==0)
        {
            int a,b;
            cin >> a >> b;
            if(a==k)
            {
                int prev = sum-read(k);
                sum = sum-prev+b;
            }
            else
            {
                int prev = read(a)-read(a-1);
                sum = sum-prev+b;
                update(a,b-prev);
            }
        }
        else
        {
            int a,b;
            cin >> a >> b;
            if(par[a]==par[b]) cout << dist(a,b) << '\n';
            else cout << dist(a,par[a])+dist(b,par[b])+cir(par[a],par[b]) << '\n';
        }
    }
}
