#include <cmath> 
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;	cin>>n;
	priority_queue <pair<int, int> > pq;  
	while(!pq.empty())pq.pop();
	for(int i=0;i<n;i++)
	{
		int a,b;	cin>>a>>b;
		pq.push(make_pair(a,b));
	}
	int la=-1,lb=-1,flag=0;
	while(!pq.empty())
	{
		pair<int,int> tmp=pq.top();pq.pop();
		//cout<<tmp.first<<"\t"<<tmp.second<<endl;
		if(la==-1 && lb==-1) la=tmp.first,lb=tmp.second;
		else
		{
			if(tmp.second>lb){flag=1;break;}
			lb=tmp.second;
		}
		
	}
	if(!flag)puts("Poor Alex");
	else puts("Happy Alex");
	
	return 0;
}
