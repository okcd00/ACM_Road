#include <cmath> 
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int har[2048];
int ans[2048][3];
int tri[3]={0};
int dou[3][3]={0};
priority_queue<pii> p_q;
/*
void swap2(int a,int b,int mrk)
{
	ans[a-1][mrk]=ans[b-1][0];
	ans[b-1][mrk]=ans[a-1][0];
}

void swap3(int a,int b,int c)
{
	int t1=ans[a][0],t2=ans[b][0],t3=ans[c][0];
	ans[a-1][1]=t1;ans[a-1][2]=t2;ans[a-1][0]=t3;
	ans[a-1][2]=t1;ans[a-1][0]=t2;ans[a-1][1]=t3;
}
*/
int main()
{
	int n,flag=1,pos=0;	scanf("%d",&n);
	memset(har,0,sizeof har);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int hard;
		scanf("%d",&hard);
		if(flag>=0)
		{
			if(har[hard]==0) 
			{
				har[hard]=i;
				//cout<<"har["<<hard<<"]="<<i<<endl;
			}
			else if(har[hard]>0)
			{
				dou[pos][0]=har[hard];
				dou[pos][1]=i;
				har[hard]=-1;
				//cout<<dou[pos][0]<<":"<<dou[pos][1]<<endl;
				pos++;
				//cout<<"har["<<hard<<"]="<<-1<<endl;
				//cout<<"pos:"<<pos<<endl;
				if(pos>=2) flag=-2;
			}
			else if(har[hard]==-1)
			{
				tri[0]=dou[0][0];
				tri[1]=dou[0][1];
				tri[2]=i;
				flag=-3;
			}
		}
		p_q.push(pii(0-hard,i));
		//cout<<"input:"<<hard<<": "<<i<<" flag:"<<flag<<" pos:"<<pos<<endl;
	}
	if(flag>=0)cout<<"NO"<<endl;
	else 
	{
		int posi=0;
		while(!p_q.empty())
		{
			pii tt=p_q.top();
			ans[posi][0]=ans[posi][1]=ans[posi][2]=tt.second;
			p_q.pop();
			//cout<<ans[posi][0]<<endl;
			posi++;
		}
		/*
		if(flag==-2)	
		{
			swap2(dou[0][0],dou[0][1],1);
			swap2(dou[1][0],dou[1][1],2);
		}
		else if(flag==-3)
		{
			swap3(tri[0],tri[1],tri[2]);
		}
		*/
		cout<<"YES"<<endl;
		//1st
		for(int j=0;j<n-1;j++)
			printf("%d ",ans[j][0]);
		printf("%d\n",ans[n-1][0]);
		//2nd
		if(flag==-2)
		{
			for(int j=0;j<n-1;j++)
			{
					 if(ans[j][1]==dou[0][0])printf("%d ",dou[0][1]);
				else if(ans[j][1]==dou[0][1])printf("%d ",dou[0][0]);
				else printf("%d ",ans[j][1]);
			}
			if(ans[n-1][1]==dou[0][0])printf("%d\n",dou[0][1]);
			else if(ans[n-1][1]==dou[0][1])printf("%d\n",dou[0][0]);
			else printf("%d\n",ans[n-1][1]);
		}
		else if(flag==-3)
		{
			for(int j=0;j<n-1;j++)
			{
					 if(ans[j][1]==tri[0])printf("%d ",tri[1]);
				else if(ans[j][1]==tri[1])printf("%d ",tri[2]);
				else if(ans[j][1]==tri[2])printf("%d ",tri[0]);
				else printf("%d ",ans[j][1]);
			}
			if(ans[n-1][1]==tri[0])printf("%d\n",tri[1]);
			else if(ans[n-1][1]==tri[1])printf("%d\n",tri[2]);
			else if(ans[n-1][1]==tri[2])printf("%d\n",tri[0]);
			else printf("%d\n",ans[n-1][1]);
		}
		//3rd
		if(flag==-2)
		{
			for(int j=0;j<n-1;j++)
			{
					 if(ans[j][1]==dou[1][0])printf("%d ",dou[1][1]);
				else if(ans[j][1]==dou[1][1])printf("%d ",dou[1][0]);
				else printf("%d ",ans[j][1]);
			}
			if(ans[n-1][1]==dou[1][0])printf("%d\n",dou[1][1]);
			else if(ans[n-1][1]==dou[1][1])printf("%d\n",dou[1][0]);
			else printf("%d\n",ans[n-1][1]);
		}
		else if(flag==-3)
		{
			for(int j=0;j<n-1;j++)
			{
					 if(ans[j][1]==tri[0])printf("%d ",tri[2]);
				else if(ans[j][1]==tri[1])printf("%d ",tri[0]);
				else if(ans[j][1]==tri[2])printf("%d ",tri[1]);
				else printf("%d ",ans[j][1]);
			}
			if(ans[n-1][1]==tri[0])printf("%d\n",tri[2]);
			else if(ans[n-1][1]==tri[1])printf("%d\n",tri[0]);
			else if(ans[n-1][1]==tri[2])printf("%d\n",tri[1]);
			else printf("%d\n",ans[n-1][1]);
		}
	}
	return 0;
}
