#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <stack> //Add stack
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

int powr(int x, int n)
{
    int result;
    if (n == 0)
        return 1;
    else
    {
        while ((n & 1) == 0)
        {
            n >>= 1;
            x *= x;
        }
    }
    result = x;
    n >>= 1;
    while (n != 0)
    {    
        x *= x;
        if ((n & 1) != 0)
            result *= x;
        n >>= 1;
    }
    return result;
}

int main()
{
    int a=0,b=0;
    RD(a);RD(b);
    if(a==0){printf("%d",b*b);while(--b)printf("x");return 0;}
    if(b==0){printf("%d",a*a);while(--a)printf("o");return 0;}
    
 

    return 0;
}
