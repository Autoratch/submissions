#include <bits/stdc++.h>
using namespace std;

long long m,n,q,ul,ur,ll,lr;
long long ax,ay,bx,by;

long long ask(long long x,long long y)
{ 
    if(x<1 or x>m or y<1 or y>n) return 1;
    cout << "? " << x << ' ' << y << endl; long long ret; cin >> ret; return ret;
}
    
//long long ask(long long x,long long y)
//{  
//    if(x<1 or x>m or y<1 or y>n) return 1;
//    return min(abs(x-ax)+abs(y-ay),abs(x-bx)+abs(y-by)); 
//}
//
int main()
{
//    cin >> ax >> ay >> bx >> by;
    cin >> m >> n >> q;
    ul = ask(1,1),ur = ask(1,n),ll = ask(m,1),lr = ask(m,n);
    long long b = (ul+ll-(m-1))/2,a = ul-b;
    long long e = (ur+lr-(m-1))/2,d = ur-e; e = (n-1-e);
    if(ask(a+1,b+1)==0 and (ul+ll-m+1)%2==0 and (ur+lr-m+1)%2==0)
    {
        cout << "! " << a+1 << ' ' << b+1 << ' ' << d+1 << ' ' << e+1 << endl;
    }
    else
    {
        b = (ul+ur-(n-1))/2,a = ul-b;
        e = (ll+lr-(n-1))/2,d = ll-e; e = (m-1-e);
        cout << "! " << b+1 << ' ' << a+1 << ' ' << e+1 << ' ' << d+1 << endl;
    }
}
