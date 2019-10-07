#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int m,n;
vector<tuple<int,int,int> > ed,im,nm;
int pa[N],l[N],r[N];

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n-1;j++)
        {
            int a = i*n+j,b = a+1,d;
            cin >> d;
            ed.push_back({d,a,b});
        }
        if(i==m-1) continue;
        for(int j = 0;j < n;j++)
        {
            int a = i*n+j,b = a+n,d;
            cin >> d;
            ed.push_back({d,a,b});
        }
    }

    sort(ed.begin(),ed.end());

    for(int i = 0;i < N;i++) pa[i] = i;

    for(int i = 0;i < ed.size();i++)
    {
        int a,b,d; tie(d,a,b) = ed[i];
        if(root(a)==root(b)) nm.push_back(ed[i]);
        else
        {
            pa[root(a)] = root(b);
            im.push_back(ed[i]);
        }
    }

    for(int i = 0;i < nm.size();i++) r[i] = im.size();

    bool status = true;
    vector<int> idx[im.size()+1];

    while(status)
    {
        status = false;
        for(int i = 0;i < im.size();i++) idx[i].resize(0);
        for(int i = 0;i < nm.size();i++)
        {
            if(l[i]<r[i]) status = true;
            int m = (l[i]+r[i])/2;
            idx[m].push_back(i);
        }
        for(int i = 0;i < N;i++) pa[i] = i;
        for(int i = 0;i < im.size();i++)
        {
            int a,b,d; tie(d,a,b) = im[i];
            pa[root(a)] = root(b);
            for(int j = 0;j < idx[i].size();j++)
            {
                int a,b,d; tie(d,a,b) = nm[idx[i][j]];
                if(root(a)==root(b)) r[idx[i][j]] = i;
                else l[idx[i][j]] = i+1;
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0;i < nm.size();i++)
    {
        int a,b,x,y; tie(x,a,b) = nm[i]; tie(y,a,b) = im[l[i]];
        ans = min(ans,x-y);
    }

    cout << ans;
}
