#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct node{ int t,a,b; };
node in[N];
int n,q,s[N];
set<int> se;
vector<int> v;

void update(int idx,int val){ while(idx<N) s[idx]+=val,idx+=(idx & -idx); }
int read(int idx){ int val = 0; while(idx>0) val+=s[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 0;i < q;i++)
    {
        int t,a,b = 1;
        cin >> t >> a;
        if(t){ cin >> b; in[i] = {t,a,b}; }
        else in[i] = {t,a};
        se.insert(a);
        se.insert(b);
    }
    se.insert(n);

    for(int x : se) v.push_back(x);

    for(int i = 0;i < q;i++)
    {
        int t = in[i].t,a = in[i].a,b = in[i].b;
        if(t==1) 
        {
            update(lower_bound(v.begin(),v.end(),a)-v.begin()+1,1);
            update(upper_bound(v.begin(),v.end(),b)-v.begin()+1,-1);
        }
        else 
        {
            int x = read(lower_bound(v.begin(),v.end(),a)-v.begin()+1);
            x%=6;
            if(x==0) cout << "sleep";
            else if(x==2 or x==4) cout << "work";
            else cout << "eat";
            cout << '\n';
        }
    }
}
