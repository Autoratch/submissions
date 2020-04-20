#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
const int MOD = 1e9 + 7;

int n;
int a[N];
vector<int> s;
map<int,int> ma;
long long f[N];
long long ans;
int fw[N];

void update(int idx,int val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

long long read(int idx){ int val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i],s.push_back(a[i]);
    sort(s.begin(),s.end());
    int id = 0;
    for(int x : s) ma[x] = ++id;
    for(int i = 0;i < n;i++) a[i] = ma[a[i]];
    f[0] = 1;
    for(long long i = 1;i <= n;i++) f[i] = (f[i-1]*i)%MOD,update(i,1);
    for(int i = 0;i < n;i++)
    {
        long long each = ((long long)f[n-1-i]*(long long)read(a[i]-1))%MOD;
        ans = (ans+each)%MOD;
        update(a[i],-1);
    }
    cout << (ans+1LL)%MOD;
}
