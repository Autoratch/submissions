#include <bits/stdc++.h>
using namespace std;

int tc,n,m;
vector<bool> t;
vector<vector<string> > a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> tc;

    while(tc--)
    {
        cin >> n >> m;
        a.clear(),b.clear();
        a.resize(n),b.resize(m);
        for(int i = 0;i < n;i++) 
        {
            int x;
            cin >> x;
            while(x--){ string s; cin >> s; a[i].push_back(s); }
        }
        for(int i = 0;i < m;i++)
        {
            int x;
            cin >> x;
            while(x--){ string s; cin >> s; b[i].push_back(s); }
        }
        bool all = true;
        for(int i = 0;i < (1 << 16);i++)
        {
            int tmp = i,cnt = 0;
            t.assign(16,false);
            while(tmp)
            {
                t[cnt] = tmp%2;
                tmp/=2; cnt++;
            }
            bool af = true,bf = true;
            for(int j = 0;j < n;j++)
            {
                bool e = false;
                for(string s : a[j])
                {
                    int tmp = s[1]-'a';
                    bool tm = t[tmp];
                    if(s[0]=='-') tm = !tm;
                    e|=tm;
                    if(e) break;
                }
                af = af and e;
                if(!e) break;
            }
            if(!af) continue;
            for(int j = 0;j < m;j++)
            {
                bool e = false;
                for(string s : b[j])
                {
                    int tmp = s[1]-'a';
                    bool tm = t[tmp];
                    if(s[0]=='-') tm = !tm;
                    e|=tm;
                    if(e) break;
                }
                bf = bf and e;
                if(!e) break;
            }
            if(af and !bf) all = false;
        }
        if(all) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}
