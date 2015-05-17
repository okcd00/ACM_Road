#include <cstdio>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
int gcd(int a, int b)  
{  
    if(a%b==0)return b;  
    return gcd(b,a%b);  
}  
  
int val[11];//1024 in base 2  
  
int main()  
{  
    int a,ans=0;  
    scanf("%d",&a);  
    for(int i=2;i<a;i++)  //只有1000 =-= 想多了…… 
    {  //Bruce Force
        int t=a;//t=temp for a  
        int pos=0;  
        while(t)  
        {  
            int mod=t%i;  
            ans+=mod;  
            t=(t-mod)/i;  
            if(!t) break;  
        }  
        //while(pos>=0)ans+=val[pos--];  
    }  
    int Valgcd=gcd(ans,a-2);  
    printf("%d/%d",ans/Valgcd,(a-2)/Valgcd);  
    return 0;  
}   
