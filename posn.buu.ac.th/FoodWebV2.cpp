#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n,q;
vector<int> adj[N];
set<int> st;
vector<int> s;
int root,sz;
int f[N],hsh[N << 1];

struct node
{
    int val;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.val = min(a.val,b.val);
        return ret;
    }
};

node tree[N << 1];

void dfs(int u,int p)
{
    s.push_back(u);
    for(int v : adj[u]) if(v!=p) dfs(v,u),s.push_back(u);
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
/*
void print(int l,int r,int idx)
{
    cout << l << ' ' << hsh[l] << endl;
    cout << r << ' ' << hsh[r] << endl;
    cout << idx << ' ' << tree[idx].val << ' ' << hsh[tree[idx].val] << endl;
    cout << endl;
    if(l==r) return;
    int m = (l+r)/2;
    print(l,m,idx*2);
    print(m+1,r,idx*2+1);
}
*/
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) st.insert(i),f[i] = -1;

    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        st.erase(b);
    }

    root = *st.begin();

    dfs(root,0);

    for(int i = 0;i < s.size();i++){ if(f[s[i]]==-1) f[s[i]] = i; hsh[i] = s[i]; }
    sz = s.size();

  //  cout << endl;
   // for(int i : s) cout << i << ' ';
    //cout << endl;

    build(0,sz-1,1);

 //   print(0,sz-1,1);

    cin >> q;

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(f[b]<f[a]) swap(a,b);
//        cout << read(0,sz-1,1,f[a],f[b]).val-1 << endl;
        cout << hsh[read(0,sz-1,1,f[a],f[b]).val] << '\n';
    }
}
