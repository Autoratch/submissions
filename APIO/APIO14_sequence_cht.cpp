#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
const int K = 201;
 
int n,k;
long long s[N];
int dp[N][K];
long long val[N][2];
vector<long long> m,b,id;
 
bool bad(int l1,int l2,int l3)
{
    return (double)(b[l2]-b[l3])*(m[l2]-m[l1])<(double)(b[l1]-b[l2])*(m[l3]-m[l2]);
}
 
void add(long long mx,long long bx,long long idx)
{
    if(!m.empty() and m.back()==mx and b.back()==bx) return;
    m.push_back(mx),b.push_back(bx),id.push_back(idx);
    while(m.size()>2 and bad(m.size()-3,m.size()-2,m.size()-1))
        m.erase(m.end()-2),b.erase(b.end()-2),id.erase(id.end()-2);
}
 
int ptr;
 
void query(long long x,long long &a,int &bb)
{
    if(m.empty()) return void(a = bb = 0);
    if(ptr>=m.size()) ptr = m.size()-1;
    while(ptr<m.size()-1 and m[ptr+1]*x+b[ptr+1]>=m[ptr]*x+b[ptr]) ptr++;
    a = m[ptr]*x+b[ptr];
    bb = id[ptr];
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> k; 
    for(int i = 1;i <= n;i++) cin >> s[i],s[i]+=s[i-1];
    int now = 1,prev = 0;
    for(int j = 0;j <= k;j++)
    {
        m.clear(),b.clear(),id.clear();
        ptr = 0;
        for(int i = 1;i <= n;i++)
        {
            if(j) query(s[i],val[i][now],dp[i][j]);
            if(i!=n and !((j-1)>1 and !dp[i][j-1]) and j-1<i) add(s[i],val[i][prev]-s[i]*s[i],i);
        }
        swap(now,prev);
    }
    cout << val[n][prev] << '\n';
    vector<int> ans;
    int l = k;
    for(int x = dp[n][k];x;x = dp[x][--l]) ans.push_back(x);
    reverse(ans.begin(),ans.end());
    for(int x : ans) cout << x << ' ';
}
