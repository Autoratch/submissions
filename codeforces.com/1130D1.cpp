#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,m;
vector<int> s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for(int i = 0;i < m;i++) 
    {
        int a,b;
        cin >> a >> b;
        s[a].push_back(b);
    }

    for(int i = 1;i <= n;i++) 
    {
        int ans = 0;
        for(int j = 1;j <= n;j++)
        {
            int each = INT_MAX;
            for(int k = 0;k < s[j].size();k++)
            {   
                int dis = s[j][k]-j;
                if(dis<0) dis+=n;
                each = min(each,dis);
            }
            int dis = j-i;
            if(dis<0) dis+=n;
            if(each==INT_MAX) continue;
            ans = max(ans,dis+n*((int)s[j].size()-1)+each);
        }
        cout << ans << ' ';
    }
}
