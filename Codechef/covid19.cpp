#include <bits/stdc++.h>
using namespace std;

const int N = 11;

int t,n,a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0;i < N;i++) a[i] = false;
        for(int i = 1;i <= n;i++){ int x; cin >> x; a[x] = true; }
        int now = 0,mn = INT_MAX,mx = INT_MIN,lst = -1;
        for(int i = 0;i < N;i++)
        {
            if((lst==-1 or i-lst<=2) and a[i]) now++,lst = i;
            else if(a[i]) mn = min(mn,now),mx = max(mx,now),now = 1,lst = i;
        }
        mn = min(mn,now),mx = max(mx,now);
        cout << mn << ' ' << mx << '\n';
    }
}
