#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,ex=0,a[111][111];
bool v[111]={0},zero[111]={0},lg[111][111];

void dfs(int i)
{
    v[i]=true;
    for (int j=1;j<=n;j++)
        if (a[i][j] && !v[j])	dfs(j);
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int t;	cin>>t;
        if (t==0)	zero[i]=true, ex++;
        while (t--)
        {
            int c;	cin>>c;
            lg[i][c]=true;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j) for (int k=1;k<=m;k++) if (lg[i][k]&&lg[j][k])	a[i][j]=1;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!v[i]&&!zero[i])
        {
            dfs(i);
            ans++;
        }
    }
    ans--;
    if (ans<0) ans=0;
    cout<<ans+ex<<endl;
    return 0;
}
