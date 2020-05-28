#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n;
vector<pair<int,int> > adj[N];
int a[N][4];

void dfs(int u,int p)
{
    a[u][1] = -1e9;
    a[u][3] = -1e9;
    int m3 = -1e9,m21 = -1e9,m22 = -1e9,m01 = -1e9,m02 = -1e9,dis = -1e9,v2,v0;
    for(auto [d,v] : adj[u]) if(v!=p)
    {
        dfs(v,u); 
        int each = a[v][0],ez = a[v][1]+d;
        a[u][0]+=max(each,ez);
 
        a[u][1] = max(a[u][1],a[v][0]+d-max(each,ez));
        
        m3 = max(m3,a[v][3]+d-max(each,ez));
        
        dis = max(dis,a[v][2]-max(each,ez));

        if(a[v][2]+d-max(each,ez)>m21) m22 = m21,m21 = a[v][2]+d-max(each,ez),v2 = v;
        else if(a[v][2]+d-max(each,ez)>m22) m22 = a[v][2]+d-max(each,ez);

        if(a[v][0]+d-max(each,ez)>m01) m02 = m01,m01 = a[v][0]+d-max(each,ez),v0 = v;
        else if(a[v][0]+d-max(each,ez)>m02) m02 = a[v][0]+d-max(each,ez);

        a[u][3] = max(a[u][3],a[v][2]+d-max(each,ez));
    }
    a[u][1]+=a[u][0];
    a[u][3]+=a[u][0];
    if(m01!=-1e9 and m02!=-1e9) a[u][2] = max(a[u][2],m01+m02);
    if(m01!=-1e9 and m21!=-1e9 and v2!=v0) a[u][2] = max(a[u][2],m01+m21);
    if(m02!=-1e9 and m21!=-1e9) a[u][2] = max(a[u][2],m02+m21);
    if(m01!=-1e9 and m22!=-1e9) a[u][2] = max(a[u][2],m01+m22);
    a[u][2] = max(a[u][2],m3);
    a[u][2] = max(a[u][2],dis);
    a[u][2]+=a[u][0];
    
/*
    if(u==1)
    {
        cout << m01 << ' ' << m02 << ' ' << m21 << ' ' << m22 << endl;
    }
    
    cout << u << endl;
    for(int i = 0;i < 4;i++) cout << a[u][i] << ' ';
    cout << endl;
*/
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n-1;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    dfs(1,0);
    cout << max(a[1][0],a[1][2]);
}
