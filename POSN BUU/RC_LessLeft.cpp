#include <bits/stdc++.h>
using namespace std;

const int N = 13;

int n,s[N];
bool fi;
int mn = INT_MAX,ans;

void solve(int x,int a,int b,int c)
{
    if(fi) return;
    if(x==n)
    {
        if(a==b)
        {
            if(c<mn) 
            {
                ans = a+c;
                mn = c;
            }   
        }
        return;
    }
    solve(x+1,a+s[x],b,c);
    solve(x+1,a,b+s[x],c);
    solve(x+1,a,b,c+s[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> s[i];

    solve(0,0,0,0);

    cout << ans;
}
