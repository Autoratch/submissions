#include <bits/stdc++.h>
using namespace std;

int t,x,y,z,m,n;

struct data
{
    int a,b,c,d; // sq6 sq3 sq2 1
    friend data operator+(const data &a,const data &b)
    {
        data ret;
        int p = a.a,q = a.b,r = a.c,s = a.d;
        int i = b.a,j = b.b,k = b.c,l = b.d;
        ret.a = s*i+r*j+q*k+p*l;
        ret.b = 2*r*i+s*j+2*p*k+q*l;
        ret.c = 3*q*i+3*p*j+s*k+r*l;
        ret.d = 6*p*i+3*q*j+2*r*k+s*l;
        ret.a%=m,ret.b%=m,ret.c%=m,ret.d%=m;
        return ret;
    }
};

data res;

data solve(int n)
{
    if(n==0) 
    {
        data ret;
        ret.a = ret.b = ret.c = 0;
        ret.d = 1;
        return ret;
    }
    else if(n==1) return res;
    data tmp = solve(n/2);
    if(n%2==0) return tmp+tmp;
    else return (tmp+tmp)+solve(1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> y >> z >> n >> m;
        x%=m,y%=m,z%=m;
        res = {0,x,y,z};
        data ret = solve(n);
        cout << ret.a << ' ' << ret.b << ' ' << ret.c << ' ' << ret.d << '\n';
    }
}