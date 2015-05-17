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

int pit[8][3];
int tmp[8][3];
int ans[8][3];
int flag=0;

bool judge()
{
	bool f=false;
	//已知空间八个点的坐标如何判定是否构成正方体啊啊啊啊！ 
	if(f)return true;
	else return false;
}

void dfs(int i)
{
	if(i!=8)
	if(pit[i][0]==pit[i][1] && pit[i][0]==pit[i][1])
	{
		tmp[i][0]=pit[i][0];
		tmp[i][1]=pit[i][1];
		tmp[i][2]=pit[i][2];
		dfs(i+1);
	}
	else
	{
		tmp[i][0]=pit[i][0];
		tmp[i][1]=pit[i][1];
		tmp[i][2]=pit[i][2];
		dfs(i+1);
		tmp[i][0]=pit[i][0];
		tmp[i][1]=pit[i][2];
		tmp[i][2]=pit[i][1];
		dfs(i+1);
		tmp[i][0]=pit[i][1];
		tmp[i][1]=pit[i][0];
		tmp[i][2]=pit[i][2];
		dfs(i+1);
		tmp[i][0]=pit[i][1];
		tmp[i][1]=pit[i][2];
		tmp[i][2]=pit[i][0];
		dfs(i+1);
		tmp[i][0]=pit[i][2];
		tmp[i][1]=pit[i][0];
		tmp[i][2]=pit[i][1];
		dfs(i+1);
		tmp[i][0]=pit[i][2];
		tmp[i][1]=pit[i][1];
		tmp[i][2]=pit[i][0];
		dfs(i+1);
	}
	
	if(i==8)
	{
		if(judge())
			for(int i=0;i<8;i++)
				for(int j=0;j<3;j++)
					ans[i][j]=tmp[i][j];
		else ;
	}

}

int main()
{
	memset(pit,0,sizeof pit);
	memset(tmp,0,sizeof tmp);
	memset(ans,0,sizeof ans);
	for(int i=0;i<8;i++)
		scanf("%d%d%d",&pit[i][0],&pit[i][1],&pit[i][2]);
	dfs(0);
	if(flag==0)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	if(flag)
	{
		for(int i=0;i<8;i++)
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}
