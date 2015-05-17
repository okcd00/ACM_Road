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

int num[1024]={0};
map<int,int> mii;

int main()
{
	int cases=0,flag;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		flag=0;
		mii.clear();
		memset(num,0,sizeof num);
		int n,k;	scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			mii[num[i]]++;
		}
		//sort(num,num+n);
		for(int i=1;i<=n;i++)
		{
//			for(int j=0;j<n;j++)
//			cout<<j<<":"<<mii[j]<<" ";
//			cout<<flag<<endl;
			if(mii[i])	
			{	mii[i]--;	continue;	}
			else
			{
				int have=0,ii=i;
				while(ii>0)
				{
					if(mii[ii])
					{
						mii[ii]--;
						have=1;	break;
					}
					else ii-=k;
				}
				if(have) continue;
				else
				{
					flag=1;	//Tom
					break;
				}
			}
		}
//		cout<<flag<<endl;
		if(flag) cout<<"Tom"<<endl;
		else cout<<"Jerry"<<endl;
	}
	return 0;
}
