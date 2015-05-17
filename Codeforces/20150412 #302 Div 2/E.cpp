#include <map>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int n,m,cnt;
int a[22][22]={0};
int uniq[22]={0}; 
map<char,int> mcol[22];
string str[22];

void rule_out()
{
	for(int i=0;i<n;i++)
	{
		if(uniq[i])continue;
		for(int j=0;j<m;j++)
		{
			if(mcol[j][str[i][j]]==1) 
			{
				uniq[i]=1,cnt--;	//rule-out 
				//cout<<"ruleout "<<i<<endl; 
			}
		} 
	}
}

int main()
{
	int cost=0;	cin>>n>>m; cnt=n;
	for(int i=0;i<m;i++) mcol[i].clear();
	for(int i=0;i<n;i++)
	{
		uniq[i]=0;
		cin>>str[i];
		for(int j=0;j<m;j++)
		{
			mcol[j][str[i][j]]++;
		}
	} 
	rule_out();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	while(cnt>1)
	{
		int vmin=6666666,rec_i=-1;
		for(int i=0;i<n;i++)
		{
			if(uniq[i])continue;
			for(int j=0;j<m;j++)
			{
				if(a[i][j]<vmin) vmin=a[i][j],rec_i=i;
			}
		}
		cost+=vmin;
		cnt--;
		uniq[rec_i]=1;
		for(int j=0;j<m;j++)
		{
			mcol[j][str[rec_i][j]]--;
			if(mcol[j][str[rec_i][j]]==1)
				for(int i=0;i<n;i++)
				{
					if(uniq[i])continue;
					if(str[i][j]==str[rec_i][j]) 
					{
						uniq[i]=1,cnt--;
						cout<<"out"<<str[rec_i][j]<<":"<<i<<endl;	
					}
				}
		}
	}
	cout<<cost; 
	return 0;
}
