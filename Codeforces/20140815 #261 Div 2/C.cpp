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
int n,k,d,depth;	
int stu[1008][1008];  //stu(d,n)=no.k

int judge()
{
	ll tmp=k,tmpd=d;
	while(1)
	{
		if(tmp>=n)return (int)d-(int)tmpd+1;
		if(tmpd==1)return -1;
		tmpd--;
		tmp*=k;
	}
}

void init()
{
	memset(stu,0,sizeof stu);
	for(int i=1;i<=depth;i++)		stu[i][1]=1;
	for(int j=2;j<=n;j++)
	{
		stu[depth][j]+=1;
		for(int i=depth;i>=1;i--)
		{
			stu[i][j]+=(stu[i][j-1]);
			if(stu[i][j]>k)	stu[i][j]=stu[i][j]%k,stu[i-1][j]++;
		}
	}
}

int main()
{
	cin>>n>>k>>d;
	depth=judge();
	if(depth==-1){cout<<-1<<endl;	return 0;}
	else init();
	
	for(int i=1;i<=depth;i++)
	{
		cout<<stu[i][1];
		for(int j=2;j<=n;j++)
		{
			cout<<" "<<stu[i][j];
		}
		cout<<endl;
	}
	for(int i=depth+1;i<=d;i++)
	{
		cout<<stu[i][1]+1;
		for(int j=2;j<=n;j++)
		{
			cout<<" "<<stu[i][j]+1;
		}
		cout<<endl;
	}
	return 0;
}
