#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,q;
vector<int> adj[N][2];
bool gone[N];
pair<int,int> qe[N << 1];
vector<int> ans;
bool res[N][2];
queue<pair<int,int> > que;
vector<int> tmp;

void upd()
{
    for(int i : tmp) if(!gone[i])
    {
        if(res[i][0]) que.push({i,0});
        if(res[i][1]) que.push({i,1});
    }
    while(!que.empty())
    {
        int x = que.front().first,l = que.front().second;
        que.pop();
        for(int y : adj[x][l]) if(!gone[y] and !res[y][l]) res[y][l] = true,que.push({y,l});
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 0;i < m;i++) 
    {
        int a,b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    for(int i = 0;i < q;i++)
    {
        int a,b;
        cin >> a >> b;
        qe[i] = {a,b};
        if(a==1) gone[b] = true; 
    }
    res[1][0] = 1,res[n][1] = 1;
    tmp.push_back(1),tmp.push_back(n);
    upd();
    for(int i = q-1;i >= 0;i--)
    {
        int a = qe[i].first,b = qe[i].second;
        if(a==1)
        {
            gone[b] = false;
            tmp.clear();
            for(int x : adj[b][0]) tmp.push_back(x);
            for(int x : adj[b][1]) tmp.push_back(x);
            upd();
        }
        else ans.push_back(res[b][0] and res[b][1]);
    }
    reverse(ans.begin(),ans.end());
    for(int x : ans) cout << x << '\n';
}
