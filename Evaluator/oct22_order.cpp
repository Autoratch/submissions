#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

int n,root;
int a[N],b[N];
int l[N],r[N];
unordered_map<int,int> iv,vi;

bool check(int al,int ar,int bl,int br)
{
    if(a[al]!=b[br]) return false;
    else return true;
}

void solve(int al,int ar,int bl,int br)
{
    if(al==ar) return;
    int rt = vi[a[al]];
    al++;
    br--;
    bool f = false;
    for(int i = al,j = bl;i < ar;i++,j++)
    {
        if(!check(al,i,bl,j)) continue;
        f = true;
        l[rt] = vi[a[al]];
        r[rt] = vi[a[i+1]];
        solve(al,i,bl,j);
        solve(i+1,ar,j+1,br);
        break;
    }
    if(!f)
    {
        l[rt] = vi[a[al]];
        solve(al,ar,bl,br);
    }
}

void post(int x)
{
    if(l[x]!=-1) post(l[x]);
    cout << iv[x] << '\n';
    if(r[x]!=-1) post(r[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++){ cin >> a[i]; iv[i] = a[i]; vi[a[i]] = i; }
    for(int i = 0;i < n;i++) cin >> b[i];
    for(int i = 0;i < n;i++) l[i] = r[i] = -1;

    solve(0,n-1,0,n-1);
    post(root);
}
