#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

int n,q;
int pa[N];
vector<pair<int,int> > tree[N << 1];
map<pair<int,int>,int> ma;
stack<pair<int,int> > st;

int root(int x){ if(pa[x]<0) return x; return root(pa[x]); }

bool merge(int a,int b)
{
    a = root(a),b = root(b);
    if(a==b) return !(pa[a]%2); 
    if(abs(pa[a])<abs(pa[b])) swap(a,b);
    st.push({a,pa[a]}),st.push({b,pa[b]});
    pa[a]+=pa[b],pa[b] = a;
    return true;
}

void rollback(int ver){ while(st.size()>ver) pa[st.top().first] = st.top().second,st.pop(); }

void update(int l,int r,int idx,int x,int y,pair<int,int> k)
{
    if(x>r or y<l) return;
    if(x<=l and y>=r) return void(tree[idx].push_back(k));
    int m = (l+r)/2;
    update(l,m,idx*2,x,y,k),update(m+1,r,idx*2+1,x,y,k);
}

void solve(int l,int r,int idx,bool ok)
{
    int ver = st.size();
    for(auto x : tree[idx]) ok&=merge(x.first,x.second);
    if(l==r){ if(ok) cout << "yes\n"; else cout << "no\n"; }
    else
    {
        int m = (l+r)/2;
        solve(l,m,idx*2,ok),solve(m+1,r,idx*2+1,ok);
    }
    rollback(ver);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1;i <= n;i++) pa[i] = -1;
    for(int i = 1;i <= q;i++)
    {
        int t,a,b;
        cin >> t >> a >> b;
        if(a>b) swap(a,b);
        if(t) ma[{a,b}] = i;
        else update(1,q,1,ma[{a,b}],i-1,{a,b}),ma[{a,b}] = 0;
    }
    for(auto x : ma) if(x.second) update(1,q,1,x.second,q,x.first);
    solve(1,q,1,true);
}
