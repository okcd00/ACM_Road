#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int fst[101];
int scd[101];

int main()
{
	int n;	cin>>n;
	char c;	scanf("%c",&c); //huiche
	memset(fst,0,sizeof fst);
	memset(scd,0,sizeof scd);
	rep(i,0,n)
	{
		scanf("%c",&c);
		fst[i]=c-'0';
	} 
	rep(j,0,n)
	{
		scanf("%c",&c);
		scd[j]=c-'0';
	}
	sort(fst,fst+n);
	sort(scd,scd+n);
	if(fst[0]==scd[0]){puts("NO");return 0;}
	bool flag= (fst[0]>scd[0]?true:false);
	rep(k,1,n)
	{
		if(flag && fst[k]<=scd[k]) {puts("NO");return 0;}
		else if(!flag && fst[k]>=scd[k]){puts("NO");return 0;}
	} 
	puts("YES");
	return 0;
}
