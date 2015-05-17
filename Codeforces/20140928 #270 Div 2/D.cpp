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

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define OUT {cout<<"NO"<<endl;return 0;}

int dist[2048][2048];

int main()
{
	int n;	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&dist[i][j]);
			dst[i][j]=dist[i][j];
			if(i==j && dist[i][j]!=0) OUT
			else if(i>j) if(dist[i][j]==0 || dist[j][i]==0 || dist[i][j]!=dist[j][i]) OUT
		}
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j]) dst[i][j]=dist[i][k]+dist[k][j];
				
			}
		}
	return 0;
}
