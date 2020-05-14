#include <bits/stdc++.h>
using namespace std;

int t,n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n<4) cout << "-1\n";
        else if(n==4) cout << "3 1 4 2\n";
        else
        {
            for(int i = 1;i <= n;i+=2) cout << i << ' ';
            vector<int> ans;
            for(int i = n;i;i--)
            {
                if(i%2==0) ans.push_back(i);
            }
            if(n%2==1) reverse(ans.begin(),ans.begin()+2);
            else reverse(ans.begin(),ans.begin()+3),reverse(ans.begin()+1,ans.begin()+3);
            for(int x : ans) cout << x << ' ';
            cout << '\n';
        }   
    }
}
