
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int_64;
//    a=x1*x2
//    b=x1+x2
//    a/b = asim/bsim + somehow/b

int_64 a=0, b=0, ans=0;
/*
void simpl(int_64 a,int_64 b) //gcd 4 simplify
         {
                  int_64 tmp = a % b;
                  a = b;
                  b = tmp;
         }
*/
int main()
{
    cin >> a >> b;
    if(a==1 && b==1)
                  {
                   printf("1");
                   return 0;
                  }
    else while(b!=0)
    {
         ans += a/b;
         //simpl(a,b);
         //cout<<ans<<endl;
         //test
         {
                  int_64 tmp = a % b;
                  a = b;
                  b = tmp;
         }
    }
    
    cout << ans << endl;
    return 0;
}
