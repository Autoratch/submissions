#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t,n,k,ans[N];
vector<int> s[N];
set<int> st;

int ask(int l,int r)
{
    st.clear();
    for(int i = 1;i <= n;i++) st.insert(i);
    for(int i = l;i <= r;i++) for(int j : s[i]) st.erase(j);
    cout << "? " << st.size() << ' ';
    for(int x : st) cout << x << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void solve(int l,int r,int exp)
{
    if(l==r)
    {
        ans[l] = ask(l,r);
        return;
    }
    int m = (l+r)/2;
    int ma = ask(m+1,r);
    if(ma<exp)
    {
        for(int i = l;i <= m;i++) ans[i] = exp;
        solve(m+1,r,exp);
    }
    else
    {
        for(int i = m+1;i <= r;i++) ans[i] = exp;
        solve(l,m,exp);
    }
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= k;i++)
        {
            s[i].clear();
            int am; cin >> am;
            while(am--){ int x; cin >> x; s[i].push_back(x); }
        }
        solve(1,k,ask(0,0));
        cout << "! ";
        for(int i = 1;i <= k;i++) cout << ans[i] << ' ';
        cout << endl;
        string ss;
        cin >> ss;
    }
}
