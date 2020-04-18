#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    for(int i = 0;i < m;i++) s+='U';
    for(int i = 0;i < n;i++) s+='L';
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n-1;j++) if(i%2==0) s+='R'; else s+='L';
        if(i<m-1) s+='D';
    }
    cout << s.length() << '\n' << s;
}
