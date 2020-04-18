#include <bits/stdc++.h>
using namespace std;

const int N = 21;

int n;
long long w,c[N];

long long solve(int n,long long w)
{
    if(n==1) return w;
    w = (w*2-c[n-1]);
    w++;
    if(w%2==1) return solve(n-1,w/2)+solve(n-1,w/2+1);
    else return solve(n-1,w/2)+solve(n-1,w/2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w;

    for(int i = 1;i < n;i++) cin >> c[i];

    long long res = solve(n,w);
    
    if(res<0) res = -1;
    cout << res;
}
