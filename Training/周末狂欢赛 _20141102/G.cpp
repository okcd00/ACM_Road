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

int main()
{
	int n=0,i=0,t=0;	cin>>n;
	n=abs(n);
	if(n==0){cout<<0;return 0;}
	for(i=1;t<n;i++)
		t+=i;	i--;
	//cout<<t<<":"<<i;
	//if(t==n){cout<<i;return 0;}
	//cout<< min(i+(n-t)*2,i+1+(t+i-n)*2);return 0;
	while((t-n)&1) {i++, t+=i;}
	cout<<i;	return 0;
}
