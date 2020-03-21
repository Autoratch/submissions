#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;
const int K = 21;

int n,q,fw[K][N];
vector<int> tmp,inp[K];
pair<int,int> qu[N];
unordered_map<int,int> hsh;
priority_queue<int,vector<int>,greater<int> > pq[K];

void update(int (&a)[N],int idx,int val){ while(idx<N) a[idx]+=val,idx+=(idx & -idx); }

int read(int (&a)[N],int idx){ int val = 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        int a;
        cin >> a;
        while(a--){ int x; cin >> x; inp[i].push_back(x); tmp.push_back(x); }
    }
    for(int i = 0;i < q;i++){ int x,y; cin >> x >> y; qu[i] = {x,y}; tmp.push_back(y); }
    sort(tmp.begin(),tmp.end());
    int id = 0;
    for(int x : tmp) hsh[x] = ++id;
    for(int i = 1;i <= n;i++) for(int x : inp[i]) update(fw[i],hsh[x],1),pq[i].push(hsh[x]);
    for(int i = 0;i < q;i++)
    {
        int x,y;
        x = qu[i].first,y = qu[i].second;
        if(x==0)
        {
            if(!pq[y].empty())
            {
                int tmp = pq[y].top(); pq[y].pop();
                update(fw[y],tmp,-1);
            }
        }
        else
        {
            y = hsh[y];
            int mn = INT_MAX,id;
            for(int j = 1;j <= n;j++)
            {
                if(read(fw[j],y)<mn) mn = read(fw[j],y),id = j;
            }
            pq[id].push(y);
            cout << id << '\n';
            update(fw[id],y,1);
        }

    }
}
