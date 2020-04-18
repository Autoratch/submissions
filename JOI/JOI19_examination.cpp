#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,m;
tuple<int,int,int,int> a[N];
int ans[N],fw[N];
vector<int> tmp;
map<int,int> ma;
stack<int> st;

bool cmp(tuple<int,int,int,int> a,tuple<int,int,int,int> b){ return get<1>(a)<get<1>(b); }

void update(int idx,int val)
{
    if(val==1) st.push(idx);
    idx = ma[idx];
    while(idx<N) fw[idx]+=val,idx+=(idx & -idx);
}

int read(int idx)
{
    if(idx==INT_MAX) idx = N-1;
    else idx = ma[idx];
    int val = 0;
    while(idx>0) val+=fw[idx],idx-=(idx & -idx);
    return val;
}

void clear()
{
    while(!st.empty()) update(st.top(),-1),st.pop();
}

void solve(int l,int r)
{
    if(l==r) return;
    int m = (l+r)/2;
    solve(l,m),solve(m+1,r);
    sort(a+l,a+m+1,cmp),sort(a+m+1,a+r+1,cmp);
    int i = l,j = m+1;
    while(i<=m+1 and j<=r)
    {
        int x = get<1>(a[i]),y = get<1>(a[j]),k = get<2>(a[i]),l = get<2>(a[j]),ix = get<3>(a[i]),iy = get<3>(a[j]);
        if(x<=y){ if(!ix and i<=m) update(k,1); i++; }
        else{ if(iy) ans[iy]+=read(l); j++;  }
    }
    while(j<=r) 
    {
        int l = get<2>(a[j]),iy = get<3>(a[j]);
        ans[iy]+=read(l); j++;
    }
    clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
    {
        int x,y;
        cin >> x >> y;
        x = -x,y = -y;
        a[i] = {x,y,x+y,0};
        tmp.push_back(x+y);
    }
    for(int i = 1;i <= m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x = -x,y = -y,z = -z;
        a[i+n] = {x,y,z,i};
        tmp.push_back(z);
    }
    sort(tmp.begin(),tmp.end());
    for(int i = 1;i <= tmp.size();i++) ma[tmp[i-1]] = i;
    sort(a+1,a+n+m+1);
    solve(1,n+m);
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';
}
