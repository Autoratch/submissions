#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n,ans = INT_MAX;
vector<int> a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    b.resize(n);
    if(a==b) ans = 0;

    for(int i = 1;i < (1 << n);i++)
    {
        b.assign(n,false);
        int tmp = i,idx = 0,cnt = 0;
        while(tmp)
        {
            if(tmp%2)
            {
                b[idx] = !b[idx];
                if(idx>0) b[idx-1] = !b[idx-1];
                if(idx<n-1) b[idx+1] = !b[idx+1];
            }
            cnt+=tmp%2;
            tmp/=2;
            idx++;
        }
        if(a==b) ans = min(ans,cnt); 
    }

    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
