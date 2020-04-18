#include <bits/stdc++.h>
using namespace std;

int n,k;
string s;
queue<int> q;
set<int> st;
vector<vector<int> > ans;
vector<int> tmp;
int all;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> s;
    s = " "+s;
    for(int i = 1;i < n;i++) if(s[i]=='R' and s[i+1]=='L') q.push(i);
    while(!q.empty())
    {
        tmp.clear();
        st.clear();
        while(!q.empty()) 
        {
            int x = q.front(); q.pop();
            tmp.push_back(x);
            all++;
            swap(s[x],s[x+1]);
        }
        for(int x : tmp)
        {
            if(x>1 and s[x-1]=='R' and s[x]=='L') st.insert(x-1);
            if(x<n-1 and s[x+1]=='R' and s[x+2]=='L') st.insert(x+1);
        }
        for(int x : st) q.push(x);
        ans.push_back(tmp);
    }
    if(all<k){ cout << "-1"; return 0; }
    if(ans.size()>k){ cout << "-1"; return 0; }
    if(ans.size()<k)
    {
        int now = ans.size(),lst = -1;
        for(int i = 0;i < ans.size();i++)
        {
            lst = i;
            if(now+ans[i].size()-1>=k)
            {
                for(int j = 0;j < k-now;j++) cout << "1 " << ans[i][j] << '\n';
                cout << ans[i].size()-(k-now) << ' ';
                for(int j = k-now;j < ans[i].size();j++) cout << ans[i][j] << ' ';
                cout << '\n';
                break;
            }
            else
            {
                for(int j = 0;j < ans[i].size();j++) cout << "1 " << ans[i][j] << '\n';
                now+=ans[i].size()-1;
            }
        }
        for(int i = lst+1;i < ans.size();i++) 
        {
            cout << ans[i].size() << ' ';
            for(int x : ans[i]) cout << x << ' ';
            cout << '\n';
        }
        return 0;
    }
    for(int i = 0;i < ans.size();i++)
    {
        cout << ans[i].size() << ' ';
        for(int x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
}
