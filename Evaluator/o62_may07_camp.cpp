#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,int> 

const int N = 3e5;

int n;
vector<pii> s;
long long dp[N][2],ans;
int tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r) return void(tree[idx] = s[l].second);
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = max(tree[idx*2],tree[idx*2+1]);
}

int read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return max(read(l,m,idx*2,x,y),read(m+1,r,idx*2+1,x,y));
}

int get(int l,int r)
{
    if(l>r) return 0;
    return read(0,n-1,1,l,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++)   
    {
        int a,b,w;
        cin >> a >> b >> w;
        s.push_back({{b,a},w});
    }
    sort(s.begin(),s.end());
    build(0,n-1,1);
    //for(int i = 0;i < n;i++) cout << i << ' ' << s[i].first.second << ' ' << s[i].first.first << ' ' << s[i].second << '\n';
    for(int i = 0;i < n;i++) 
    {
        int l = s[i].first.second,w = s[i].second;
        auto it = lower_bound(s.begin(),s.end(),make_pair(make_pair(l,INT_MIN),INT_MIN)); 
        if(it==s.begin())
        {
            dp[i][0] = dp[i][1] = w;
            if(i) dp[i][1] = max(dp[i][1],dp[i-1][0]+w);
            dp[i][1] = max(dp[i][1],(long long)w+get(0,i-1));
        }
        else
        {
            it--;
            int j = it-s.begin();       
            dp[i][0] = w+dp[j][0];
            dp[i][1] = w+dp[j][1];
            if(i) dp[i][1] = max(dp[i][1],dp[i-1][0]+w);
            dp[i][1] = max(dp[i][1],w+dp[j][0]+get(j+1,i-1));
        }
        if(i) dp[i][0] = max(dp[i][0],dp[i-1][0]),dp[i][1] = max(dp[i][1],dp[i-1][1]);
        ans = max(ans,max(dp[i][0],dp[i][1]));
        //cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    cout << ans;
}
