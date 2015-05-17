#include <cmath> 
#include <queue>
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

int n=0, ct=0, a[100086]={0}, b[100086]={0};

int main() 
{
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n; i>=0; i-=2) 
	{
        if(a[i] == a[i-1]) b[ct++]=a[i];
        else 
		{
            if(a[i]-a[i-1] == 1) b[ct++]=a[i-1];
            else ++i;
        }
    }
    ll ans=0;
    for(int i=0;i<=ct-1;i+=2) ans+=(ll)b[i]*b[i+1];
    cout<<ans;
    return 0;
}
