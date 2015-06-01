#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> lk[1024];
int dist[1024];

void bfs(int start)
{
    int mov=0;
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(start);
    while(!q.empty())
    {
        int now=q.front(); q.pop(); mov++;
        for(int i=0;i<lk[now].size();i++)
        {
            q.push(lk[now][i]);
            dist[lk[now][i]]=mov;
        }
    }

}

int main()
{
    freopen("E.in","r",stdin);
    int T; scanf("%d",&T);
    for(int _T=0;_T<T;_T++)
    {
        int n,k;    cin>>n>>k;
        memset(lk,0,sizeof lk);
        memset(dist,0,sizeof dist);
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a<b) lk[a].push_back(b);
            else lk[b].push_back(a);
        }
        bfs(1);
    }
    return 0;
}
