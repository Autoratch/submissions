#include <bits/stdc++.h>
using namespace std;

int t,n;
long long l,r;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        long long cur = 0;
        for(int i = 1;i < n;i++)
        {
            long long each = 2*(n-i);
            if(l>each+cur){ cur+=each; continue; }
            int id = (l-cur+1LL)/2+i,ix = (r-cur+1LL)/2+i;
            if((l-cur)%2LL==0) cout << id << ' ',id++;
            cur+=(id-i-1)*2;
            for(int j = id;j <= min(n,ix);j++) 
            {
                cout << i << ' ',cur++;
                if(cur>=r) break;
                cout << j << ' ',cur++;
                if(cur>=r) break;
            }
            if(cur>=r) break;
            l = cur+1LL;
        }
        if(cur<r) cout << "1";
        cout << '\n';
    }
}
