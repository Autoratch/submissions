#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int t;
string x,y;
vector<int> a[26];
int cur[26];
int s[N];
long long ans;

void update(int idx,int val){ while(idx<N){ s[idx]+=val; idx+=(idx & -idx); } }

int read(int idx){ int val = 0; while(idx>0){ val+=s[idx]; idx-=(idx & -idx); } return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> x >> y;

    for(int i = 0;i < x.length();i++) a[x[i]-'a'].push_back(i),update(i+1,1);

    for(char c : y)
    {
        if(cur[c-'a']>=a[c-'a'].size()){ cout << "-1"; return 0; }
        ans+=read(a[c-'a'][cur[c-'a']]+1);
        if(t) update(a[c-'a'][cur[c-'a']]+1,-1);
        cur[c-'a']++;
    }

    cout << ans;
}
