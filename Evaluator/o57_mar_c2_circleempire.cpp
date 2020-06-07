#include <bits/stdc++.h>
using namespace std;

const int L = 52;
const int K = 201;

int n,m,k,l,q;
int dist[L][L][K],jump[K][K]; 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> l >> m >> q,n = k*l; 
    for(int i = 0;i <= l;i++) for(int j = 0;j <= l;j++) for(int l = 1;l <= k;l++) if(i!=j) dist[i][j][l] = INT_MAX;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        if(a>b) swap(a,b);
        a--,b--;
        int ta = a/l+1,tb = b/l+1;
        a%=l,b%=l;
        a++,b++;
        if(ta==tb) dist[a][b][ta] = dist[b][a][ta] = d;
        else
        {
            if(ta+1==tb and a==l) dist[0][b][tb] = dist[b][0][tb] = d;
            else if(tb==k and b==l) dist[0][a][ta] = dist[a][0][ta] = d;
        }
    }
    for(int t = 1;t <= k;t++) 
        for(int k = 0;k <= l;k++) for(int i = 0;i <= l;i++) for(int j = 0;j <= l;j++) 
            if(dist[i][k][t]!=INT_MAX and dist[k][j][t]!=INT_MAX) dist[i][j][t] = min(dist[i][j][t],dist[i][k][t]+dist[k][j][t]);
    for(int i = 1;i <= k;i++) for(int j = 1;j <= k;j++) if(i!=j) jump[i][j] = INT_MAX;
    for(int i = 1;i <= k;i++) 
    {
        if(i==1) jump[i][k] = jump[k][i] = dist[0][l][i];
        else jump[i][i-1] = jump[i-1][i] = dist[0][l][i];
    }
    for(int t = 1;t <= k;t++) for(int i = 1;i <= k;i++) for(int j = 1;j <= k;j++) 
        if(jump[i][t]!=INT_MAX and jump[t][j]!=INT_MAX) jump[i][j] = min(jump[i][j],jump[i][t]+jump[t][j]);
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        int ans = INT_MAX;
        int ta = a/l+1,tb = b/l+1;
        a%=l,b%=l;
        a++,b++;
        if(ta==tb) ans = min(ans,dist[a][b][ta]);
        int sa = ta-1;
        if(sa<1) sa = k;
        int sb = tb-1;
        if(sb<1) sb = k;
        if(jump[sa][tb]!=INT_MAX and dist[0][a][ta]!=INT_MAX and dist[l][b][tb]!=INT_MAX)
            ans = min(ans,dist[0][a][ta]+jump[sa][tb]+dist[l][b][tb]);
        if(jump[ta][tb]!=INT_MAX and dist[l][a][ta]!=INT_MAX and dist[l][b][tb]!=INT_MAX)
            ans = min(ans,dist[l][a][ta]+jump[ta][tb]+dist[l][b][tb]);
        if(jump[sa][sb]!=INT_MAX and dist[0][a][ta]!=INT_MAX and dist[0][b][tb]!=INT_MAX)
            ans = min(ans,dist[0][a][ta]+jump[sa][sb]+dist[0][b][tb]);
        if(jump[ta][sb]!=INT_MAX and dist[l][a][ta]!=INT_MAX and dist[0][b][tb]!=INT_MAX)
            ans = min(ans,dist[l][a][ta]+jump[ta][sb]+dist[0][b][tb]);
        cout << ans << '\n';
    }
}
