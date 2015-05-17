#include <map>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define MP(a,b) make_pair(a,b)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int gem[30033]={0},pos[30033]={0};
map<pair<int,int>,int> mpi;
queue<int> q;

int main()
{
	int n,d,temp;	cin>>n>>d;
	q.clear(); q.push_back(d);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		pos[i]=temp;
		gem[temp]++;
	} 
	while(!q.empty())
	{
		int now=q.front(); q.pop();
		if(now>temp) continue;
		for(int i=-1;i<=1;i++)
		{
			if(now+i<=0)continue;
			q.push_back(now+i);
		}
		pii tpii=MP();
		mpi[]
	}
	return 0;
}
