#include <bits/stdc++.h>
using namespace std;

int n,res[3001],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 2;i <= n;i++)
    {
        for(int j = 2;j < i;j++) if(i%j==0 and !res[j]) res[i]++;
        if(res[i]==2) ans++;
    }

    cout << ans;
}
