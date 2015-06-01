#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int exp[101];

void exp_init()
{
    memset(exp,0,sizeof exp);
    exp[0]=-1;
    exp[1]=0;
    for(int i=2;i<101;i++)
    {
        exp[i]=exp[i-1]+300+(i-2)*100;
        //cout<<i<<":"<<exp[i]<<endl;
    }
}

int main()
{
    freopen("B.in","r",stdin);
    int T;  scanf("%d",&T);
    exp_init();
    for(int _T=0;_T<T;_T++)
    {
        int n,l,e;
        scanf("%d%d%d",&n,&l,&e);
        int now=exp[l]+e-n;
        int lv= upper_bound(exp,exp+101,now)-exp-1;
        int rest=now-exp[lv];
        cout<<lv<<" "<<rest<<endl;
    }
    return 0;
}
