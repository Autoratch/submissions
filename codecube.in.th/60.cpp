#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N],s[N],l,r,mn,idmn,mx,idmx,now,idno;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        char c;
        cin >> c >> a[i];
        if(c=='R') a[i] = -a[i],r-=a[i];
        else l+=a[i];
        s[i] = s[i-1]+a[i];
    }
    mn = 0,idmn = 0,now = 0,idno = 0;
    mx = INT_MIN;
    for(int i = 1;i <= n;i++) 
    {
        if(s[i]-mn>mx) mx = s[i]-mn,idmx = i,idno = idmn,now = mn;
        if(s[i]<=mn) mn = s[i],idmn = i;
    }
    int amx = mx,al = idno+1,ar = idmx;
    for(int i = 1;i <= n;i++) a[i] = -a[i],s[i] = s[i-1]+a[i];
    mn = 0,idmn = 0,now = 0,idno = 0;
    mx = INT_MIN;
    for(int i = 1;i <= n;i++) 
    {
        if(s[i]-mn>mx) mx = s[i]-mn,idmx = i,idno = idmn,now = mn;
        if(s[i]<=mn) mn = s[i],idmn = i;
    }
    int bmx = mx,bl = idno+1,br = idmx;
    amx+=r,bmx+=l;
    if(bmx>amx) cout << "L " << bmx << ' ' << bl << ' ' << br;
    else cout << "R " << amx << ' ' << al << ' ' << ar; 
}