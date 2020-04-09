#include <bits/stdc++.h>
using namespace std;

const int N = 351;
const int MOD = 29947;

int x,y,z;
int a[N][N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> x >> y >> z;

    x--,y--,z--;

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++)
    {
        if(i==0 or j==0) a[i][j] = 1;
        else a[i][j] = a[i-1][j]+a[i][j-1];
    }

    for(int i = 1;i <= x;i++) for(int j = 1;j <= y;j++)
    {
        int res = (a[i-1][j-1]*a[x-i+y-j][z])%MOD;
        ans = (ans+res)%MOD;
    }

    ans = (ans+a[x+y][z])%MOD;

    cout << ans;
}
