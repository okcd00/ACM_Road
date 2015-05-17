#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define RD(a) scanf("%d",&a)
#define PT(a) printf("%d",a)


using namespace std;

int main()
{
    int n=0,p=0,k=0;
    RD(n);RD(p);RD(k);
    int l=(p-k>1)?(p-k):1;
    int r=(p+k<n)?(p+k):n;
    if(l!=1) printf("<< ");
    while(l<p) {
                        printf("%d ",l);
                        l++;
                  }
    printf("(%d) ",p);
    while(p<r){   
                      p++;
                      printf("%d ",p);
                  }
    if(r!=n)printf(" >>");
      
    return 0;

}
