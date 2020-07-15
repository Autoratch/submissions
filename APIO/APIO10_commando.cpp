#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int t,n;
long long s[N],dp[N],ax,bx,cx;
vector<long long> m,b;

bool bad(int l1,int l2,int l3)
{
    return (double)(b[l2]-b[l3])*(m[l2]-m[l1])<(double)(b[l1]-b[l2])*(m[l3]-m[l2]);
}

void add(long long mx,long long bx)
{
    m.push_back(mx),b.push_back(bx);
    while(m.size()>2 and bad(m.size()-3,m.size()-2,m.size()-1))
        m.erase(m.end()-2),b.erase(b.end()-2);
}

int ptr;

long long query(long long x)
{
    if(ptr>=m.size()) ptr = m.size()-1;
    while(ptr<m.size()-1 and m[ptr+1]*x+b[ptr+1]>m[ptr]*x+b[ptr]) ptr++;
    return m[ptr]*x+b[ptr];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> ax >> bx >> cx;
        for(int i = 1;i <= n;i++) cin >> s[i],s[i]+=s[i-1];
        m.clear(),b.clear(),ptr = 0;
        add(0,0);
        for(int i = 1;i <= n;i++)
        {
            dp[i] = ax*s[i]*s[i]+bx*s[i]+cx+query(-2*ax*s[i]);
            add(s[i],dp[i]+ax*s[i]*s[i]-bx*s[i]);
        }
        cout << dp[n] << '\n';
    }
}
