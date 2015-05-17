#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Why not trying force^
using namespace std;
int x[103][4];
int main(){

    int n,i,j,min=1001,index; cin>>n;
    for(i=0;i<n;i++)
        scanf("%d %d %d %d",&x[i][0],&x[i][1],&x[i][2],&x[i][3]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if((x[j][0]<x[i][0])&&(x[j][1]<x[i][1])&&(x[j][2]<x[i][2]))
                  x[j][3]=1000+1;//goto back

    for(i=0;i<n;i++)      if(x[i][3]<min){min=x[i][3];index=i+1;}
    cout<<index<<endl;
}

/*****************Unlimited Loop**********************
#define S first.first 
#define R first.second
#define H second.first
#define C second.second
#define CPT(s,r,h,c) make_pair(make_pair(s,r),make_pair(h,c))
using namespace std;
int cost[101];
typedef pair<int,int> pii;
vector < pair<pii,pii> > v;

int main()
{
	memset(cost,0,sizeof cost);
	priority_queue < pair<pii,pii> > pq;
	while(!pq.empty())pq.pop();
	int n;	cin>>n;
	for(int i=0;i<n;i++)
	{
		int s,r,h,c;	cin>>s>>r>>h>>c;
		pq.push(CPT(s,r,h,i+1));
		cost[i+1]=c;
	}
	queue < pair<pii,pii> > q;
	while(!q.empty())q.pop();
	while(!pq.empty())
	{
		q.push(pq.top());
		pq.pop();	
	}
	while(!q.empty())
	{
		pair<pii,pii> last=q.front();pq.pop();
		v.push_back(last);
		for(int i=0;i<n;i++)
		{
			pair<pii,pii> now=q.front();q.pop();
			if(now.S<last.S &&now.R<last.R &&now.H<last.H);
			else q.push(now);
		}		
	}
	int minc=9999,index=-1;
	for(int i=0;i<v.size();i++)
	{
		if(minc>v.at(i).C)
		{
			minc=cost[v.at(i).C];
			index=v.at(i).C;
		} 
	}
	cout<<minc;
	return 0;
} 
**********************************************************/
