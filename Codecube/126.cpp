#include <stdio.h>

char s[3][20];
int allow[4][10],ans,ch[4];

void solve(int x)
{
    if(s[0][1+ch[x]]!=' ') allow[x][1] = allow[x][4] = 0;
    if(s[1][ch[x]]!=' ') allow[x][1] = allow[x][2] = allow[x][3] = allow[x][7] = 0;
    if(s[1][1+ch[x]]!=' ') allow[x][1] = allow[x][7] = allow[x][0] = 0;
    if(s[1][2+ch[x]]!=' ') allow[x][5] = allow[x][6] = 0;
    if(s[2][ch[x]]!=' ') allow[x][1] = allow[x][3] = allow[x][4] = allow[x][5] = allow[x][7] = allow[x][9] = 0;
    if(s[2][1+ch[x]]!=' ') allow[x][1] = allow[x][4] = allow[x][7] = 0;
    if(s[2][2+ch[x]]!=' ') allow[x][2] = 0;
}

int main()
{
    for(int i = 0;i < 3;i++) fgets(s[i],19,stdin);
    for(int i = 0;i < 4;i++) for(int j = 0;j < 10;j++) allow[i][j] = 1;
    ch[1] = 3,ch[2] = 7,ch[3] = 10;
    for(int i = 0;i < 4;i++) solve(i);
    for(int i = 0;i < 24;i++) for(int j = 0;j < 60;j++) if(allow[0][i/10] and allow[1][i%10] and allow[2][j/10] and allow[3][j%10]) ans++;
    printf("%d",ans);
}
