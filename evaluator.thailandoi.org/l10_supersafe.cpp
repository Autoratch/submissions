#include <bits/stdc++.h>
using namespace std;

int n,k,pt,pv,ct,cv;

bool solve(int x)
{
    if(((ct-pt)*pv*x/(x-pv))>=k) return true;
    else return false;
}

int main()
{
    cin >> n >> k;

    for(int i = 0;i < n;i++)
    {
        cin >> ct >> cv;
        if(i==0 or cv<=pv){ pv = cv; pt = ct; cout << "0\n"; continue; }
        int l = pv,r = cv;
        while(l<r)
        {
            int m = (l+r)/2;
            bool ok = solve(m);
            cout << l << ' ' << r << ' ' << m << ' ' << ok << endl;
            if(ok)
            {
                if(m==r){ l = r; break; }
                if(solve(m+1)) l = m+1;
                else{ l = m; break; }
            }
            else r = m-1;
        }
        cout << cv-l << '\n';
        pt = ct;
        pv = l;
   }
}
