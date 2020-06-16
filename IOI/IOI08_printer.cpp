#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n;
string s[N],ans;
int tree[N][26],mxch[N],mxs[N];
int cur[N],cnt;
vector<string> ls;

void add(string s)
{
    int now = 0;
    for(char c : s) 
    {
        if(s.length()>mxs[now]) mxs[now] = s.length(),mxch[now] = c-'a';
        if(tree[now][c-'a']) now = tree[now][c-'a'];
        else tree[now][c-'a'] = ++cnt,now = cnt;
    }
    cur[now]++;
}

void solve(int now,string cu)
{
    while(cur[now]--) ls.push_back(cu);
    for(int i = 0;i < 26;i++) if(tree[now][i])
    {
        if(mxs[now] and mxch[now]==i) continue;
        solve(tree[now][i],cu+(char)(i+'a'));
    }
    if(mxs[now]) solve(tree[now][mxch[now]],cu+(char)(mxch[now]+'a'));
}

void ch(string a,string b)
{
    int sm = 0;
    for(int i = 0,j = 0;i < a.length() and j < b.length() and a[i]==b[j];i++,j++) sm++;
    for(int i = 0;i < a.length()-sm;i++) ans+='-';
    for(int i = sm;i < b.length();i++) ans+=b[i];
    ans+='P';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> s[i],add(s[i]);
    solve(0,"");
    for(int i = 0;i < ls.size();i++)
    {
        string a = "",b = ls[i];
        if(i) a = ls[i-1];
        ch(a,b);
    }
    cout << ans.length() << '\n';
    for(char c : ans) cout << c << '\n';
}
