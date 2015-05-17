#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int num[10]={0};

ll getv(int x)
{
	ll ans = x;  
    while(ans>=10)	//d(s(x)) 
	{  
        ans = 0;  
        while(x) 	//s(x)
		{  
            ans += x%10;  
            x /= 10;  
        }  
        x = ans;  
    }  
    return ans;  
}

int main()
{
	int n;	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++) num[getv(i)]++,ans-=n/i; //appear times 
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			//ans+=num[i]*num[j]*num[getv(i*j)];
			ans+=(ll)num[i]*(ll)num[j]*num[getv(i*j)];
	cout<<ans;
	return 0;
}
