#include <iostream>  
#include <cstdio>  
#include <algorithm>  
using namespace std;  
  
  
int main()  
{  
    int n,p1,p2,p3,t1,t2 ;  
    int l,r,l2,r2;  
    scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);  
    scanf("%d%d", &l, &r);  
    int sum = (r - l) * p1;  
    while(--n)  
    {  
        scanf("%d%d",&l2,&r2);  
        int mid = l2 - r ;  
        int p1pow = t1 * p1, p2pow = t2 * p2;  
        if (mid <= t1)  
            sum += mid * p1;  
        else  
        {  
         sum += p1pow;  
         mid -= t1;  
         if (mid <= t2)  
            sum += mid * p2;  
         else  
            sum += p2pow + (mid - t2) * p3;  
        }  
        sum += (r2 - l2) * p1;  
        l = l2;  
        r = r2;  
    }  
     printf("%d",sum);    
     return 0;  
}  
