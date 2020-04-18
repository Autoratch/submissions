#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int k,m,pa[N],ch[N],lt[N];
vector<int> res[N];
set<int> s[N];

void update(int si,int x)
{
    if(!x) return;
    int idx = 0;
    for(int tmp : res[x]) if(s[si].find(tmp)==s[si].end()) res[x][idx++] = tmp; 
    res[x].resize(idx);
    update(si,ch[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> m;

    for(int i = 1;i <= k;i++)
    {
        int n;
        cin >> n;
        pa[i] = lt[i] = i;
        for(int j = 0;j < n;j++){ int x; cin >> x; res[i].push_back(x); }
    }

    while(m--)
    {
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1)
        {
            if(pa[a]==0) continue;
            s[pa[a]].insert(b);
        }
        else
        {
            update(pa[a],pa[a]);
            update(pa[b],pa[b]);
            if(pa[b]==0) continue;
            if(pa[a]!=0)
            {
                ch[lt[pa[a]]] = pa[b];
                lt[pa[a]] = lt[pa[b]];
                pa[b] = 0;
            }
            else
            {
                pa[a] = pa[b];
                pa[b] = 0;
            }
        }
    }

    for(int i = 1;i <= k;i++)
    {
        int id = pa[i];
        update(id,id);
        while(id)
        {
            for(int x : res[id]) cout << x << '\n';
            id = ch[id];
        }
    }
}
