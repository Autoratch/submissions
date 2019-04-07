#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int m,n;
int a[N][N],r[N][N],c[N][N],mxr[N],mxc[N];
set<int> s;
unordered_map<int,vector<int> > ma;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < m;i++)
    {
        s.clear();
        ma.clear();
        for(int j = 0;j < n;j++){ s.insert(a[i][j]); ma[a[i][j]].push_back(j); }
        mxr[i] = s.size();
        int cnt = 1;
        for(auto it = s.begin();it != s.end();it++)
        {
            for(int j = 0;j < ma[*it].size();j++)
                r[i][ma[*it][j]] = cnt;
            cnt++;
        }
    }

    for(int i = 0;i < n;i++)
    {
        s.clear();
        ma.clear();
        for(int j = 0;j < m;j++){ s.insert(a[j][i]); ma[a[j][i]].push_back(j); }
        mxc[i] = s.size();
        int cnt = 1;
        for(auto it = s.begin();it != s.end();it++)
        {
            for(int j = 0;j < ma[*it].size();j++)
                c[ma[*it][j]][i] = cnt;
            cnt++;
        }
    }

    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
            cout << max(mxr[i]+max(r[i][j],c[i][j])-r[i][j],mxc[j]+max(r[i][j],c[i][j])-c[i][j]) << ' ';
        cout << '\n';
    }

}
