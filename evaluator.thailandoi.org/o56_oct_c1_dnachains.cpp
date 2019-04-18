#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

struct node
{
    bool is = false;
    int nx[2] = {0,0};
}a[N];

int n,m,sum;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    int idx = 1;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        for(int j = 0;j < x;j++)
        {
            if(j>0) a[idx].nx[0] = idx-1;
            if(j<x-1) a[idx].nx[1] = idx+1;
            idx++;
        }
    }
    sum = idx-1;

    a[0].is = true;
    int cur = 1;
    while(m--)
    {
        char c;
        cin >> c;
        if(c=='B') 
        {
            bool nxt = !a[a[cur].nx[0]].is;
            if(a[cur].nx[nxt]==0){ cout << cur << '\n'; continue; }
            int pr = cur;
            cur = a[cur].nx[nxt];
            a[cur].is = false;
            if(pr!=a[cur].nx[nxt]) a[a[cur].nx[nxt]].is = true;
            else a[a[cur].nx[!nxt]].is = true;
            cout << cur << '\n';
        }
        else if(c=='F')
        {
            bool nxt = a[a[cur].nx[0]].is;
            if(a[cur].nx[nxt]==0){ cout << cur << '\n'; continue; }
            a[a[cur].nx[!nxt]].is = false;
            a[cur].is = true;
            cur = a[cur].nx[nxt];
            cout << cur << '\n';
        }
        else
        {
            int x;
            cin >> x;
            bool nxt;
            if(a[a[cur].nx[0]].is) nxt = true;
            else nxt = false;
            if(cur==a[a[cur].nx[nxt]].nx[0]) a[a[cur].nx[nxt]].nx[0] = 0;
            else a[a[cur].nx[nxt]].nx[1] = 0;
            a[cur].nx[nxt] = x;
            if(a[x].nx[0]==0) a[x].nx[0] = cur;
            else a[x].nx[1] = cur;
            a[a[cur].nx[!nxt]].is = false;
            a[cur].is = true;
            cur = a[cur].nx[nxt];
            cout << cur << '\n';
        }
    }
}
