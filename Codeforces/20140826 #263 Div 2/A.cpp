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

int main()
{
	int n,flag=0;	cin>>n;
	char c,map[101][101];
	for(int i=0;i<n;i++)
	{
		scanf("%c",&c);//huiche
		for(int j=0;j<n;j++)
		{
			scanf("%c",&map[i][j]);
		}
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cnt=0;
			if(i>0 && map[i-1][j]=='o')cnt++;
			if(i<n-1 && map[i+1][j]=='o')cnt++;
			if(j>0 && map[i][j-1]=='o')cnt++;
			if(j<n-1 && map[i][j+1]=='o')cnt++;
			//cout<<i<<" "<<j<<": "<<cnt<<endl;
			if(cnt%2!=0)flag=1; 
		}
	}
	if(flag)printf("NO");
	else printf("YES");
	return 0;
} 
