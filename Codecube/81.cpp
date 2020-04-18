#include <bits/stdc++.h>
using namespace std;
#define p pair<int,string>

int n;
priority_queue<p,vector<p>,greater<p> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    q.push({1,"0"});
    q.push({1,"1"});
    q.push({1,"8"});
    q.push({2,"00"});
    q.push({2,"11"});
    q.push({2,"69"});
    q.push({2,"88"});
    q.push({2,"96"});

    while(!q.empty())
    {
        string x = q.top().second;
        q.pop();
        if(!(x!="0" and x[0]=='0'))
        {
            n--;
            if(n==0){ cout << x; return 0; }
        }
        q.push({x.length()+2,"0"+x+"0"});
        q.push({x.length()+2,"1"+x+"1"});
        q.push({x.length()+2,"6"+x+"9"});
        q.push({x.length()+2,"8"+x+"8"});
        q.push({x.length()+2,"9"+x+"6"});
    }
}
