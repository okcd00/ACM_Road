#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = (int)1e6;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int n,prime[N]={0},nump=0;
int isNotPrime[N]={1,1};

bool cmp(const int a, const int b)
{
	return a > b;
}

void getpri()
{
	for(int i=2;i<=N/2;i++)
	{
		if(!isNotPrime[i]) prime[nump++]=i;//cout<<i<<' ';
		for(int j=0;j<nump && i*prime[j]<N;j++)
		{
			isNotPrime[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
}

int main()
{
	cin>>n;
	int pos=1;
	getpri();
	
	for(int i=4;i<=n/2;i++)
	{
		if(i> prime[pos])pos++;
		if(i==prime[pos])continue;
		if(count(prime,prime+55555,n-i)==1)continue;
		else
		{
			cout<<i<<" "<<n-i<<endl;
			return 0;
		}
	}
	
	return 0;
}
