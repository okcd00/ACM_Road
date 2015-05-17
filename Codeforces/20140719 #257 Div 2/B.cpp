#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int main()
{
	ll x,y,n;
	cin>>x>>y;
	cin>>n;
	ll ans[6];
	//ll ans[6]={y-x,x,y,y-x,-x,y-2*x};  //-y
	ans[1]=(x+mod)%mod;
    ans[2]=(y+mod)%mod;
    ans[3]=(ans[2]-ans[1]+mod)%mod;
    ans[4]=(-x+mod)%mod;
    ans[5]=(-y+mod)%mod;
    ans[0]=(ans[1]-ans[2]+mod)%mod;
	cout<<(ans[n%6]%mod+mod)%mod;
	return 0;
}
