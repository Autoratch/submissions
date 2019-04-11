#include <bits/stdc++.h>
using namespace std;
#define point pair<int,int>
#define x first
#define y second
 
const int N = 1e5;
 
point s[N],sx[N],sy[N];
int n;
 
bool cmpx(const point &a,const point &b){ if(a.x!=b.x) return a.x<b.x; else return a.y<b.y; }
 
bool cmpy(const point &a,const point &b){ if(a.y!=b.y) return a.y<b.y; else return a.x<b.x; }
 
long long dist(point a,point b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
 
long long solvestrip(point strip[],int sz,long long mn)
{
    for(int i = 0;i < sz;i++) for(int j = i+1;j < sz and strip[j].y-strip[i].y<mn;j++) mn = min(mn,dist(strip[i],strip[j]));
    return mn;
}
 
long long solve(point px[],point py[],int sz)
{
    if(sz<=3)
    {
        long long mn = LLONG_MAX;
        for(int i = 0;i < sz;i++) for(int j = i+1;j < sz;j++) mn = min(mn,dist(px[i],px[j]));
        return mn;
    }
 
    int m = sz/2;
    int li = 0,ri = 0;
    point mid = px[m];
    point pyl[m+1];
    point pyr[n-m+1];
 
    for(int i = 0;i < n;i++)
    {
        if(py[i].x<=mid.x) pyl[li++] = py[i];
        else pyr[ri++] = py[i];
    }
 
    long long mnl = solve(px,pyl,m);
    long long mnr = solve(px+m,pyr,sz-m);
    long long mn = min(mnl,mnr);
 
    point strip[sz];
    int j = 0;
 
    for(int i = 0;i < sz;i++) if(abs(py[i].x-mid.x)<mn){ strip[j] = py[i]; j++; }
 
    return min(mn,solvestrip(strip,j,mn));
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
 
    for(int i = 0;i < n;i++){ cin >> s[i].x >> s[i].y; sx[i] = sy[i] = s[i]; }
 
    sort(sx,sx+n,cmpx);
    sort(sy,sy+n,cmpy);
 
    cout << solve(sx,sy,n);
}
