#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,k,m,l,x,y,id,st,en;
int s[N],a[N],b[N],bf[N],at[N];
int ax[N],by[N];
vector<int> res[N];
int marked[N],cnt,pl[N],ppl;
bool flg;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) scanf("%d",s+i);
    scanf("%d%d",&m,&l);
    for(int i = 1;i <= m;i++) scanf("%d",a+i);
    for(int i = 1;i <= l;i++) scanf("%d",b+i);
    for(int i = 1;i <= n;i++) marked[s[i]]++;
    for(int i = 1;i <= k;i++) res[i].resize(marked[i]),marked[i] = 0;
    for(int i = 1;i <= n;i++) res[s[i]][marked[s[i]]++] = i;
    for(int i = 1;i <= k;i++)
    {
        for(int j = 0;j+1 < res[i].size();j++) bf[res[i][j+1]] = res[i][j],at[res[i][j]] = res[i][j+1];
    }
    x = res[a[1]][0];
    y = x,id = 1;
    pl[ppl++] = y;
//    pl.push_back(y);
    while(id<m and y<=n)
    {
        if(s[y]==a[id+1]) pl[ppl++] = y,id++;
        y++;
    }
    y--;
    if(ppl!=m){ printf("0"); return 0; }
    ax[x] = pl[ppl-1];
    for(int x : res[a[1]])
    {
        if(flg){ ax[x] = -1; continue; }
        pl[0] = x;
        for(int j = 1;j < ppl;j++)
        {
            while(pl[j] and pl[j]<pl[j-1]) pl[j] = at[pl[j]];
            if(!pl[j]){ ax[x] = -1; break; }
        }
        if(ax[x]!=-1) ax[x] = pl[ppl-1];
        else flg = true;
    }
    ppl = 0;
    x = res[b[1]].back();
    y = x,id = 1;
    pl[ppl++] = y;
    while(id<l and y>=1)
    {
        if(s[y]==b[id+1]) pl[ppl++] = y,id++;
        y--;
    }
    y++;
    if(ppl!=l){ printf("0"); return 0; }
    by[x] = ppl;
    flg = false;
    reverse(res[b[1]].begin(),res[b[1]].end());
    for(int x : res[b[1]])
    {
        if(flg){ by[x] = -1; continue; }
        pl[0] = x;
        for(int j = 1;j < ppl;j++)
        {
            while(pl[j] and pl[j]>pl[j-1]) pl[j] = bf[pl[j]];
            if(!pl[j]){ by[x] = -1; break; }
        }
        if(by[x]!=-1) by[x] = pl[ppl-1];
        else flg = true;
    }
    reverse(res[b[1]].begin(),res[b[1]].end());
    for(int i = 1;i <= n;i++) marked[i] = 0;
    for(int i = 1;i <= k;i++)
    {   
        if(res[i].size()<2) continue;
        st = res[i][0],en = res[i].back();
        auto itl = upper_bound(res[a[1]].begin(),res[a[1]].end(),st);
        auto itr = lower_bound(res[b[1]].begin(),res[b[1]].end(),en);
        if(itl==res[a[1]].end() or itr==res[b[1]].begin()) continue;
        itr--;
        x = ax[*itl],y = by[*itr];
        if(x>y) continue;
        if(x==-1 or y==-1) continue;
        marked[x]++,marked[y+1]--;
    }
    for(int i = 1;i <= n;i++) marked[i]+=marked[i-1];
    for(int i = 1;i <= n;i++) if(marked[i] and s[i]==a[m]) cnt++;
    printf("%d\n",cnt);
    for(int i = 1;i <= n;i++) if(marked[i] and s[i]==a[m]) printf("%d ",i);
}

