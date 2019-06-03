#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int m,n,mn[N*2];
char a[N][N];
bool g[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];
    for(int i = 0;i < m+n;i++) mn[i] = INT_MAX;

    g[0][0] = true;
    for(int s = 1;s < m+n;s++)
    {
        for(int i = 0;i < m;i++) 
        {
            int j = s-i;
            if(j>=n or j<0) continue;
            bool f = false;
            if(i>0 and g[i-1][j]) f = true;
            if(j>0 and g[i][j-1]) f = true;
            if(!f) continue;
            mn[s] = min(mn[s],a[i][j]-'a');
        }
        for(int i = 0;i < m;i++)
        {
            int j = s-i;
            if(j>=n or j<0) continue;
            bool f = false;
            if(i>0 and g[i-1][j]) f = true;
            if(j>0 and g[i][j-1]) f = true;
            if(!f) continue;
            if(mn[s]<a[i][j]-'a') continue;
            //else if(mn[s]==INT_MAX) mn[s] = a[i][j]-'a';
            g[i][j] = true;
        }
    }

    string s;

    for(int x = m-1,y = n-1;x>0 or y>0;)
    {
        s+=a[x][y];
        if(x==0 or g[x][y-1]) y--;
        else x--;
    }

    s+=a[0][0];

    reverse(s.begin(),s.end());

    cout << s;
}
