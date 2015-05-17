#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;

int amt[27];
bool cmp(const int a, const int b){return a > b;}

int main()
{
	char c;
	int n,k;	cin>>n>>k;
	scanf("%c",&c);	//huiche
	memset(amt,0,sizeof amt);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		amt[(c-'A')]++;
	}
	sort(amt,amt+26,cmp);
	//for(int i=0;i<26;i++)cout<<amt[i]<<endl;
	ll ans=0;
	for(int i=0;i<26;i++)
	{
		if(k>=amt[i]) 
		{
			ans+=(ll)amt[i]*(ll)amt[i];
			k-=amt[i];
		}
		else
		{
			ans+=(ll)k*(ll)k;
			k=0;
		}
		
		if(k==0)
		{
			printf("%I64d",ans);
			return 0;
		}
	}
	return 0;
} 
