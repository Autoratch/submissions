#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    int a[n];

    int sum = 0;
    for(int i = 0;i < n;i++) cin >> a[i],sum+=a[i];

    int cnt = 0,ch = 0;
    
    cnt = 1,ch = a[0];
    for(int i = 1;i < n;i++) if(a[0]>=a[i]*2) cnt++,ch+=a[i];

    if(ch<=sum/2) cout << "0";
    else
    {
        cout << cnt << '\n' << "1 ";
        for(int i = 1;i < n;i++) if(a[0]>=a[i]*2) cout << i+1 << ' ';
    }
}
