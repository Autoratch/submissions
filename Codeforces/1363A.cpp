#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        int e = 0,o = 0,s = 0;
        int l = 0,r = 0;
        for(int i = 0;i < n;i++)
        {
            int a;
            cin >> a;
            if(i<x){

            if(a%2==1) o++;
            else e++;
            }
            else
            {
                if(a%2==1) l++;
                else r++;
            }
            if(i<x) s+=a;
        }
        if(s%2==1){ cout << "Yes\n"; continue; }
        if(e>0 and o>0 and x<n){ cout << "Yes\n"; continue; }
        if(e>0 and l>0){ cout << "Yes\n"; continue; }
        if(o>0 and r>0){ cout << "Yes\n"; continue; }
        cout << "No\n"; 
    }
}
