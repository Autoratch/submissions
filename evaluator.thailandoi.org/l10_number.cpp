#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;  
    int a[9];
    int mn = INT_MAX;
    int d;

    cin >> n;
    for(int i = 0;i < 9;i++) cin >> a[i];
    for(int i = 0;i < 9;i++) mn = min(mn,a[i]);

    d = n/mn;
    int used = 0;

    for(int i = 0;i < d;i++)
    {
        int mx = 0;
        for(int j = 0;j < 9;j++)
        {
            if(n-used-a[j]>=mn*(d-i-1)) mx = j;
        }
        cout << mx+1;
        used+=a[mx];
    }
}
