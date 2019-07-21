#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int n;
vector<bool> pr(N,true);
vector<pair<int,int> > ans;
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    pr[0] = pr[1] = false;
    for(int i = 2;i < N;i++) 
    {
        if(!pr[i]) continue;
        for(int j = 2;j*i < N;j++) pr[i*j] = false;
    }

    for(int i = 1;i < n;i++) ans.push_back({i,i+1});
    ans.push_back({n,1});

    int now = 1;
    while(!pr[ans.size()])
    {
        if(visited[now]){ now++;  continue; }
        ans.push_back({now,now+2});
        visited[now+2] = true;
        now++;
    }

    cout << ans.size() << '\n';
    for(pair<int,int> x : ans) cout << x.first << ' ' << x.second << '\n';
}
