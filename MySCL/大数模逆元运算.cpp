#include<cmath>    
#include<cstdio>    
#include<string>    
#include<vector>    
#include<cstring>    
#include<iostream>    
#include<algorithm>    
using namespace std;    
typedef long long ll;    
const ll lim=1000000007;  //lim := vmod  
    
ll Jval[2000001];  
void Jc_init() //初始化阶乘值的数组    
{    
    Jval[0]=1;    
    for(int i=1;i<=2000000;i++)    
    Jval[i]=(i*Jval[i-1])%lim;    
}    
    
//三元组gcd(a,b) == ax +by == d;       
struct gcdstruct //定义结构体存储(_Ni的计算)  
{       
        ll d;      
        ll x;      
        ll y;      
};      
gcdstruct EXTENDED_EUCLID(ll a,ll b)  //EUCLID算法    
{      
    gcdstruct aa,bb;      
    if(b==0)  
    {  
        aa.d = a;      
        aa.x = 1;      
        aa.y = 0;      
        return aa;      
    }      
    else  
    {      
        bb = EXTENDED_EUCLID(b,a%b);       
        aa.d = bb.d;      
        aa.x = bb.y;      
        aa.y = bb.x - bb.y * (a/b);      
    }      
    return aa;      
}       
        
ll _Ni(ll a,ll m)  //获得a对m的模逆元    
 {      
      ll x;      
      gcdstruct aa;      
      aa = EXTENDED_EUCLID(a,m);      
      return aa.x;      
}         
    
    
ll C(ll n,ll m) //获得C(n,m) 的组合数结果 := n!/((n-m)!*m!)  
{     
    ll  Cans=   (   Jval[n]*_Ni(Jval[m],lim) +lim   ) %lim;  // Get n!/m!   
        Cans=   (   Cans*_Ni(Jval[n-m],lim) +lim   ) %lim;      // Get Cans/(n-m)!   
    return (Cans+lim)%lim ;     
}    
  
int main()    
{    
    int T=0;    scanf("%d",&T);   
    ll n=0,m=0;     Jc_init();     
    for(int cnt=1;cnt<=T;cnt++)     
    {    
        scanf("%I64d%I64d",&n,&m);    
        printf("Case #%d: \n",cnt);  
        cout<<"===<Jval>===\n n!="<<Jval[n]<<"; m!="<<Jval[m]<<endl;  
        cout<<"===<_Ni>===\n m!^-1="<<_Ni(Jval[m],lim)  
                    <<"; (n-m)!^-1="<<_Ni(Jval[n-m],lim)<<endl;  
        printf("C(%d,%d) = %I64d (Mod lim)\n",n,m,C(n,m));    
    }    
        
    return 0;    
} 
