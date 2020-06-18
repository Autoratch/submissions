#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int m,n,k;
long long ans;
priority_queue<pair<long long,pair<int,int> > > q;
vector<pair<int,long long> > res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    for(int i = 0;i < n;i++)
    {
        int am;
        cin >> am;
        int amm = am;
        for(int j = 0;j < am;j++)
        {
            int x,y;
            cin >> x >> y;
            if(j==0 and x) res[i].push_back({0,0}),amm++;
            res[i].push_back({x,y});
        }
        res[i].push_back({0,0});
        am = amm;
        for(int j = am-1;j > 0;j--)
        {
            res[i][j].second+=res[i][j+1].second;
        }
        for(int j = am-1;j > 0;j--)
        {
            q.push({res[i][j].second,{-res[i][j].first,res[i][j].first-res[i][j-1].first}});
            res[i][j].first-=res[i][j-1].first;
        }
    }
    while(m>=0 and !q.empty())
    {
        long long a = q.top().first,b = q.top().second.second;
        if(b>=m){ ans+=a*m; break; }
        ans+=a*b;
        m-=b;
        q.pop();
    }
    double a = ans,b = k;
    cout << fixed << setprecision(8) << a/b;
}
