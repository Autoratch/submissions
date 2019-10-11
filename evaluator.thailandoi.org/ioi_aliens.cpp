//#include "alienslib.cpp"
#include <bits/stdc++.h>
#include "alienslib.h"
using namespace std;
 
long long n,x,y,ox,oy,l,r,up,lo,sz;
 
bool check(long long x,long long y)
{
//    cout << "examine " << x << ' ' << y; cout << flush;
if(x<1 or x>n or y<1 or y>n) return false;
    return examine((int)x,(int)y);
    string s; cin >> s;
    return s=="true";
}
 
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0);
 
//    cin >> n >> x >> y;
//   
int a,b,c;
get_size_and_start(a,b,c);
n = a,x = b,y = c;
//cout << check(x,y) << endl;
//  return 0;
    ox = x,oy = y;
    l = x,r = n;
 //   return 0;
    for(long long i = 1LL;x+i <= n;i*=2LL)
    {
        if(!check(x+i,y)){ r = x+i; break; }
        else if(!check(x+i+1LL,y)){ r = x+i+1LL; break; }
        else l = x+i;
        x+=i;
    }
//return 0;
    while(l<r)
    {
        long long m = (l+r)/2LL;
        if(check(m,y))
        { 
            if(!check(m+1LL,y)){ l = m; break; } 
            else l = m+1LL; 
        }
        else r = m;
    }
//return 0;
    //  return 0;
//cout << "still ok";
//cout.flush();
//cout << l;
    up = l;
    x = ox,y = oy;
    l = 1LL,r = x;
    for(long long i = 1LL;x-i >= 1LL;i*=2LL)
    {
//        cout << x << ' ' << x-i << endl;
        if(!check(x-i,y)){ l = x-i; break; }
        else if(!check(x-i-1LL,y)){ l = x-i-1LL; break; }
        else r = x-i;
        x-=i;
    }
    while(l<r)
    {
        long long m = (l+r)/2LL;
  //      cout << l << ' ' << m << ' ' << r << endl;
    //    cout << check(m,y) << endl;
        if(check(m,y))
        {
            if(!check(m-1LL,y)){ l = m; break; }
            else r = m;
        }
        else l = m+1LL;
    }
   // cout << r << endl;
//   cout << lo << ' ' << up << ' ' << sz << endl;
    lo = l,sz = up-lo+1LL;
 //   cout << lo << ' ' << up << ' ' << sz << endl;
    x = ox,y = oy;
    while(check(x-sz,y-sz)) x-=sz,y-=sz;
    while(check(x-sz*2LL,y)) x-=sz*2LL;
    while(check(x,y-sz*2LL)) y-=sz*2LL;
    l = x-sz,r = x;
    while(l<r)
    {
        long long m = (l+r)/2LL;
        if(check(m,y))
        {
            if(!check(m-1LL,y)){ l = m; break; }
            else r = m;
        }
        else l = m+1LL;
    }
//return 0;
    x = l;
    l = y-sz,r = y;
    while(l<r)
    {
        long long m = (l+r)/2LL;
        if(check(x,m))
        {
            if(!check(x,m-1LL)){ l = m; break; }
            else r = m;
        }
        else l = m+1LL;
    }
    y = l;
  //  cout << x+sz*2+sz/2 << ' ' << y+sz*2+sz/2;
//cout << flush;

    solution(x+sz*2+sz/2,y+sz*2+sz/2);
}
