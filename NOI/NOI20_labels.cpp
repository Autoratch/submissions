#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i < n;i++) cin >> a[i];
    int x = 0,mn = 0,mx = 0;
    for(int i = 1;i < n;i++)
    {
        x+=a[i];
        mn = min(mn,x),mx = max(mx,x);
    }
    if(mx-mn!=n-1){ cout << "-1"; return 0; }
    x = 0;
    cout << x+1-mn << ' ';
    for(int i = 1;i < n;i++)
    {
        x+=a[i];
        cout << x+1-mn << ' ';
    }
}
