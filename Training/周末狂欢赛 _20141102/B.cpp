#include <deque>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Lim 102
#define eps 1e8
using namespace std;

deque<int> noq;
bool gra[Lim][Lim];
int l,r1,r2,value,wid,mid,vn;

void solve(int vv,int i,int rr1,int rr2)
{
    if(value>=vv)
    {  value=vv;l=i;r1=rr1;r2=rr2;    }
}

int main()
{
    int n,k;    scanf("%d%d",&n,&k);
    mid=(k+1)>>1;
    memset(gra,true,sizeof(gra));
    while(n--)
    {
        scanf("%d",&wid);
        value=eps;
        for(int i=k;i>=1;i--)
        {
            noq.clear();
            vn=0;
            if(k<wid)break;
            for(int j=k;j>k-wid;j--)
            {
                if(!gra[i][j])noq.push_back(j);
                vn+=abs(i-mid)+abs(j-mid);
            }
           if(noq.empty())solve(vn,i,k-wid+1,k);
            for(int j=k-wid;j>=1;j--)
            {
               while(!noq.empty()&&(*noq.begin())-wid>=j)noq.pop_front();
               if(!gra[i][j])noq.push_back(j);
               vn=vn-(abs(i-mid)+abs(j+wid-mid))+abs(i-mid)+abs(j-mid);
                    if(noq.empty())solve(vn,i,j,j+wid-1);
            }
        }
            if(value<eps)
            {
                printf("%d %d %d\n",l,r1,r2);
                for(int i=r1;i<=r2;i++)gra[l][i]=0;
            }
            else printf("-1\n");
    }
    return 0;
}

