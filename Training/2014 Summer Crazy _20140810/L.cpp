#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int aval[1001];

bool cmp(const int a, const int b){return a > b;}

int main()
{
	int n;	cin>>n; 
	int points=0, ops=0, a=0, b=0, cnt=1, c=0;
	memset(aval,0,sizeof aval);
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(b==0) aval[c]=a,c++;
		else cnt+=(b-1),points+=a;
	} 
	sort(aval,aval+c,cmp);
	for(int i=0;i<c && cnt!=0;i++)
	{
		points+=aval[i];
		cnt--;
	}
	cout<<points;
	return 0;
}
