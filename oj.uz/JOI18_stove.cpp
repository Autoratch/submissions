#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,k,ans,all;
int a[N],pa[N];
priority_queue<pair<int,pair<int,int> > > q;

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i],pa[i] = i;

    sort(a,a+n);

    for(int i = 0;i < n-1;i++) q.push({a[i]-a[i+1],{i,i+1}}),all+=a[i+1]-a[i];

    for(int i = 0;i < n-k;i++)
    {
        while(!q.empty() and root(q.top().second.first)==root(q.top().second.second)) q.pop();
        int a = q.top().second.first,b = q.top().second.second;
        ans-=q.top().first;
        pa[root(a)] = root(b);
    }

    cout << ans+k;
}
