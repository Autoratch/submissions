#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int m,n,k,x;
int idx[N],tid[N],val[N];
map<int,vector<int> > res;
vector<int> tmp;
int ans;
bool used;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    for(int i = 1;i <= n;i++) cin >> val[i];
    for(int i = 1;i <= n;i++) idx[i] = tid[i] = i;

    for(int i = 0;i < k;i++)
    {
        int id,h;
        cin >> id >> h;
        res[h].push_back(id);
    }
    cin >> x;

    for(auto it = res.rbegin();it != res.rend();it++)
    {
        tmp = it->second;
        for(int j = 0;j < tmp.size();j++) swap(idx[tmp[j]],idx[tmp[j]+1]);
    }

    ans = val[idx[x]];
    used = false;

    if(x>1) 
    {
        if(val[x+1]>ans){ ans = val[x+1]; used = true; }
    }
    if(x<n)
    {
        if(val[x-1]>ans){ ans = val[x-1]; used = true; }
    }

    for(auto it = res.rbegin();it != res.rend();it++)
    {
        tmp = it->second;
        for(int j = 0;j < tmp.size();j++)
        {
            swap(tid[tmp[j]],tid[tmp[j]+1]);
            if(tid[tmp[j]]==x and tmp[j]>1)
            {
                if(val[tid[tmp[j]-1]]>ans){ ans = val[tid[tmp[j]-1]]; used = true; }
            }
            if(tid[tmp[j]+1]==x and tmp[j]+1<n)
            {
                if(val[tid[tmp[j]+2]]>ans){ ans = val[tid[tmp[j]+2]]; used = true; }
            }
        }
    }

    cout << ans << '\n';
    if(used) cout << "USE";
    else cout << "NO";
}
