#include <bits/stdc++.h>
using namespace std;

const int N = 2003;

int n,k;
char a[N][N];
int br[N],bc[N],s[N][N],rer[N][N],rec[N][N],ret[N][N];
int ans,z;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) br[i]+=(a[i][j]=='B'),bc[j]+=(a[i][j]=='B'),s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='B');

    for(int i = 1;i <= n;i++) 
    {
        if(!br[i]) z++;
        if(!bc[i]) z++;
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j+k-1 <= n;j++) if(s[i][j+k-1]-s[i][j-1]-s[i-1][j+k-1]+s[i-1][j-1]==br[i] and br[i]) rer[i][j]++;
    
    for(int i = 1;i+k-1 <= n;i++) for(int j = 1;j <= n;j++) if(s[i+k-1][j]-s[i-1][j]-s[i+k-1][j-1]+s[i-1][j-1]==bc[j] and bc[j]) rec[i][j]++;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) rer[i][j]+=rer[i-1][j],rec[i][j]+=rec[i][j-1];
//    for(int i = 1;i <= n;i++) for(int j = 1;j+k-1 <= n;j++) if(s[j+k-1][i]-s[j-1][i]-s[j+k-1][i-1]+s[j-1][i-1]==bc[i]) res[j][i]++,cout << j << ' ' << i << endl;

//    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cout << i << ' ' << j << ' ' << res[i][j] << endl;

//    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) res[i][j]+=res[i-1][j]+res[i][j-1]-res[i-1][j-1];

    for(int i = 1;i+k-1 <= n;i++) for(int j = 1;j+k-1 <= n;j++)
    {
   //     ret[i][j] = res[i][j+k-1]-res[i][j-1]-res[i-1][j+k-1]+res[i-1][j-1]+res[i+k-1][j]-res[i-1][j]-res[i+k-1][j-1]+res[i-1][j-1]-(res[i][j]-res[i][j-1]-res[i-1][j]+res[i-1][j-1]);
        ret[i][j] = rer[i+k-1][j]-rer[i-1][j]+rec[i][j+k-1]-rec[i][j-1];
        ans = max(ans,ret[i][j]);
    }

//    for(int i = 1;i+k-1 <= n;i++) for(int j = 1;j+k-1 <= n;j++) ret[i][j] = res[i+k-1][j+k-1]-res[i-1][j+k-1]-res[i+k-1][j-1]+res[i-1][j-1];

//    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) res[i][j]+=res[i-1][j]+res[i][j-1]-res[i-1][j-1];

  //  for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) ans = max(ans,ret[i][j]),cout << i << ' ' << j << ' ' << ret[i][j] << endl;

    cout << ans+z;
}
