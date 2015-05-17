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

int vit[666]={0};
int lgt[666]={0};	//degree of light

int main()
{	
	int c=0;
	int m,t,r;	cin>>m>>t>>r;
	if(t<r) {cout<<-1;return 0;}
	for(int i=1;i<=m;i++)
		scanf("%d",&vit[i]);
	int now=1;
	for(int i=1;i<=300;i++)
	{
		lgt[i]+=lgt[i-1];
		if(i==vit[now])
		{
			if(lgt[i]!=r)
			{
				int dec=r-lgt[i];
				c+=dec;
				for(int vt=i+t;i+t-vt<dec;vt--)
				{
					//cout<<"decing..."<<endl;
					lgt[vt]--;
				}
				lgt[i]=r;
			}
			now++;
		}
		//cout<<"lgt["<<i<<"]:"<<lgt[i]<<endl;
	} 
	cout<<c;
	return 0;
}
