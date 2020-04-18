#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m,n;
    cin >> m >> n;
    if(m==1 and n==1){ cout << "0"; return 0; }
    for(int i = 1;i <= m;i++){ for(int j = 1;j <= n;j++) if(m<n) cout << i*(j+m) << ' '; else cout << j*(i+n) << ' '; cout << '\n'; }
}
