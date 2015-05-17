#include <cmath>   
#include <queue>
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
typedef pair<int,int> p;

int main()
{
	int n,m;
	cin>>n>>m;
	queue<p> q;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		q.push(make_pair(tmp,i));
	}
	p now=make_pair(0,1);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now.first<=m);//sorry for forgetting '='
		else q.push(make_pair(now.first-m,now.second));
	}
	cout<<now.second;
	return 0;
}
