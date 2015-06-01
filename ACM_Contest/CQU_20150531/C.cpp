#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

char mp[20][20];
int nmp[20][20];

void update(int n,int x,int y)
{
    int dir[8][2]={-2,-2,-1,-1,1,1,2,2,1,-1,2,-2,-1,1,-2,2};
    for(int i=0;i<8;i++)
    {
        if(x+dir[i][0]>=1 && x+dir[i][0]<=n && y+dir[i][1]>=1 && y+dir[i][1]<=n)
            nmp[x+dir[i][0]][y+dir[i][1]]++;
    }
}

int main()
{
    freopen("C.in","r",stdin);
    int T;  scanf("%d",&T);
    for(int _T=0;_T<T;_T++)
    {
        memset(nmp,0,sizeof nmp);
        int n=0;    scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            getchar();
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&mp[i][j]);
                if(mp[i][j]=='x') update(n,i,j);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j]=='x')printf("x");
                else printf("%d",nmp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
