#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];


int main()
{
	int n;	cin>>n;
	memset(a,0,sizeof a); 
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])continue;
		if(a[i]<a[i-1]*2)
		{
			cout<<"YES"<<endl;
			return 0; 
		}
	}
	cout<<"NO"<<endl;
	
	return 0;
} 
