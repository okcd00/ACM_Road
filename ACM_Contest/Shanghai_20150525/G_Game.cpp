#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#define rep(i,a,b) for (int i=a;i<((b)+1);i++)
#define Rep(i,a,b) for (int i=a;i>=b;i--)
#define foreach(e,x) for (__typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define mid ((l+r)>>1)  //segement tree
#define lson (k<<1)     //segement tree
#define rson (k<<1|1)   //segement tree
#define MEM(a,x) memset(a,x,sizeof a)
#define L ch[r][0]                  //splay tree
#define R ch[r][1]                  //splay tree
#define keyvalue ch[ch[root][1]][0] //splay tree
using namespace std;
const int N=1000050;
const long long Mod=1e9+7;
const int inf=0x3f3f3f3f;
typedef pair<int, int> pii;
typedef long long ll;
int pnt[N],head[N],nxt[N],cnt,fa[N],a[N],n,m,k;
bool vis[N];
struct P{
    int u;ll w;
    P(){}
    P(int _u,ll _w) {
        u=_u;w=_w;
    }
};
void addedge(int u,int v) {
    pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}
vector<P>   vt;
bool cmp(const P &a,const P &b) {
    return a.w>b.w;
}
void dfs(int u,int f,ll w) {
    bool flag=true;
    fa[u]=f;
    for (int i=head[u];i!=-1;i=nxt[i]) {
        int v=pnt[i];
        if (v==f)   continue;
        flag=false;
        dfs(v,u,w+a[v]);
    }
    if (flag)   vt.push_back(P(u,w));
}
int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    rep(z,1,T) {
        scanf("%d%d",&n,&k);
        MEM(head,-1);MEM(vis,false);
        cnt=0;
        rep(i,1,n)  scanf("%d",&a[i]);
        rep(i,1,n-1) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1,1,a[1]);
        sort(vt.begin(),vt.end(),cmp);
        ll ans=0;
        priority_queue<ll,vector<ll>,less<ll> > p;
        rep(i,0,vt.size()-1) {
            P cur=vt[i];
            ll tmp=0;int u=cur.u;
            while (!vis[u]) {
                tmp+=a[u];
                vis[u]=true;
                u=fa[u];
            }
            p.push(tmp);
        }
        rep(i,1,k) {
            if (p.empty())  break;
            ans+=p.top();p.pop();
        }
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}