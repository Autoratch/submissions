#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> a[5001];
int s[5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> s[i];

    for(int i = 1;i <= n;i++)
    {
        a[i] = a[i-1];
        a[i][s[i]]++;
    }

    while(m--)
    {
        int l,r;
        cin >> l >> r;
        int ans= 0;
        for(auto it = a[r].begin();it != a[r].end();it++) 
        {
            int x = it->first,y = it->second;
            if(y-a[l-1][x]==2) ans++;
        }

        cout << ans << '\n';
    }
}
