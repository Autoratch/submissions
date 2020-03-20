#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int MOD = 998244353;

int n,k;
long long ans = 1,sum;
pair<int,int> a[N];
vector<int> b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> a[i].first,a[i].first*=-1,a[i].second = i+1;
    sort(a,a+n);
    for(int i = 0;i < k;i++) b.push_back(a[i].second);
    sort(b.begin(),b.end());
    for(int i = 0;i < k-1;i++) ans = (ans*(long long)(b[i+1]-b[i]))%MOD;
    for(int i = 0;i < k;i++) sum-=a[i].first;
    cout << sum << ' ' << ans;
}
