#include <bits/stdc++.h>
using namespace std;

int n,s,m,x,y;
vector<char> ans,res[3][3];

void p(int x,int y,int m)
{
    if(x==0 and y==0){ while(m--) if(ans.size()) ans.resize(ans.size()-1); return; }
    m--;
    m%=res[x][y].size();
    ans.push_back(res[x][y][m]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s >> m;

    x = (s-1)/3,y = (s-1)%3;
    
    res[0][1] = {'A','B','C'},res[0][2] = {'D','E','F'};
    res[1][0] = {'G','H','I'},res[1][1] = {'J','K','L'},res[1][2] = {'M','N','O'};
    res[2][0] = {'P','Q','R','S'},res[2][1] = {'T','U','V'},res[2][2] = {'W','X','Y','Z'};

    p(x,y,m);

    for(int i = 0;i < n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        swap(a,b);
        x+=a,y+=b;
        p(x,y,c);
    }

    for(char c : ans) cout << c;
    if(ans.size()==0) cout << "null";
}
