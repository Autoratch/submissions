#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,a[3];
long long s[3][N];

long long cal(int x[3])
{
    long long now = 0;
    for(int i = 0;i < 3;i++) for(int j = i+1;j < 3;j++) now+=(s[i][x[i]]-s[j][x[j]])*(s[i][x[i]]-s[j][x[j]]);
    return now;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        for(int i = 0;i < 3;i++) cin >> a[i];
        for(int i = 0;i < 3;i++) for(int j = 1;j <= a[i];j++) cin >> s[i][j];
        for(int i = 0;i < 3;i++) sort(s[i]+1,s[i]+a[i]+1);
        int x[] = {1,1,1};
        long long ans = LLONG_MAX;
        while(true)
        {
            ans = min(ans,cal(x));
            int mv = -1;
            long long nx = LLONG_MAX;
            for(int i = 0;i < 3;i++) if(x[i]<a[i])
            {
                x[i]++;
                if(cal(x)<nx) nx = cal(x),mv = i;
                x[i]--;
            }
            if(mv==-1) break;
            x[mv]++;
        }
        cout << ans << '\n';
    }
}
