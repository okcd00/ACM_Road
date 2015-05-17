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
ll ans=0;

int num[300033];
bool cmp(const int a, const int b){return a > b;}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		ans+=num[i];
	}
	sort(num,num+n,cmp);
	ans-=num[0];
	for(int i=0;i<n;i++)
	{
		ans+=(ll)num[i]*(ll)(n-i);
	}
	printf("%I64d",ans);
	return 0;
} 
