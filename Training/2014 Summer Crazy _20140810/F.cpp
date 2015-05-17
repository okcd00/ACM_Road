#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;
bool vis[100005];
int  p[100005], q[100005];
char s[100005], str[16][4];

int main()
{
    int i, j, k, t, x, y;
    while( ~scanf("%s", s) )
    {
    	scanf("%d", &k);
        int len = strlen(s);
        for(i = 0; i < k; i++) scanf("%s", str[i]);
        for(i = 0; i < k; i++) for(j = 0; j < len; j++)
        {
        	x = y = 0;
            while(s[j] == str[i][0] || s[j] == str[i][1] && j < len) 
        		s[j++] == str[i][0] ? x++ : y++;
            ans += x < y ? x : y;
        }
        printf("%d\n", ans);
    }
    return 0;
}
