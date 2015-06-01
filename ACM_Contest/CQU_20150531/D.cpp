#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

double fd[10086],nfd[10086];
bool cmp(const double a,const double b)
{
    return a - b > 0.0;
}

int main()
{
    freopen("D.in","r",stdin);
    int T; scanf("%d",&T);
    for(int _T=0;_T<T;_T++)
    {
        int n,m,posf=0,posn=0;
        double sum=0.0;
        scanf("%d%d",&n,&m);
        memset(fd,0,sizeof fd);
        memset(nfd,0,sizeof nfd);
        for(int i=0;i<m;i++)
        {
            int p,t;
            scanf("%d%d",&p,&t);
            if(t==1)
            {
                fd[posf++]=(double)p*0.8;
                sum+=(double)p*0.8;
            }
            else
            {
                nfd[posn++]=(double)p;
                sum+=(double)p;
            }
        }
        sort(fd,fd+posf,cmp);
        sort(nfd,nfd+posn,cmp);
        int lenf=posf,lenn=posn;
        posf=posn=0;
        for(int i=0;i<n;i++)
        {
            if(posn==lenn)break;
            if(i==n-1)
            {
                if(posf==lenf)sum-=nfd[lenn-1]/2.0;
                else sum-=min(nfd[lenn-1],fd[lenf-1])/2.0;
            }
            else
            {
                sum-=(nfd[posn]/2.0);
                posn++;
            }
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
