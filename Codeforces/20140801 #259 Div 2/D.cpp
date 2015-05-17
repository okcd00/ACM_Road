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
int a[101]={0};
int b[101]={0};
int pri[18]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,49,53};
int mrk[60]={0}  

int main()
{
	int n;	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	
	
}
