#include <cmath> 
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

int n=0,m=0;
int cases=0;
int ans[128]={0};

struct Node
{
	int pre;
	int val;
	int mine;	//minimal energy
}mat[128][128]={0};

bool judge(int col, int dir)
{
	if(dir==-1 && col==0) return false;
	if(dir== 1 && col==m-1) return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		int end=0;	//min_ending
		memset(mat,0,sizeof mat);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&mat[i][j].val);
		for(int j=0;j<m;j++)
		{
			mat[0][j].pre=-1;
			mat[0][j].mine=mat[0][j].val;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				mat[i][j].mine=-1;
				for(int dir=-1;dir<=1;dir++)
				{
					if(judge(j,dir))
					{
						if(mat[i][j].mine==-1 || mat[i-1][j+dir].mine+mat[i][j].val<=mat[i][j].mine) 
						{
							mat[i][j].mine=mat[i-1][j+dir].mine+mat[i][j].val;
							mat[i][j].pre=j+dir;
						}
					}
				}
//				cout<<i<<":"<<j<<":"<<mat[i][j].mine<<":"<<mat[i][j].pre<<endl;
			}
		}
		for(int j=0;j<m;j++)
		{
			if(mat[n-1][j].mine <= mat[n-1][end].mine) end=j;
//			printf("%d:%d\n",j,mat[n-1][j].mine);	
		} 
		int pos=0;
		int nowp=n-1;
//		cout<<end<<endl;
		while(mat[nowp][end].pre!=-1)
		{
			ans[pos++]=end+1;
			end=mat[nowp][end].pre;
			nowp--;
		}
		ans[pos++]=end+1;
		printf("Case %d\n",_case);
		for(int i=pos-1;i>=0;i--) 
		{
			if(i!=pos-1) printf(" ");
			printf("%d",ans[i]);
			if(i==0) printf("\n"); 
		}
	}
	return 0;
}
