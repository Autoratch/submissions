#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n,m;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        int cnt[n];
        for(int i = 1;i <= n;i++) cnt[i] = 0;
        
        for(int i = 0;i < m;i++)
        {
            int a,b;
            cin >> a >> b;
            cnt[a]++,cnt[b]++;
        }

        int x = -1;
        bool ok = true;
        for(int i = 1;i <= n;i++)
        {
            if(cnt[i]!=0) 
            {
                if(x==-1) x = cnt[i];
                else if(x!=cnt[i]) ok = false; 
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
