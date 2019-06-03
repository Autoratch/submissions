#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int q,n,m;
int a[N];
set<int> s;
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> a[i];
        cout << m-1 << '\n'; continue;
/*        s.clear();
        s.insert(0);
        ans = 0;
        for(int i = 0;i < m;i++)
        {
            if(s.find(i)==s.end()) continue;
            for(int j = 0;j < n;j++) s[i+a[j]] = true;
            if(s[i]) ans = i;
        }
        cout << ans << '\n';*/
    }
}
