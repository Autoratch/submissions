#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n;
int b[N],a[N],mx;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++)
    {
        if(i==1) a[i] = b[i];
        else a[i] = mx+b[i];
        mx = max(mx,a[i]);
    }
    for(int i = 1;i <= n;i++) cout << a[i] << ' ';
}   
