#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,m;
int adj[N][N];
vector<pair<int,int> > ed;
int ans5,ans6;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        ed.push_back({a,b});
        adj[a][b] = adj[b][a] = 1;
    }

    for(int i = 0;i < m;i++) for(int j = 0;j < m;j++)
    {
        int a = ed[i].first,b = ed[i].second;
        int c = ed[j].first,d = ed[j].second;
        if(a==c or a==d or b==c or b==d) continue;
        if(adj[a][c]+adj[a][d]+adj[b][c]+adj[b][d]==3) ans5++;
        else if(adj[a][c]+adj[a][d]+adj[b][c]+adj[b][d]==4) ans6++;
    }

    cout << ans5/4+ans6/6;
}  