#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int t,n,k;
int a[N],b[N];
set<int> s;

bool solve(int m)
{
    s.clear();
    int cnt = 0,cur = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i]>m) return false;
        if(s.find(b[i])!=s.end() or cur+a[i]>m) cur = a[i],cnt++,s.clear(),s.insert(b[i]);
        else cur+=a[i],s.insert(b[i]);
    }
    if(cur) cnt++;
    return cnt<=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        for(int i = 0;i < n;i++) cin >> a[i] >> b[i];
        int l = 0,r = 1e8 + 1;
        while(l<r)
        {
            int m = (l+r)/2;
            if(solve(m)) r = m;
            else l = m+1;
        }
        if(l==1e8 + 1) l = -1;
        cout << l << '\n';
    }
}
