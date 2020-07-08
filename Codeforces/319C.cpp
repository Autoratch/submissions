#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
long long a[N],b[N],dp[N];
vector<long long> m,c;

bool bad(int l1,int l2,int l3)
{
    return (double)(c[l2]-c[l3])*(m[l2]-m[l1])<(double)(c[l1]-c[l2])*(m[l3]-m[l2]);
}

void add(long long mx,long long cx)
{
    m.push_back(mx),c.push_back(cx);
    while(m.size()>=3 and bad(m.size()-3,m.size()-2,m.size()-1)) 
        m.erase(m.end()-2),c.erase(c.end()-2);
}

int ptr;
long long query(long long x)
{
    if(ptr>=m.size()) ptr = m.size()-1;
    while(ptr<m.size()-1 and m[ptr+1]*x+c[ptr+1]<m[ptr]*x+c[ptr]) ptr++;
    return m[ptr]*x+c[ptr];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++)
    {
        if(i>1) dp[i] = query(a[i]);
        add(b[i],dp[i]);
    }
    cout << dp[n];
}
