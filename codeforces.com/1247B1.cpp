#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

int t,n,k,d;
int a[N],s[N],lst[N];

void update(int idx,int val){ while(idx<N) s[idx]+=val,idx+=(idx & -idx);  }

int read(int idx){ if(!idx) return 0; int val = 0; while(idx) val+=s[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> k >> n >> d;
        for(int i = 1;i <= k;i++) cin >> a[i];
        for(int i = 1;i <= max(n,k);i++) s[i] = 0,lst[i] = 0;
        int ans = INT_MAX;
        for(int i = 1;i <= k;i++)
        {
            if(lst[a[i]]) update(lst[a[i]],-1);
            update(i,1);
            if(i>=d) ans = min(ans,read(i)-read(i-d));
            lst[a[i]] = i;
        }
        cout << ans << '\n';
    }
}
