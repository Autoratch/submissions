#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n,l;
struct node{ int d; vector<int> st; };
node res[N];
int dp[1 << N],ans = INT_MAX;

int main()
{
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);
    cin >> n >> l;
    for(int i = 0;i < n;i++) 
    {
        cin >> res[i].d;
        int am;
        cin >> am;
        while(am--){ int x; cin >> x; res[i].st.push_back(x); }
    }
    for(int i = 0;i < (1 << n);i++)
    {
        if(dp[i]>=l) 
        {
            int cnt = 0;
            for(int j = 0;j < n;j++) if((1 << j)&i) cnt++;
            ans = min(ans,cnt);
            continue;
        }
        for(int j = 0;j < n;j++) if(!((1 << j)&i)) 
        {
            int k = i+(1 << j);
            auto it = upper_bound(res[j].st.begin(),res[j].st.end(),dp[i]);
            if(it==res[j].st.begin()) continue;
            it--;
            dp[k] = max(dp[k],res[j].d+*it);
        }
    }
    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
