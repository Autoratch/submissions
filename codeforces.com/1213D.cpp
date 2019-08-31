#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,k;
int a[N],sz[N],res[N];
queue<pair<int,int> > q;
int mn = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        q.push({a[i],0});
    }

    while(!q.empty())
    {
        int p = q.front().first,lv = q.front().second;
        q.pop();
        res[p]+=lv,sz[p]++;
        if(sz[p]==k) mn = min(mn,res[p]); 
        if(p) q.push({p/2,lv+1});
    }

    cout << mn;
}