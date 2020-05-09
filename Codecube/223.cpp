#include <bits/stdc++.h>
using namespace std;

const int N = 7e3 + 1;

int m,n;
char c[N][N];
int a[N][N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> c[i][j],a[i][j] = c[i][j]-'0';
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        if(!a[i][j]) continue;
        a[i][j]+=min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]));
        b[a[i][j]]++;
    }
    for(int i = min(m,n);i >= 1;i--) b[i]+=b[i+1];
    for(int i = 1;i <= min(m,n);i++) cout << b[i] << '\n';
}
