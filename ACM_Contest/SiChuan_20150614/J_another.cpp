#include <map>
#include <set>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int mmax = 500010;
const int inf=0x3fffffff;
struct node
{
    int x,y;
    void read() {scanf("%d %d",&x,&y);}
    node(int x,int y):x(x),y(y) {}
    node() {}
    bool operator < (const node &a) const
    {
        if(x==a.x) return y<a.y;
        return x<a.x;
    }
}P[2100];

map<node,int>q;
map<int,int>qx,qy;
set<int> Sx[2100],Sy[2100];
int dir[4][2]={1,0,0,-1,-1,0,0,1};

bool vis[10100][4];
bool fuck(int x,int y)
{
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(qx.count(tx)  &&  Sx[qx[tx]].count(ty)) cnt++;
    }
    return cnt==4;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        qx.clear(); qy.clear();
        for(int i=0;i<1100;i++) Sx[i].clear(),Sy[i].clear();
        int cntx=0,cnty=0;
        for(int i=0;i<n;i++)
        {
            P[i].read();
            if(!qx.count(P[i].x)) qx[P[i].x]=cntx++;
            if(!qy.count(P[i].y)) qy[P[i].y]=cnty++;
            Sx[ qx[P[i].x]  ].insert(P[i].y);
            Sy[ qy[P[i].y]  ].insert(P[i].x);
        }
        int nowx=0,nowy=0,nowdir=0;
        q.clear();
        int cc=0, cnt=0;
        bool fg=1;
        memset(vis,0,sizeof vis);
        while(1)
        {
            if(!q.count(node(nowx,nowy))) q[node(nowx,nowy)]=cc++;
            if(vis[q[node(nowx,nowy)]][nowdir])
            {
                fg=0;
                break;
            }
            else vis[q[node(nowx,nowy)]][nowdir]=1;
			if(nowdir==0)
            {
                if(!qy.count(nowy)) break;
                set<int>::iterator it;
                if(fuck(nowx,nowy))
                {
                    fg=0;
                    break;
                }
                it=Sy[ qy[nowy] ].upper_bound(nowx);
                if(it!=Sy[ qy[nowy] ].end())
                {
                    int tx=*it;
                    tx--;
                    nowx=tx;
                    nowdir++;
                    nowdir%=4;
                    cnt++;
                }
                else break;
            }
            else if(nowdir==1)
            {
                if(!qx.count(nowx)) break;
                set<int>::iterator it;
                if(fuck(nowx,nowy))
                {
                    fg=0;
                    break;
                }
                it=Sx[ qx[nowx] ].lower_bound(nowy);
                if(it!=Sx[ qx[nowx] ].begin())
                {
                    it--;
                    int ty=*it;
                    ty++;
                    nowy=ty;
                    nowdir++;
                    nowdir%=4;
                    cnt++;
                }
                else break;
            }
            else if(nowdir==2)
            {
                if(!qy.count(nowy)) break;
                set<int>::iterator it;
                if(fuck(nowx,nowy))
                {
                    fg=0;
                    break;
                }
                it=Sy[ qy[nowy] ].lower_bound(nowx);
                if(it!=Sy[ qy[nowy] ].begin())
                {
                    it--;
                    int tx=*it;
                    tx++;
                    nowx=tx;
                    nowdir++;
                    nowdir%=4;
                    cnt++;
                }
                else break;

            }
            else if(nowdir==3)
            {
                if(!qx.count(nowx)) break;
                set<int>::iterator it;
                if(fuck(nowx,nowy))
                {
                    fg=0;
                    break;
                }
                it=Sx[ qx[nowx] ].upper_bound(nowy);
                if(it!=Sx[ qx[nowx] ].end())
                {
                    int ty=*it;
                    ty--;
                    nowy=ty;
                    nowdir++;
                    nowdir%=4;
                    cnt++;
                }
                else break;
            }
        }
        if(!fg) puts("-1");
        else printf("%d\n",cnt);
    }
    return 0;
}
