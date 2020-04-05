#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t,n;
pair<pair<int,int>,int> a[N];
char ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int c = 1;c <= t;c++)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i].first.first >> a[i].first.second,a[i].second = i;
        sort(a+1,a+n+1);
        int x = 0,y = 0;
        string an = ""; 
        for(int i = 1;i <= n;i++)
        {
            if(a[i].first.first>=x) ans[a[i].second] = 'J',x = a[i].first.second;
            else if(a[i].first.first>=y) ans[a[i].second] = 'C',y = a[i].first.second;
            else{ an = "IMPOSSIBLE"; break; }
        }
        cout << "Case #" << c << ": ";
        if(an[0]=='I') cout << "IMPOSSIBLE";
        else for(int i = 1;i <= n;i++) cout << ans[i];
        cout << '\n';
    }
}
