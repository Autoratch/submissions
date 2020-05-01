#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int MOD = 2012;

int n;
string s;
int a[2][N][N];
int now;

int main()
{
    freopen("bbreeds.in","r",stdin);
    freopen("bbreeds.out","w",stdout);
    cin >> s;
    n = s.length();
    s = " "+s;
    a[0][0][0] = 1;
    for(int i = 1;i <= n;i++)
    {
        if(s[i]=='(') now++; else now--;
        for(int j = 0;j <= now;j++) 
        {
            int x = 0;
            if(s[i]=='(') x = 1; else x = -1;
            a[i&1][j][now-j] = 0;
            if(j-x>=0) a[i&1][j][now-j]+=a[1-(i&1)][j-x][now-j];
            if(now-j-x>=0) a[i&1][j][now-j]+=a[1-(i&1)][j][now-j-x];
            a[i&1][j][now-j]%=MOD;
        }
    }
    cout << a[n&1][0][0];
}
