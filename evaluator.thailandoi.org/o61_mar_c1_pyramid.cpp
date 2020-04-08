#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
pair<pair<int,int>,int> a[N];
long long ans[N],fw[N << 2];
stack<int> st;

void update(int idx,long long val){ if(val==1) st.push(idx); idx+=N; while(idx<N << 2) fw[idx]+=val,idx+=(idx & -idx); }

long long read(int idx){ idx+=N; long long val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

void clear(){ while(!st.empty()) update(st.top(),-1),st.pop(); }

void solve(int l,int r)
{
    if(l==r) return;
    int m = (l+r)/2;
    solve(l,m),solve(m+1,r);
    sort(a+l,a+m+1),sort(a+m+1,a+r+1);
    int i = l,j = m+1;
    while(i<=m+1 and j<=r)
    {
        if(a[i].first.first>a[j].first.first) ans[a[j].second]+=read(N)-read(a[j].first.second-1),j++;
        else{ if(i<=m) update(a[i].first.second,1); i++; }
    }
    while(j<=r) ans[a[j].second]+=read(N)-read(a[j].first.second-1),j++;
    clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) 
    {
        int x,y;
        cin >> x >> y;
        a[i] = {{x-y,x+y},i};
    }
    solve(1,n);
    for(int i = 1;i <= n;i++) cout << ans[i] << '\n';
}
