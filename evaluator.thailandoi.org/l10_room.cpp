#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 3;
long long ans = 1,tmp = 1,tmm = 1; 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long a,b;
    
    cin >> a >> b;

    for(long long i = b+1;i <= a;i++) ans = (ans*i)%MOD;
    for(long long i = 1;i <= a-b;i++) tmp = (tmp*i)%MOD;
    for(long long i = 1;i <= MOD-2;i++) tmm = (tmm*tmp)%MOD;
    
    ans = (ans*tmm)%MOD;

    cout << ans;
}
