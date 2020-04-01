#include <bits/stdc++.h>
using namespace std;

int t,n,k;
string s;
int c[26][200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        int ans = 0;
        for(int i = 0;i < k;i++) for(int j = 0;j < 26;j++) c[j][i] = 0;
        for(int i = 0;i < k;i++)
        {
            for(int j = 0;j < n/k;j++) c[s[i+j*k]-'a'][i]++;
        }
        int l = 0,r = k-1;
        while(l<=r)
        {
            int mx = 0;
            for(int i = 0;i < 26;i++) mx = max(mx,c[i][l]+c[i][r]);
            if(l!=r) ans+=n/k+n/k-mx;
            else ans+=n/k-mx/2;
            l++,r--;
        }
        cout << ans << '\n';
    }
}
