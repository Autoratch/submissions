#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int N = 1000;

int n,m;
pair<long long,long long> a[N],b[N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 0;i < m;i++) cin >> b[i].x >> b[i].y;

    for(int i = 0;i < n;i++)
    {
        long long x = LLONG_MAX;
        for(int j = 0;j < m;j++)
        {   
            long long tmp = (a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
            x = min(x,tmp);
        }
        ans = max(ans,x);
    }

    double x = ans;
    x = sqrt(x);

    cout << fixed;
    cout << setprecision(4) << x;
}
