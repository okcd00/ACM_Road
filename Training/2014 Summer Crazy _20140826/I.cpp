#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;    scanf("%d %d", &n, &m);
    if (m == 3)
    {
        if (n == 3)
        	printf("0 0\n0 1\n1 0\n");
        else if (n == 4)
        	printf("0 0\n0 10\n10 0\n1 1\n");
        else 
			printf("-1\n");
		return 0;
    }
    
    for (int i = 1; i <= m; ++ i)
        printf("%d %d\n", i, -(n-i) * (n-i));
    for (int i = 1; i <= n - m; ++ i)
        printf("%d %d\n", -i, (n-i) * (n-i));
	return 0; 
}
