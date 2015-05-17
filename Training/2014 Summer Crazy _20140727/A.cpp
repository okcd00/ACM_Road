#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define update(a) ans=(ans==-1?a:ans>a?a:ans)
using namespace std;

int price[10001];
int match[101][101];
vector<int> v[101];

int main()
{
	int N,M,ans=-1;
	cin>>N>>M;
	memset(price,0,sizeof price);
	memset(match,0,sizeof match);
	for(int i=0;i<101;i++) v[i].clear();
	for(int i=1;i<=N;i++)
	{
		int tmp;
		cin>>tmp;
		price[i]=tmp;
	}
	for(int j=1;j<=M;j++)
	{
		int a,b;
		cin>>a>>b;
		match[a][b]=match[b][a]=1;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1;i<=N-1;i++)	//I am 1st point
	{
		for(int j=0;j<v[i].size();j++) //I am 2nd point
		{
			int k=v[i].at(j);
			if(k<j)continue;
			else
			{
				for(int l=0;l<v[k].size();l++)
				{
					int m=v[k].at(l);
					for(int n=0;n<v[m].size();n++)
					{
						int o=v[m].at(n);
						if(o==i) update(price[i]+price[k]+price[m]);
						//cout<<i<<' '<<k<<' '<<m<<endl;
					}
				}
			} 
		}
	}

	
	cout<<ans<<endl;
	return 0;
} 
