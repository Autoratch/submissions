#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int K = 18;

int n,k,cnt,s;
int tree[N][2],am[N][2];
set<int> st;

void update(int x)
{
    int now = 0;
    for(int i = K;i >= 0;i--)
    {
        int y = (1 << i)&x; if(y) y = 1;
        am[now][y]++;
        if(tree[now][y]) now = tree[now][y];
        else now = tree[now][y] = ++cnt;
    }
}

int query(int x)
{
    int now = 0,cur = 0;
    for(int i = K;i >= 0;i--)
    {
        int y = (1 << i)&x; if(y) y = 1;
        if(now==-1){ cur+=(1 << i)*y; continue; }
        if(am[now][y]==0){ now = -1,cur+=(1 << i)*y; continue; }
        if(am[now][y]<(1 << i)) now = tree[now][y],cur+=(1 << i)*y;
        else if(tree[now][y^1]==0) now = -1,cur+=(1 << i)*(int)(y^1);
        else now = tree[now][y^1],cur+=(1 << i)*(int)(y^1);
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 0;i < n;i++){ int x; cin >> x; if(st.find(x)==st.end()) st.insert(x),update(x); }
    while(k--)
    {
        int x;
        cin >> x;
        s^=x;
        cout << (query(s)^s) << '\n';
    }
}
