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
const ll lim=(ll)1e9+7;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int main(){
    ll n,a,b;
    const ll mod=1000000007;
    scanf("%I64d%I64d",&a,&b);
    if(b==1){printf("0\n");return 0;}
    ll fa,fb,an=(b+1+b*a+1)*a/2;
    ll ans=((a*(a+1)/2)%mod*b+a)%mod;
    ans=ans*((b*(b-1)/2)%mod)%mod;
    printf("%I64d\n",ans);
    return 0;
}