#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int a,b;
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    ans = 4;

    for(int i = 1;i < a;i++) ans = (ans*2)%MOD;
    for(int i = 1;i < b;i++) ans = (ans*2)%MOD;

    cout << ans;
}
