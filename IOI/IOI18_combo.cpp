#include <bits/stdc++.h>
#include "combo.h"
using namespace std;
   
string guess_sequence(int n)
{
    string all = "ABXY",pos,ans;
    if(press("AB"))
    {
        if(press("A")) ans = "A";
        else ans = "B";
    }
    else
    {
        if(press("X")) ans = "X";
        else ans = "Y";
    }
    if(n==1) return ans;
    for(int i = 0;i < 4;i++) if(all[i]!=ans[0]) pos = pos+all[i];
    for(int i = 1;i < n-1;i++)
    {
        string tmp = ans+pos[0];
        for(int j = 0;j < 3;j++) tmp+=ans+pos[1]+pos[j];
        int ret = press(tmp);
        if(ret==i) ans+=pos[2];
        else if(ret==i+1) ans+=pos[0];
        else ans+=pos[1];
    }
    if(press(ans+pos[0]+ans+pos[1])==n) 
    {
        if(press(ans+pos[0])==n) ans+=pos[0];
        else ans+=pos[1];
    }
    else ans+=pos[2];
    return ans;
}
