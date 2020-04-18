#include <bits/stdc++.h>
using namespace std;

const int N = 4001;

int n,k;
char c[N*3];
int a[N][N],dp[2][N];

void compute(int l,int r,int optl,int optr,int f,int id)
{
    if(l>r) return;
    int mid = (l+r)/2;
    int val = INT_MAX,opt;
    for(int i = optl;i <= min(optr,mid);i++)
    {
        int now = dp[f^1][i]+a[mid][mid]-a[i][mid]-a[mid][i]+a[i][i];
        if(now<val) val = now,opt = i;
    }
    dp[f][mid] = val;
    compute(l,mid-1,optl,opt,f,id);
    compute(mid+1,r,opt,optr,f,id);
}

int main()
{
    scanf("%d%d",&n,&k);
    getchar();
    for(int i = 1;i <= n;i++)
    {
        fgets(c,N*2,stdin);
        for(int j = 1;j <= n;j++) a[i][j] = c[2*(j-1)]-'0';
    }
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i = 1;i <= n;i++) dp[1][i] = a[i][i];
    for(int i = 2;i <= k;i++) compute(i,n,1,n,i%2,i);
    printf("%d",dp[k%2][n]/2);
}
