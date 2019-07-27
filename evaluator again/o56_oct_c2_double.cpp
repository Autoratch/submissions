#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N],s[N];
unordered_map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> a[i],s[i] = a[i]+s[i-1];

    for(int i = 1;i <= n;i++) if(s[i]*2==s[n]){ cout << i; return 0; }

    for(int i = 1;i <= n;i++)
    {
        if(s[n]%2==0 and m[s[i]-s[n]/2]){ cout << m[s[i]-s[n]/2] << ' ' << i; return 0; }
        m[s[i]] = i;
    }

    cout << "NO";
    
}
