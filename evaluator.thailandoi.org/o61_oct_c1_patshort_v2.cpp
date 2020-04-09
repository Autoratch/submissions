#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>

const long long N = 200;

long long n,m,q;
vector<pii> res,ed;
long long dist[N][N];

long long dis(pii x,pii y)
{
    long long a = x.first,b = x.second,c = y.first,d = y.second;
    if(abs(b-d)>=abs(a-c)) return abs(b-d);
    else
    {
        if((abs(a-c)-abs(b-d))%2==0) return abs(a-c);
        else return abs(a-c)+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> q;

    for(long long i = 0;i < m;i++)
    {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        swap(a,b),swap(c,d);
        res.push_back({a,b}),res.push_back({c,d});
        ed.push_back({res.size()-2,res.size()-1});
    }

    n = res.size();

    for(long long i = 0;i < n;i++) for(long long j = i;j < n;j++) dist[i][j] = dist[j][i] = dis(res[i],res[j]);

    for(long long i = 0;i < ed.size();i++) dist[ed[i].first][ed[i].second] = dist[ed[i].second][ed[i].first] = 1;

    for(long long k = 0;k < n;k++) for(long long i = 0;i < n;i++) for(long long j = 0;j < n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    while(q--)
    {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        swap(a,b),swap(c,d);
        long long ans = dis({a,b},{c,d});
        for(long long i = 0;i < n;i++) for(long long j = 0;j < n;j++) ans = min(ans,dis({a,b},res[i])+dis({c,d},res[j])+dist[i][j]);
        cout << ans << '\n';
    }

}
