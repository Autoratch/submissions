#include <bits/stdc++.h>
using namespace std;

const int N = 3001;

int m,n;
char s[N][N];
int ao[N][N],ai[N][N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        cin >> s[i][j];
        if(s[i][j]=='O') ao[i][j]++;
        else if(s[i][j]=='I') ai[i][j]++;
    }
    for(int i = m;i >= 1;i--) for(int j = n;j >= 1;j--) ao[i][j]+=ao[i][j+1],ai[i][j]+=ai[i+1][j];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) if(s[i][j]=='J') ans+=(long long)ao[i][j]*(long long)ai[i][j];
    cout << ans;
}
