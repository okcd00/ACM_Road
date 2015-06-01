#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const double EPS=1e-10;

double add(double a,double b)
{
    if( fabs(a+b) < EPS*( abs(a)+abs(b)) )return 0;
    return a+b;
}

struct P
{
    double x;
    double y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator+ (P p)
    {return P(add(x,p.x),add(y,p.y));}
    P operator- (P p)
    {return P(add(x,-p.x),add(y,-p.y));}
    P operator* (double d)
    {return P(x*d,y*d);}
    double dot(P p)//neiji
    {return add(x*p.x,y*p.y);}
    double det(P p)//waiji
    {return add(x*p.y,-y*p.x);}
};

bool cmp_x(const P& p,const P& q)
{
    if(p.x != q.x) return p.x<q.x;
    return p.y<q.y;
}

vector<P> convex_hull(P* ps,int n)
{
    sort(ps,ps+n,cmp_x);
    //for(int i=0;i<n;i++){cout<<ps[i].x<<":"<<ps[i].y<<endl;}
    int k=0;
    vector<P> qs(n<<1);
    for(int i=0;i<n;i++)
    {
        while( k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0 )k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k; i>=0; i--)
    {
        while( k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0 )k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}

int N;
P ps[1024];

void solve()
{
    vector<P> qs = convex_hull(ps,N);
    //cout<<qs.size()<<endl;
    if(qs.size()<=3)printf("Y\n");
    else printf("N\n");
}

int main()
{
    freopen("G.in","r",stdin);
    int T; scanf("%d",&T);
    for(int _T=0;_T<T;_T++)
    {
        double tx,ty;
        scanf("%d",&N);
        memset(ps,0,sizeof ps);
        for(int i=0;i<N;i++)
        {
            cin>>tx>>ty;
            //cout<<tx<<":"<<ty<<endl;
            ps[i].x=tx;
            ps[i].y=ty;
        }
        solve();
    }
    return 0;
}
