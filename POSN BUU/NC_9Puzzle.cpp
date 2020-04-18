#include <bits/stdc++.h>
using namespace std;

int t;
string s;
char a[3][3];
queue<pair<string,int> > q;
map<string,bool> visited;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;
        visited.clear();
        while(!q.empty()) q.pop();
        visited[s] = true;
        q.push({s,0});
        while(!q.empty())
        {
            string s = q.front().first;
            int lv = q.front().second;
            q.pop();
            if(s=="123456780"){ cout << lv << '\n'; break; }
            int x,y,cn = 0;
            for(int i = 0;i < 3;i++) for(int j = 0;j < 3;j++)
            {
                a[i][j] = s[cn],cn++;
                if(a[i][j]=='0') x = i,y = j;
            }
            for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
            {
                if(i==0 and j==0) continue;
                if(i!=0 and j!=0) continue;
                int ai = x+i,aj = y+j;
                if(ai<0 or ai>=3 or aj<0 or aj>=3) continue;
                string t = s;
                swap(t[x*3+y],t[ai*3+aj]);
                if(visited[t]) continue;
                visited[t] = true;
                q.push({t,lv+1});
            }
        }
    }
}
