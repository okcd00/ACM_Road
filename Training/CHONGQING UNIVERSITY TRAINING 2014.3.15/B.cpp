#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int n=(a+b+c)/2;
	if ((a+b+c)%2==1) {
						printf("Impossible");
						return 0;
						}
	if((n==c)&&(n==a)||(n==a)&&(n==b)||(n==b)&&(n==c))
                                                      {
						                               printf("Impossible");
						                               return 0;
                                                       }
    if((n<c)||(n<a)||(n<b))
                                                       {
						                               printf("Impossible");
						                               return 0;
                                                       }
	printf("%d %d %d",n-c,n-a,n-b);
	return 0;
}
