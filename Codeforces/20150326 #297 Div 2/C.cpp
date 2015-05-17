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
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}
ll ans=0;
priority_queue<int> pq;
int main()
{
	while(!pq.empty()) pq.pop();
	int n,iv=0;	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&iv);
		pq.push(iv);
	} 
	while(!pq.empty())
	{
		int longer=0,another=0;
		while(!pq.empty())
		{
			longer=pq.top();
			pq.pop(); 
			if(!pq.empty()) another=pq.top();
			else break;
			if(another+1<longer) continue;
			else 
			{
				pq.pop();
				break;
			}
		}
		int shorter=0,anos=0;
		while(!pq.empty())
		{
			shorter=pq.top();
			pq.pop(); 
			if(!pq.empty()) anos=pq.top();
			else break;
			if(anos+1<shorter) continue;
			else
			{
				pq.pop();
				break;
			}
		}
		ans+=(ll)another*(ll)anos;
		//cout<<ans<<":"<<another<<":"<<anos<<endl;
	}
	cout<<ans;
	return 0;
}
