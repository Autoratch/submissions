#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;

int n,q;
int pa[N];
bool ask[N];
map<pair<int,int>,int> ma;
vector<pair<int,int> > tree[N << 1];
stack<pair<int,int> > st;

int root(int u){ if(pa[u]<0) return u; return root(pa[u]); }

bool merge(int a,int b)
{
    a = root(a),b = root(b);
    if(a==b) return false;
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

void solve(int l,int r,int idx,int com)
{
    int ver = st.size();
    for(auto x : tree[idx]) if(merge(x.first,x.second)) com--;
    if(l!=r)
    {
        int m = (l+r)/2;
        solve(l,m,idx*2,com),solve(m+1,r,idx*2+1,com);
    }
    else if(ask[l]) cout << com << '\n';
    rollback(ver);
}

int main()
{
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
    
    cin >> n >> q;
    for(int i = 1;i <= n;i++) pa[i] = -1;
    for(int i = 1;i <= q;i++)
    {
        char c;
        cin >> c;
        if(c=='?') ask[i] = true;
        else
        {
            int x,y;
            cin >> x >> y;
            if(x>y) swap(x,y);
            if(c=='+') ma[{x,y}] = i;
            else
            {
                update(1,q+1,1,ma[{x,y}],i,{x,y});
                ma[{x,y}] = 0;
            }
        }
    }
    for(auto x : ma) if(x.second) update(1,q+1,1,ma[x.first],q+1,x.first);
    solve(1,q+1,1,n);
}
