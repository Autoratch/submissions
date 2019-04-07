#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1001;

int n,m;
int a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++){ cin >> a[i]; a[i]+=a[i-1];}

    for(int i = 1;i <= n;i++) s[i] = INT_MAX;

    for(int i = 1;i <= n;i++) for(int j = i;j <= n;j++) s[j-i+1] = min(s[j-i+1],a[j]-a[i-1]);

    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(s,s+n,x);
        cout << it-s-1 << endl;
    }
}