#include <bits/stdc++.h>
using namespace std;

const int N = 15000;

int n,m,dist[N];
pair<int,int> a[N];
priority_queue<int,vector<int>,greater<int> > ans;
long long as;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second,dist[i] = INT_MAX;
    dist[0] = 0;

    for(int i = 0;i < n;i++)
    {
        int each = INT_MAX,id;
        for(int j = 0;j < n;j++) if(dist[j]!=-1 and dist[j]<each) each = dist[j],id = j;
        if(i) ans.push(each);
        dist[id] = -1;
        for(int j = 0;j < n;j++) if(dist[j]!=-1) dist[j] = min(dist[j],abs(a[id].first-a[j].first)+abs(a[id].second-a[j].second)); 
    }

    for(int i = 0;i < n-m;i++)
    {
        long long x = ans.top();
        ans.pop();
        as+=x;
    }

    cout << as;
}
