#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5;

long long n,k;
pair<long long,long long> a[N],b[N];
long long ans[N],all;
vector<long long> tmp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(long long i = 0LL;i < n;i++)
    {
        cin >> a[i].first >> a[i].second;
        b[i] = {-(min(a[i].first*2LL,a[i].second)-min(a[i].first,a[i].second)),i};
        ans[i] = min(a[i].first,a[i].second);
    }

    sort(b,b+n);

    for(long long i = 0LL;i < k;i++)
    {
        ans[b[i].second]-=b[i].first;
        tmp.push_back(b[i].second+1LL);
    }

    for(long long i = 0LL;i < n;i++) all+=ans[i];

    sort(tmp.begin(),tmp.end());

    for(long long x : tmp) cout << x << ' ';
    cout << '\n' << all;
}
