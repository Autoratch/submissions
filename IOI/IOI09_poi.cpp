#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int n,t,p;
int a[N][N],no[N],sc[N],ta[N];
vector<pair<int,pair<int,int> > > res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t >> p;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= t;j++) cin >> a[i][j];
    for(int i = 1;i <= n;i++) for(int j = 1;j <= t;j++) if(!a[i][j]) no[j]++;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= t;j++) if(a[i][j]) sc[i]+=no[j],ta[i]++;
    for(int i = 1;i <= n;i++) res.push_back({-sc[i],{-ta[i],i}});
    sort(res.begin(),res.end());
    int id = 1;
    for(auto it : res)
    {
        if(it.second.second==p){ cout << -it.first << ' ' << id; return 0; }
        id++;
    }
}
