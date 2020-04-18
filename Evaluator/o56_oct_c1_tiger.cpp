#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int N = 1000;

int m,n;
pair<int,int> a[N],b[N];
int cnt[1000001],mx;

int dist(pair<int,int> a,pair<int,int> b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) cin >> a[i].x >> a[i].y;
    for(int i = 0;i < n;i++) cin >> b[i].x >> b[i].y;

    sort(a,a+m);
    sort(b,b+n);

    for(int i = 0;i < n;i++)
    {
        int mn = INT_MAX;
        for(int j = 0;j < m;j++) mn = min(mn,dist(a[j],b[i]));
        cnt[mn]++;
        mx = max(mx,cnt[mn]);
    }

    cout << mx;
}
