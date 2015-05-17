#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int Jc[12];
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

void Jc_init()
{
	Jc[1]=Jc[0]=1;
	for(int i=2;i<12;i++)
		Jc[i]=Jc[i-1]*i;
}

double C(int n,int m)
{
	double ret=1.0;
	for(int i=1;i<=n;i++)	ret/=2.0;
	ret= ret*(double)Jc[n]/(double)Jc[m]/(double)Jc[n-m];
	return ret;
}


int main()
{
	string s1,s2;
	cin>>s1>>s2;
	double rate=0.0;
	int pos1=0,pos2=0,unc=0;
	Jc_init();
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]=='+')pos1++;
		else pos1--;
		if(s2[i]=='+')pos2++;
		else if(s2[i]=='-') pos2--;
		else unc++;
	}
	int pos=abs(pos2-pos1);
	if(pos<=unc)
	{
		int res=unc-pos;
		if(res%2==0)
		{
			int need=res/2+pos;
			rate=C(unc,need);
		}
	}
	printf("%.12f",rate);
	return 0;
}
