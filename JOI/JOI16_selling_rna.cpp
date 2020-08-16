#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,suf[N],ans[N];
pair<string,int> sx[N];
string s[N],t[N];
tuple<string,string,int> q[N];
tuple<int,int,int,int> qe[N];
int fw[N];

void update(int idx,int val){ if(!idx) return; while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ int val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

string nxt(string s)
{
    s[s.size()-1]++;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> s[i],t[i] = s[i],reverse(t[i].begin(),t[i].end());
    for(int i = 1;i <= m;i++) 
    {
        string a,b;
        cin >> a >> b;
        q[i] = {a,b,i};
    }
    sort(s+1,s+n+1);
    sort(t+1,t+n+1);
    for(int i = 1;i <= n;i++) sx[i] = {s[i],i},reverse(sx[i].first.begin(),sx[i].first.end());
    sort(sx+1,sx+n+1);
    for(int i = 1;i <= n;i++) suf[sx[i].second] = i;
    sort(q+1,q+m+1);
    for(int i = 1;i <= m;i++)
    {
        auto [a,b,x] = q[i];
        auto ix = lower_bound(s+1,s+n+1,a),iy = upper_bound(s+1,s+n+1,nxt(a));
        reverse(b.begin(),b.end());
        auto jx = lower_bound(t+1,t+n+1,b),jy = upper_bound(t+1,t+n+1,nxt(b));
        qe[i] = {ix-s,iy-s,jx-t,jy-t};
    }
//    cout << endl;
  //  for(int i = 1;i <= n;i++) cout << i << ' ' << s[i] << endl;
   // cout << endl;
    //for(int i = 1;i <= n;i++) cout << i << ' ' << t[i] << endl;
    //cout << endl;
    for(int i = 1;i <= m;i++)
    {
        auto [s,t,x] = q[i];
        auto [a,b,c,d] = qe[i];
//        cout << s << ' ' << t << ' ' << x << endl;
//        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }
  //  cout << endl;
    int l = 0,r = 1;
    for(int i = 1;i <= m;i++) 
    {
        auto [a,b,c,d] = qe[i];
    //    cout << l << ' ' << r << endl;
      //  cout << a << ' ' << b << ' ' << c << ' '  << d << endl;
        while(r>=b) update(suf[--r],-1);
        while(r<b) update(suf[r++],1);
        while(l<a) update(suf[l++],-1);
        //for(int j = 1;j <= n;j++) cout << read(j)-read(j-1) << ' ';
        //cout << endl;
        ans[get<2>(q[i])] = read(d-1)-read(c-1);
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';
}
