#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
pair<int,pair<int,int> > a[N];
long long x[N],y[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++) cin >> x[i];
    for(int i = 0;i < n;i++) cin >> y[i];
    for(int i = 0;i < n;i++) a[i] = {x[i]-y[i],{x[i],y[i]}};
    sort(a,a+n);
    for(int i = 0;i < n/2;i++)
    {
        long long x = a[i].second.first;
        ans+=x;
    }
    for(int i = (n+1)/2;i < n;i++)
    {
        long long y = a[i].second.second;
        ans+=y;
    }
    if(n%2==1) 
    {
        long long x = a[n/2].second.first,y = a[n/2].second.second;
        ans+=min(x,y);
    }
    cout << ans;
}
