#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int q;
string s;
int a[26][N];

void update(int idx,int val,int *a){ idx++; while(idx<N) a[idx]+=val,idx+=(idx & -idx); }

int read(int idx,int *a){ idx++; int val = 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> q;

    for(int i = 0;i < s.length();i++) update(i,1,a[s[i]-'a']);

    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x;
            char c;
            cin >> x >> c;
            x--;
            update(x,-1,a[s[x]-'a']);
            s[x] = c;
            update(x,1,a[s[x]-'a']);
        }
        else    
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            int ans = 0;
            for(int i = 0;i < 26;i++)
            {
                bool x = read(r,a[i])-read(l-1,a[i]);
                ans+=x;
            }
            cout << ans << '\n';
        }
    }
}
