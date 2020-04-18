#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n,m;
pair<int,int> a[N],b[N];
int res[N*2],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
    for(int i = 0;i < m;i++) cin >> b[i].first >> b[i].second;

    for(int i = 0;i < m;i++) 
    {
        int tmp = INT_MAX;
        for(int j = 0;j < n;j++) tmp = min(tmp,abs(b[i].first-a[j].first)+abs(b[i].second-a[j].second));
        res[tmp]++;
        ans = max(ans,res[tmp]);
    }

    cout << ans;
}
