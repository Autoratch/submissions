#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N*2];
vector<long long> s[N],c;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n*2;i++)
    {
        cin >> a[i];
        s[a[i]].push_back(i);
    }
    c.push_back(0);
    c.push_back(0);

    for(int i = 1;i <= n;i++) ans+=abs(c[0]-s[i][0])+abs(c[1]-s[i][1]),c = s[i];

    cout << ans;
}
