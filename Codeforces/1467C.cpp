#include <bits/stdc++.h>
using namespace std;

int m,n,l;
vector<int> a,b,c;
long long sa,sb,sc,ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> l;
    for(int i = 0,x;i < m;i++) cin >> x,a.push_back(x),sa+=x;
    for(int i = 0,x;i < n;i++) cin >> x,b.push_back(x),sb+=x;
    for(int i = 0,x;i < l;i++) cin >> x,c.push_back(x),sc+=x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ans = max(ans,sa+sb-sc);
    ans = max(ans,sa+sc-sb);
    ans = max(ans,sc+sb-sa);
    sa-=a[0],sb-=b[0],sc-=c[0];
    ans = max(ans,sa+a[0]+sc-sb-b[0]-c[0]);
    ans = max(ans,sb+b[0]+sc-sa-a[0]-c[0]);
    ans = max(ans,sa+a[0]+sb-sc-c[0]-b[0]);
    ans = max(ans,sc+c[0]+sb-sa-a[0]-b[0]);
    ans = max(ans,sc+c[0]+sa-sb-b[0]-a[0]);
    ans = max(ans,sb+b[0]+sa-sc-c[0]-a[0]);
    ans = max(ans,sa+sb+sc+a[0]-b[0]-c[0]);
    ans = max(ans,sa+sb+sc+b[0]-a[0]-c[0]);
    ans = max(ans,sa+sb+sc+c[0]-b[0]-a[0]);
    cout << ans;    
}