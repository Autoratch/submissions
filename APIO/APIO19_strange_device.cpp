#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int n;
long long a,b;
map<long long,int> ma;
set<long long> s;
int res[N];
vector<pair<long long,long long> > in;
long long rng[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b;
    a/=__gcd(a,b+1);
    if(a>1e18/b) a = (1e18+2),b = 1;
    for(int i = 0;i < n;i++)
    {
        long long x,y;
        cin >> x >> y; 
        if(y-x+1LL>=a*b){ cout << a*b; return 0; }
        y++;
        x%=(a*b),y%=(a*b); 
        if(y<x) in.push_back({0LL,y}),in.push_back({x,a*b});
        else in.push_back({x,y});
        s.insert(x),s.insert(y);
    }
    s.insert(0),s.insert(a*b);
    long long prev = 0;
    int id = 0;
    for(auto x : s) ma[x] = ++id,rng[id-1] = x-prev,prev = x;
    for(auto x : in) res[ma[x.first]]++,res[ma[x.second]]--;
    for(int i = 1;i < N;i++) res[i]+=res[i-1];
    for(int i = 1;i < N;i++) if(res[i]) ans+=rng[i];
    cout << ans;
}
