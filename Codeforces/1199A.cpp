#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,x,y;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x >> y;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        int mn = INT_MAX;
        for(int j = max(0,i-x);j < i;j++) mn = min(mn,a[j]);
        for(int j = min(n-1,i+y);j > i;j--) mn = min(mn,a[j]);
        if(mn>a[i]){ cout << i+1; return 0; }
    }
}
