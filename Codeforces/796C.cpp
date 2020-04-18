#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n,s[N];
vector<int> adj[N];
int d[3],mx = INT_MIN,ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> s[i],mx = max(mx,s[i]);
    for(int i = 1;i <= n;i++) if(s[i]==mx) d[0]++; else if(s[i]==mx-1) d[1]++; else if(s[i]==mx-2) d[2]++;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++)
    {
        int e[3] = {0,0,0};
        int each = s[i];    
        if(s[i]==mx) e[0]++; else if(s[i]==mx-1) e[1]++; else if(s[i]==mx-2) e[2]++;
        for(int j : adj[i]){ each = max(each,s[j]+1); if(s[j]==mx) e[0]++; else if(s[j]==mx-1) e[1]++; else if(s[j]==mx-2) e[2]++; }
        if(d[0]>e[0]) each = max(each,mx+2);
        else if(d[1]>e[1]) each = max(each,mx+1);
        else if(d[2]>e[2]) each = max(each,mx);
        ans = min(ans,each);
    }
    cout << ans;
}
