#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n;
map<pair<int,int>,vector<string> > sres;
vector<string> sre[N];
vector<string> sr,sl;

bool v(char c){ return c=='a' or c=='e' or c=='i' or c=='o' or c=='u'; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for(int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        int am = 0;
        char lst;
        for(char c : s) if(v(c)) am++,lst = c;
//        res[am][lst-'a']++;
        sres[{am,lst-'a'}].push_back(s);
  //      re[am]++;
        sre[am].push_back(s);
    }

    int r = 0,l = 0;

    vector<string> st;

    for(int i = 1;i < N;i++) if(sre[i].size()>0)
    { 
        int x = 0;
        int re = sre[i].size();
        for(int j = 0;j < 26;j++)
        { 
            int res = sres[{i,j}].size();
            r+=res/2;
            int cn = 0;
            for(string s : sres[{i,j}]){ if(cn>=(res/2)*2) break; sr.push_back(s); cn++; }
            x+=res; 
            if(res%2==1) st.push_back(sres[{i,j}][res-1]);
            if(res%2==1) x--; 
        }
        l+=(re-x)/2; 
        for(int j = 0;j < ((re-x)/2)*2;j++) sl.push_back(st[j]);
        st.resize(0);
    }
    
//cout << l << ' ' << r << endl;

    int il = 0,ir = 0;

    while(l<r) l++,r--;

    cout << min(l,r) << '\n';
/*
for(string s : sl) cout << s << ' ';
cout << endl;
for(string s : sr) cout << s << ' ';
cout << endl;
*/
    for(int i = 0;i < min(l,r);i++)
    {
        if(il>=sl.size()) sl.push_back(sr[ir++]),sl.push_back(sr[ir++]);
        cout << sl[il] << ' ' << sr[ir] << '\n';
        il++,ir++;
        cout << sl[il] << ' ' << sr[ir] << '\n';
        il++,ir++;
    }
}

