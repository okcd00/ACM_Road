#include <cstdio>
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        int a=n%4 ,b=n/4;
        for(i = 0; i < b; i++) printf("abcd");
        for(i = 0; i < a; i++) printf("%c",i+'a');
        printf("\n");
    }
    return 0;
}
