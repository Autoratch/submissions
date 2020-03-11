#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int n,a[N];
bool visited[N][N];
int cmb[N][N],am[N][N];

void solve(int l,int r)
{
    if(visited[l][r]) return;
    visited[l][r] = true;
    if(l==r){ cmb[l][r] = a[l],am[l][r] = 1; return; }
    am[l][r] = INT_MAX;
    for(int i = l;i < r;i++)
    {
        solve(l,i),solve(i+1,r);
        if(cmb[l][i] and cmb[l][i]==cmb[i+1][r]) cmb[l][r] = cmb[l][i]+1,am[l][r] = 1;
        else if(am[l][i]+am[i+1][r]<am[l][r]) am[l][r] = am[l][i]+am[i+1][r];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    solve(1,n);
    cout << am[1][n];
}
