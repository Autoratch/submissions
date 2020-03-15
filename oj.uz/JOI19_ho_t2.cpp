#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5;
 
int n,m;
pair<long long,long long> a[N];
long long b[N],ans;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i].second >> a[i].first;
    for(int i = 0;i < m;i++) cin >> b[i];
    sort(a,a+n),sort(b,b+m);
    int i = n-1,j = m-1;
    while(i>=0 and j>=0)
    {
        if(b[j]>=a[i].second) ans++,i--,j--;
        else i--;
    }
    cout << ans;
}
