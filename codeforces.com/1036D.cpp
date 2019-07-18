#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 100;

int n,m;
long long a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    cin >> m;

    for(int i = 0;i < m;i++) cin >> b[i];

    int i = 0,j = 0,ans = 0;

    while(i<n and j<m)
    {
        if(a[i]==b[j]) ans++,i++,j++;
        else if(a[i]>b[j]) b[j+1]+=b[j],j++;
        else a[i+1]+=a[i],i++;
    }

    if(i<n or j<m) cout << "-1";
    else cout << ans;
}
