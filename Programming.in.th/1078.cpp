#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

long long n,ans,a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    for(int i = 0;i < n/2;i++) ans-=a[i];
    for(int i = n/2;i < n;i++) ans+=a[i];

    cout << ans;
}
