#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        long long x;
        cin >> x;
        int cnt = 0;
        while(x%2==0) x/=2,cnt++;
        while(x%3==0) x/=3,cnt+=2;
        while(x%5==0) x/=5,cnt+=3;
        if(x!=1) cout << "-1";
        else cout << cnt;
        cout << '\n';
    }
}
