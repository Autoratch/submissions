#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int N = 200;

struct node
{
    long long a,b,c,d;
}in[N];

int n,m,q;
set<pair<long long,long long> > s;
map<pair<long long,long long>,int> ma;
long long dist[N][N];
pair<long long,long long> nd[N];

long long dis(pair<long long,long long> a,pair<long long,long long> b)
{
    swap(a.x,a.y),swap(b.x,b.y);
    if(abs(a.x-b.x)<=abs(a.y-b.y)) return abs(a.y-b.y);
    else if(abs(a.x-b.x)%2==abs(a.y-b.y)%2) return abs(a.x-b.x);
    else return abs(a.x-b.x)+1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> q;

    for(int i = 0;i < m;i++)
    {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        s.insert({a,b});
        s.insert({c,d});
        node r;
        r.a = a,r.b = b,r.c = c,r.d = d;
        in[i] = r;
    }

    int cn = 0;
    for(auto it = s.begin();it != s.end();it++)
    {
        int i = cn; cn++;
        ma[*it] = i;
        nd[i] = *it;
    }

    n = s.size();

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(i!=j) dist[i][j] = INT_MAX;

    for(int i = 0;i < m;i++)
    {
        long long a = in[i].a,b = in[i].b,c = in[i].c,d = in[i].d;
        int ia = ma[make_pair(a,b)],ib = ma[make_pair(c,d)];
        dist[ia][ib] = 1;
        dist[ib][ia] = 1;
    }

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) dist[i][j] = min(dist[i][j],dis(nd[i],nd[j]));

    for(int k = 0;k < n;k++) for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    while(q--)
    {
        pair<long long,long long> a,b;
        cin >> a.x >> a.y >> b.x >> b.y;
        long long ans = dis(a,b);
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) ans = min(ans,dis(a,nd[i])+dist[i][j]+dis(nd[j],b));
        cout << ans << '\n';
    }
}
