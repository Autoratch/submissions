#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e7;

int n;
long long s[N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        long long a,b;
        cin >> a >> b;
        s[a] = max(s[a],b);
    }

    for(int i = 1e7;i > 0;i--) s[i] = max(s[i],s[i+1]),ans+=s[i];

    cout << ans;
}
