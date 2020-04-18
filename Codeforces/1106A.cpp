#include <bits/stdc++.h>
using namespace std;

int m,n;
char a[500][500];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    m = n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    int cnt = 0;
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(i+1>=m or j+1>=n) continue;
        if(i-1<0 or j-1<0) continue;
        if(a[i][j]!='X') continue;
        if(a[i-1][j-1]!='X' or a[i-1][j+1]!='X' or a[i+1][j-1]!='X' or a[i+1][j+1]!='X') continue;
        cnt++;
    }

    cout << cnt;
}
