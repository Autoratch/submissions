#include <bits/stdc++.h>
using namespace std;

int n,m,n6;
bool adj[1001][1001];
vector<pair<int,int> > edj;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++) 
    {
        int a,b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
        edj.push_back({a,b});
    }   

    for(int i = 0;i < m;i++)
    {
        int a = edj[i].first,b = edj[i].second;
        long long cnt = 0;
        for(int c = 1;c <= n;c++)
        {
            if(adj[a][c] and adj[b][c]) cnt++;
        }
        ans+=(cnt*(cnt-1))/2;
    }

    for(int i = 0;i < m;i++) for(int j = i+1;j < m;j++)
    {
        int a = edj[i].first,b = edj[i].second;
        int c = edj[j].first,d = edj[j].second;
        if(adj[a][d] and adj[b][d] and adj[a][c] and adj[b][c]) n6++;
    }

    cout << ans-(n6*5/3);
}
