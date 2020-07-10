#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n;
tuple<long long,long long,long long> x[N];
long long dp[N];
vector<long long> m,b;
long long ans;

bool bad(int l1,int l2,int l3)
{
    return (double)(b[l3]-b[l2])*(m[l1]-m[l2])<(double)(b[l2]-b[l1])*(m[l2]-m[l3]);
}

void add(long long mx,long long bx)
{
    m.push_back(mx),b.push_back(bx);
    while(m.size()>=3 and bad(m.size()-3,m.size()-2,m.size()-1)) 
        m.erase(m.end()-2),b.erase(b.end()-2);
}

int ptr;

long long query(long long x)
{
    if(ptr>=m.size()) ptr = m.size()-1;
    while(ptr<m.size()-1 and m[ptr+1]*x+b[ptr+1]<=m[ptr]*x+b[ptr]) ptr++;
    return m[ptr]*x+b[ptr];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        long long a,b,c;
        cin >> a >> b >> c;
        x[i] = {a,b,c};
    }
    sort(x+1,x+n+1),reverse(x+1,x+n+1);
    for(int i = 1;i <= n;i++)
    {
        auto [a,b,c] = x[i];
        dp[i] = a*b-c;
        if(i>1) dp[i]-=min(query(-a),0LL);
        add(-b,-dp[i]);
        ans = max(ans,dp[i]);
    }
    cout << ans;
}
