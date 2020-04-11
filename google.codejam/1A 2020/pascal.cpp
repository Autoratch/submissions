#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n;
    cin >> t;
    for(int c = 1;c <= t;c++)
    {
        cin >> n;
        cout << "Case #" << c << ": \n";
        n--;
        cout << "1 1\n";
        int lst = 2;
        for(int i = 1;;i++)
        {
            if(n>=i) cout << i+1 << ' ' << "2\n",n-=i,lst = i+1;
            else break;
        }
        while(n--) cout << lst << ' ' << "1\n",lst++;
    }
}
