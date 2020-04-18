#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int q;
string s[N];
int fw[N],bw[N],idx,cur;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> q;

    fw[cur] = -1;
    bw[cur] = -1;

    for(int i = 1;i <= q;i++)
    {
        char c;
        cin >> c;
        if(c=='i') 
        {
            cin >> s[i];
            if(fw[cur]!=-1)
            {
                fw[i] = fw[cur];
                bw[fw[i]] = i;
                fw[cur] = i;
                bw[i] = cur;
                cur = i;
            }
            else fw[cur] = i,bw[i] = cur,cur = i,fw[i] = -1;
        }
        else if(c=='l'){ if(bw[cur]!=-1) cur = bw[cur]; }
        else if(c=='r'){ if(fw[cur]!=-1) cur = fw[cur]; }
        else if(c=='d')
        {
            if(fw[cur]==-1) continue;
            if(fw[fw[cur]]==-1) fw[cur] = -1;
            else bw[fw[fw[cur]]] = cur,fw[cur] = fw[fw[cur]];
        }
        else if(c=='b')
        {
            if(cur==0) continue;
            if(bw[cur]==0) bw[cur] = 0,fw[0] = -1,cur = bw[cur];
            else fw[bw[cur]] = fw[cur],bw[fw[cur]] = bw[cur],cur = bw[cur];
        }/*
        for(int j = 0;j != -1;j = fw[j]) cout << s[j] << ' ';
        cout << s[cur];
        cout << endl;*/
    }

    for(int i = fw[0];i != -1;i = fw[i]) cout << s[i] << ' ';
}
