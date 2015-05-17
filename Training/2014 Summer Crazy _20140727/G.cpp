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
typedef __int64 ll;
ll a[105];
int main()
{
	int i,n;
    while(scanf("%d",&n)!=EOF)
	{
		ll sum=0;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) sum+=i*(a[i]-1)+1;
        cout<<sum;
    }
    return 0;
} 

