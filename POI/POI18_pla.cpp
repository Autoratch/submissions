#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n;
int a[N],b[N];
bool eq;
vector<pair<int,int> > adj[N];
vector<tuple<int,int,int> > res;
set<int> ss;
unordered_map<int,int> hsh;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 2;i < n;i++) cin >> a[i];
    for(int i = 2;i < n;i++) cin >> b[i];
    for(int i = 2;i < n;i++) ss.insert(abs(a[i]-b[i]));
    if(ss.size()==1)
    {
        if(a[2]==b[2])
        {
            int mn = INT_MAX,id = 0,cnt = 0;
            for(int i = 2;i < n;i++)
            {
                if(a[i]<mn) mn = a[i],id = i,cnt = 1;
                else if(a[i]==mn) cnt++;
            }
            if(cnt>1){ cout << "NIE"; return 0; }
            cout << "TAK\n";
            cout << "1 " << id << ' ' << mn << '\n';
            cout << n << ' ' << id << ' ' << mn << '\n';
            for(int i = 2;i < n;i++)
            {
                if(i==id) continue;
                cout << id << ' ' << i << ' ' << a[i]-mn << '\n';
            }
            return 0;
        }
        cout << "TAK\n";
        cout << "1 " << n << ' ' << *ss.begin() << '\n';
        for(int i = 2;i < n;i++)
        {
            if(a[i]<b[i]) cout << "1 " << i << ' ' << a[i] << '\n';
            else cout << n << ' ' << i << ' ' << b[i] << '\n';
        }
        return 0;
    }
    int mid = INT_MAX;
    for(int i = 2;i < n;i++) mid = min(mid,a[i]+b[i]);
    for(int i = 2;i < n;i++) 
    {
        if(b[i]-a[i]==mid) adj[1].push_back({a[i],i});
        else if(a[i]-b[i]==mid) adj[n].push_back({b[i],i});
        else if(a[i]+b[i]==mid) res.push_back({a[i],b[i],i});
    }
    sort(res.begin(),res.end());
    int lst = 1,lsl = 0;
    for(auto [x,y,id] : res)
    {
        hsh[x] = id;
        adj[lst].push_back({x-lsl,id});
        if(x-lsl==0){ cout << "NIE"; return 0; }
        lst = id,lsl = x;
    }
    adj[lst].push_back({mid-lsl,n});
    for(int i = 2;i < n;i++)
    {
        if(abs(a[i]-b[i])==mid or a[i]+b[i]==mid) continue;
        int tmp = (a[i]+b[i]-mid)/2;
        a[i]-=tmp,b[i]-=tmp;
        if(a[i]+b[i]!=mid){ cout << "NIE"; return 0; }
        int xx = hsh[a[i]];
        if(!xx or b[i]<=0){ cout << "NIE"; return 0; }
        adj[xx].push_back({tmp,i});
    }
    cout << "TAK\n";
    for(int i = 1;i <= n;i++) for(auto [d,v] : adj[i]) cout << i << ' ' << v << ' ' << d << '\n';
}
