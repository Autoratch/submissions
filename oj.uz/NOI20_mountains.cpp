#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 3;

int n;
long long a[N];
vector<long long> s;
map<long long,int> ma;
long long fa[N],fb[N];
long long ans;

void update(long long (&a)[N],int idx,long long val){ idx++; while(idx<N) a[idx]+=val,idx+=(idx & -idx); }

long long read(long long (&a)[N],int idx){ idx++; long long val = 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i],s.push_back(a[i]);
    sort(s.begin(),s.end());
    int id = 0;
    for(long long x : s) if(!ma[x]) ma[x] = ++id;
    for(int i = 1;i <= n;i++) a[i] = ma[a[i]];
    for(int i = 1;i <= n;i++)
    {
        ans+=read(fb,N-2)-read(fb,a[i]);
        update(fb,a[i],read(fa,a[i]-1));
        update(fa,a[i],1);
    }
    cout << ans;
}
