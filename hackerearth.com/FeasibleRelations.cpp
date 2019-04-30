#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int t,n,m;
int pa[N];
vector<pair<int,int> > eq,nq;

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;i++) pa[i] = i;
        eq.clear(),nq.clear();
        for(int i = 0;i < m;i++)
        {
            int a,b;
            string s;
            cin >> a >> s >> b;
            if(s=="=") eq.push_back({a,b});
            else nq.push_back({a,b});
        }
        for(pair<int,int> x : eq)
        {
            int a = x.first,b = x.second;
            if(root(a)!=root(b)) pa[root(a)] = root(b);
        }
        bool ok = true;
        for(pair<int,int> x : nq)
        {
            int a = x.first,b = x.second;
            if(root(a)==root(b)){ ok = false; break; }
        }
        if(!ok) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }
}
