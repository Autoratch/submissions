#include <bits/stdc++.h>
using namespace std;

int a[1001];
int ans;
int cnt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    k = (n+1)/2;

    for(int i = 0;i < n;i++){ int x; cin >> x; a[x]++; }

    for(int i = 1;i <= 1000;i++) if(a[i]) 
    {
        if(a[i]/2>k) a[i] = k*2;
        ans+=(a[i]/2)*2,k-=a[i]/2;
        if(a[i]%2) cnt++;
    }

    ans+=min(cnt,k);

    cout << ans;
}
