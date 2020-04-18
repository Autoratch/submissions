#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,a[N],l[N],r[N],root;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < N;i++) l[i] = r[i] = -1;

    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        if(!i){ cout << "*\n"; continue; }
        int cur = 0;
        while(true)
        {
            if(a[i]<a[cur])
            {
                cout << 'L';
                if(l[cur]==-1){ l[cur] = i; break; }
                else cur = l[cur];
            }
            else
            {
                cout << 'R';
                if(r[cur]==-1){ r[cur] = i; break; }
                else cur = r[cur];
            }
        }
        cout << "*\n";
    }
}
