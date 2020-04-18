#include <stdio.h>

const int N = 5e4 + 1;
const int MOD = 1e6 + 7;

int n,m;
int a[500],dp[N][2],cur = 1,pre;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",a+i);
    dp[0][pre] = dp[0][cur] = 1;
    for(int i = 0;i < n;i++)
    {
        for(int j = 1;j <= m;j++) 
        {
            if(a[i]>j) continue;
            dp[j][cur]+=dp[j-a[i]][pre];
            dp[j][cur]%=MOD;
        }
        for(int j = 1;j <= m;j++) dp[j][cur]+=dp[j][pre],dp[j][cur]%=MOD; 
        for(int j = 1;j <= m;j++) dp[j][pre] = 0;
        int tmp = cur;
        cur = pre;
        pre = tmp;
    }
    printf("%d",dp[m][pre]);
}