#include<cstdio>
using namespace std;
int main()
{
	char str[4];
	int n=0, x=0; scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);
		x+= (str[1]=='+'?1:-1);
	}	printf("%d", x);
	return 0;
}
