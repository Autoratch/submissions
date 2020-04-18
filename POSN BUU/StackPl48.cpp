#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 1;

int n;
vector<int> adj[N];
int pa[N];
vector<pair<int,int> > q;
vector<int> s;
int sz;
int f[N << 3];
int hsh[N],ori[N];
vector<pair<int,int> > ans;
vector<int> id;
int lv[N];

struct node
{
    int val;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.val = min(a.val,b.val);
        return ret;
    }
}tree[N << 4];

void dfs(int u)
{
    s.push_back(u);
    for(int v : adj[u]) lv[v] = lv[u]+1,dfs(v),s.push_back(u);
}

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].val = f[s[l]]; return; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret; ret.val = INT_MAX; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i <= n;i++) f[i] = -1;

    for(int i = 1;i <= n;i++)
    {
        char c;
        cin >> c;
        if(c=='a') 
        {
            int x;
            cin >> x;
            adj[ori[x]].push_back(i);
            ori[i] = i;
            pa[i] = ori[x];
        }
        else if(c=='b')
        {
            int x;
            cin >> x;
            if(ori[x]==0) ans.push_back({i,-1});
            else ans.push_back({i,ori[x]});
            ori[i] = pa[ori[x]]; 
        }
        else
        {
            int x,y;
            cin >> x >> y;
            q.push_back({ori[x],ori[y]});
            id.push_back(i);
            ori[i] = ori[x];
        }
    }

    dfs(0);
    sz = s.size();

    for(int i = 0;i < sz;i++){ if(f[s[i]]==-1) f[s[i]] = i;  hsh[i] = s[i]; }

    build(0,sz-1,1);

    for(int i = 0;i < q.size();i++)
    {
        int x = q[i].first,y = q[i].second;
        if(f[ori[x]]>f[ori[y]]) swap(x,y);
        ans.push_back({id[i],lv[hsh[read(0,sz-1,1,f[ori[x]],f[ori[y]]).val]]});
    }

    sort(ans.begin(),ans.end());

    for(pair<int,int> x : ans) cout << x.second << '\n';
}
