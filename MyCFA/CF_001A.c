#include<cstdio>    
int main()    
{    
    long m, n, a;    
    long i = 1, j = 1;           
    scanf("%ld %ld %ld",&m, &n, &a);    
    while(i * a < m)  i++;    
    while(j * a < n)  j++;    
    printf("%I64d\n", (long long)i * j);    
    return 0;    
}    
