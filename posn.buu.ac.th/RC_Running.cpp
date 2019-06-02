#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n,m;
int a[N];
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    int now = 0;
int ans = 0;
    for(int i = 0;i < n;i++) 
    {
        if(a[i]>m) ans+=now;
        else now+=(m-a[i])*2;
        ans+=abs(m-a[i]);
        
    }

    cout << ans;
}
