#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;

int m,n;
int a[N],cnt;
vector<int> ans[10];

void solve(int x,int lv)
{
    if(x*2<=n) solve(x*2,lv+1);
    ans[lv].push_back(a[cnt]); cnt++;
    if(x*2+1<=n) solve(x*2+1,lv+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;
    n = 1 << m;
    n--;

    for(int i = 0;i < n;i++) cin >> a[i];

    solve(1,0);

    for(int i = 0;i < m;i++) 
    {
        for(int x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
}
