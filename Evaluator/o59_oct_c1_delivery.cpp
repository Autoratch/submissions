#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int k,l,q,am,sz;
pair<int,int> inl[5];
set<int> st;
int val[10],idx[N];
int dist[10][10],f[N],dis[N],tmp[10][2];
vector<int> s;

struct node
{
    int fi,val;
    friend node operator+(const node &a,const node &b)
    {
        if(a.fi<b.fi) return a;
        else return b;
    }
}tree[N << 1];

void dfs(int u)
{
    s.push_back(u);
    f[u] = s.size();
    for(int v = u*2;v <= u*2+1;v++)
    {
        if(v>=(1 << k)) continue;
        dis[v] = dis[u]+1;
        dfs(v);
        s.push_back(u);
    }
}

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].fi = f[s[l]]; tree[idx].val = s[l]; return; }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret; ret.fi = INT_MAX; ret.val = -1; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> l >> q;

    for(int i = 0;i < l;i++)
    {
        int a,b;
        cin >> a >> b;
        inl[i] = {a,b};
        st.insert(a);
        st.insert(b);
    }

    am = st.size();
    int cn = 0;
    for(auto it = st.begin();it != st.end();it++)
    {
        val[cn] = *it;
        idx[*it] = cn;
        cn++;
    }

    for(int i = 0;i < am;i++) for(int j = i+1;j < am;j++) dist[i][j] = dist[j][i] = INT_MAX;

    for(int i = 0;i < l;i++)
    {
        int a,b;
        a = inl[i].first,b = inl[i].second;
        dist[idx[a]][idx[b]] = dist[idx[b]][idx[a]] = 1;        
    }

    dfs(1);
    sz = s.size();
    build(0,sz-1,1);

    for(int i = 0;i < am;i++) for(int j = 0;j < am;j++) 
    {
        int a = val[i],b = val[j];
        if((a<(1 << k) and b>(1 << k)) or (a>(1 << k) and b<(1 << k))) continue;
        if(a>(1 << k)) a-=(1 << k),b-=(1 << k);
        if(f[a]>f[b]) swap(a,b);
        dist[i][j] = dis[a]+dis[b]-dis[read(0,sz-1,1,f[a]-1,f[b]-1).val]*2;
    }

    for(int k = 0;k < am;k++) for(int i = 0;i < am;i++) for(int j = 0;j < am;j++) 
        if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int i = 0;i < q;i++)
    {
        int xa,xb,ans = INT_MAX;
        cin >> xa >> xb;
        if((xa<(1 << k) and xb<(1 << k)) or (xa>(1 << k) and xb>(1 << k)))
        {
            int a = xa,b = xb;
            if(a>(1 << k)) a-=(1 << k),b-=(1 << k);
            if(f[a]>f[b]) swap(a,b);
            ans = dis[a]+dis[b]-dis[read(0,sz-1,1,f[a]-1,f[b]-1).val]*2;
        }
        for(int j = 0;j < am;j++)
        {
            tmp[j][0] = tmp[j][1] = -1;
            int a = xa,b = xb,c = val[j];
            if((a<(1 << k) and (c<(1 << k))) or (a>(1 << k) and (c>(1 << k))))
            {
                if(a>(1 << k)) a-=(1 << k),c-=(1 << k);
                if(f[a]>f[c]) swap(a,c);
                tmp[j][0] = read(0,sz-1,1,f[a]-1,f[c]-1).val;
            }
            c = val[j];
            if((b<(1 << k) and (c<(1 << k))) or (b>(1 << k) and c>(1 << k)))
            {
                if(b>(1 << k)) b-=(1 << k),c-=(1 << k);
                if(f[b]>f[c]) swap(b,c);
                tmp[j][1] = read(0,sz-1,1,f[b]-1,f[c]-1).val;
            }
        }
        for(int x = 0;x < am;x++) for(int y = 0;y < am;y++)
        {
            if(dist[x][y]>ans) continue;
            int a = xa,b = xb,c = val[x],d = val[y];
            if(a<(1 << k) and c>(1 << k)) continue;
            if(a>(1 << k) and c<(1 << k)) continue;
            if(b<(1 << k) and d>(1 << k)) continue;
            if(b>(1 << k) and d<(1 << k)) continue;
            if(a>(1 << k)) a-=(1 << k),c-=(1 << k);
            if(b>(1 << k)) b-=(1 << k),d-=(1 << k);
            if(f[a]>f[c]) swap(a,c);
            if(f[b]>f[d]) swap(b,d);
            int da = dis[a]+dis[c]-dis[tmp[x][0]]*2;
            int db = dis[b]+dis[d]-dis[tmp[y][1]]*2;
            ans = min(ans,da+db+dist[x][y]);
        }
        cout << ans << '\n';
    }
}
