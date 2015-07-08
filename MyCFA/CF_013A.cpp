#include <cstdio>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/24535363

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
    for(int i=2;i<a;i++)  
    {  
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