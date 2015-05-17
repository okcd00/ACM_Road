#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int mat[111][111]={0};
int ans[111][111]={0};
int visrow[111]={0};
int col[111]={0},vcol=0;
int row[111]={0},vrow=0;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}



int main()
{
	int n,m;	cin>>n>>m;
	int flag=0,zero=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&mat[i][0]);	flag=0;
		if(mat[i][0]) flag=1,zero=1;
		for(int j=1;j<m;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j]) zero=1;
			if(mat[i][j]!=mat[i][0])
			{
				flag=0;
			}
		}
		if(flag) row[vrow++]=i, visrow[i]=1;
	}
	for(int j=0;j<m;j++)
	{
		flag=0;
		if(mat[0][j]) flag=1;
		for(int i=1;i<n;i++)
		{
			if(mat[i][j]!=mat[0][j])
			{
				flag=0;
			}		
		}
		if(flag) col[vcol++]=j;
		else
		{
			for(int i=0;i<n;i++)
			{
				if(mat[i][j] && visrow[i]==0)
				{
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	if(zero==0)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			printf("%d",mat[i][0]);
			for(int j=1;j<m;j++)
			{
				printf(" %d",mat[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	if(vcol==0 || vrow==0)
	{
		cout<<"NO";
		return 0;
	}
	int l=max(vcol,vrow),s=min(vcol,vrow),cntp=0;
	for(cntp=0;cntp<s;cntp++)
	{
		ans[row[cntp]][col[cntp]]=1;	
	}
	if(l==vrow)	for(;cntp<l;cntp++)
	{
		ans[row[cntp]][col[0]]=1;
	}
	else for(;cntp<l;cntp++)
	{
		//ans[col[cntp]][row[0]]=1;
		ans[row[0]][col[cntp]]=1;
	}
	printf("YES\n");
	for(int i=0;i<n;i++)
	{
		printf("%d",ans[i][0]);
		for(int j=1;j<m;j++)
		{
			printf(" %d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
