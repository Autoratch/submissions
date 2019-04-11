#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,ans;
int res[N];
vector<int> adj[N];

vector<int> dfs(int u,int p)
{
    vector<vector<int> > ch;
    for(int v : adj[u])
    {
        if(v==p) continue;
        ch.push_back(dfs(v,u));
    }
    vector<int> ret(5,-1);
    for(int i = 0;i < ch.size();i++) for(int j = 0;j < ch[i].size();j++) ret[j+1] = max(ret[j+1],ch[i][j]);
    ret[0] = res[u];
    if(ret[4]>-1) ans = max(ans,ret[4]+res[u]);
    ret.resize(4);
    int mx21 = INT_MIN+1,mx22 = INT_MIN+1,amt = 0;
    for(int i = 0;i < ch.size();i++) 
    {
        int x = ch[i][1];
        if(x==-1) x = INT_MIN;
        if(x>mx21) mx21 = x,amt = 1;
        else if(x==mx21) amt++;
        else if(x>mx22) mx22 = x;
    }
    if(amt>1 or mx22>-1) 
    {
        if(amt>1) ans = max(ans,mx21*2);
        else ans = max(ans,mx21+mx22);
    }
    int mx11 = INT_MIN+1,mx12 = INT_MIN+1,mx31 = INT_MIN+1,mx32 = INT_MIN+1,am1 = 0,am3 = 0;
    bool same = false;
    for(int i = 0;i < ch.size();i++)
    {
        int x1 = ch[i][0],x3 = ch[i][2];
        if(x1==ret[1] and x3==ret[3]) same = true;
        if(x1==-1) x1 = INT_MIN;
        if(x3==-1) x3 = INT_MIN;
        if(x1>mx11) mx11 = x1,am1 = 1;
        else if(x1==mx11) am1++;
        else if(x1>mx12) mx12 = x1;
        if(x3>mx31) mx31 = x3,am3 = 1;
        else if(x3==mx31) am3++;
        else if(x3>mx32) mx32 = x3;
    }
    if(am1>0 and am3>0)
    {
        if(am1>1 or am3>1) ans = max(ans,mx11+mx31);
        else if(!same) ans = max(ans,mx11+mx31);
        else ans = max(ans,max(mx11+mx32,mx12+mx31));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++){ cin >> res[i]; adj[i].resize(0); }
        for(int i = 0;i < n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans = INT_MIN;
        dfs(1,0);
        if(ans==INT_MIN) ans = -1;
        cout << ans << '\n';
    }
}
