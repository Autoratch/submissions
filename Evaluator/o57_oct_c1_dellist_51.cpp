#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m;
int fw[N],root[N],en[N];
vector<int> a[N];
set<int> exs,del[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) fw[i] = -1,root[i] = i,en[i] = i;

    for(int i = 0;i < n;i++) 
    {
        int y;
        cin >> y;
        a[i].resize(y);
        for(int j = 0;j < y;j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
            del[i].insert(x);
        }
    }

    while(m--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x,y;
            cin >> x >> y;
            x--;
            for(int i = root[x];;i = fw[i]){ del[i].erase(y); if(i==en[x]) break; }
        }
        else
        {
            int x,y;
            cin >> x >> y;
            x--,y--;
            if(root[y]==-1) continue;
            if(root[x]==-1) root[x] = root[y];
            else fw[en[x]] = root[y];
            en[x] = en[root[y]];
            root[y] = -1;
        }
    }

    for(int i = 0;i < n;i++) if(root[i]!=-1)
    {
        for(int j = root[i];;j = fw[j])
        {
            for(int x : a[j]) if(del[j].find(x)!=del[j].end()) cout << x << '\n';
            if(j==en[i]) break;
        }
    }
}
