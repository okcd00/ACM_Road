#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<string,string> pss;

map<pss,int> mpi;
map<pss,int> friends;

void update(string a,string b)
{
    pss f1=make_pair(a,b),f2=make_pair(b,a);
    if(friends[f1]==0 && friends[f2]==0)
    {
        friends[f1]=friends[f2]=1;
        //cout<<a<<":"<<b<<endl;
    }
}

int main()
{
    freopen("F.in","r",stdin);
    int T; scanf("%d",&T);
    for(int _T=0;_T<T;_T++)
    {
        mpi.clear();
        friends.clear();
        int n,d;    scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++)
        {
            string a,b;
            int t;
            cin>>a>>b>>t;
            pss tmp= make_pair(a,b);
            pss ask= make_pair(b,a);
            if(mpi[ask]!=0)
            {
                if(mpi[ask]==-1)
                {
                    if(t-(mpi[ask]+1)<=d && t-(mpi[ask]+1)>0)   //shenti!!! [a!=b]
                    update(a,b);
                }
                else if(t-mpi[ask]<=d && t-mpi[ask]>0)
                {
                    update(a,b);
                }
            }
            if(t!=0)mpi[tmp]=t;
            else mpi[tmp]=-1;
        }
        //for(map<pss,int>::iterator it=friends.begin();it!=friends.end();++it)
        printf("%d\n",friends.size()/2);
    }
    return 0;
}
