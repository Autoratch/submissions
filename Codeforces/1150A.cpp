#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int n,m,a[N],b[N],mx,mn = INT_MAX,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) cin >> a[i],mn = min(mn,a[i]);
    for(int i = 0;i < m;i++) cin >> b[i],mx = max(mx,b[i]);

    int bu = k/mn;
    
    if(mx<mn) cout << k;
    else cout << k+bu*(mx-mn);
}
