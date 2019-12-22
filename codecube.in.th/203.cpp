#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

string s;
int cnt[N];
queue<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i]=='2') cnt[i] = cnt[i+1] = 1,q.push({i,1}),q.push({i+1,1});
        else if(s[i]=='0') cnt[i] = cnt[i+1] = -1,q.push({i,-1}),q.push({i+1,-1});
        else if(s[i]=='1' and i==0) cnt[i+1] = 1,q.push({i+1,1});
        else if(s[i]=='1' and i==s.length()-1) cnt[i] = 1,q.push({i,1});
    }
    while(!q.empty())
    {
        int p = q.front().first,x = q.front().second;
        q.pop();
        if(p>0 and cnt[p-1]==0 and s[p-1]!='?' and s[p-1]=='1')
        {
            q.push({p-1,-x});
            cnt[p-1] = -x;
        }
        if(p<s.length()-1 and cnt[p+1]==0 and s[p]!='?' and s[p]=='1') 
        {
            q.push({p+1,-x});
            cnt[p+1] = -x;
        }
    }
    for(int i = 0;i < s.length();i++) if(s[i]=='1' and cnt[i]==0) 
    {
        q.push({i,1});
        cnt[i] = 1;
        while(!q.empty())
        {
            int p = q.front().first,x = q.front().second;
            q.pop();
            if(p>0 and cnt[p-1]==0 and s[p-1]!='?' and s[p-1]=='1')
            {
                q.push({p-1,-x});
                cnt[p-1] = -x;
            }
            if(p<s.length()-1 and cnt[p+1]==0 and s[p]!='?' and s[p]=='1') 
            {
                q.push({p+1,-x});
                cnt[p+1] = -x;
            }
        }
    }
    for(int i = 1;i < s.length();i++) 
    {
        cout << 'x';
        if(cnt[i]==1) cout << '-';
        else cout << '.';
    }
    cout << 'x';
}
