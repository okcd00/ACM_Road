#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define inf 0x7f7f7f7f
#define N 505
#define update(x) u=min(u,x)
int dp[N][N][55],a[N],b[N],la,lb;
char s[N],p[N];
int i, j, k, u; //loop-varieties

void init()
{
	for(i=1;s[i];i++) if(islower(s[i]))a[i] = s[i]-'a'; else a[i] = s[i]-'A'+26;
	for(i=1;p[i];i++) if(islower(p[i]))b[i] = p[i]-'a'; else b[i] = p[i]-'A'+26;
	memset(dp, inf, sizeof dp);
	la = strlen(s+1), lb = strlen(p+1);
	
	dp[0][0][52] = 0;
}

void dp_update()
{
	update(dp[i-1][j][k] +1);
	update(dp[i][j-1][k] +1);
	update(dp[i-1][j-1][k] +1);
	dp[i][j][b[j]] = min(dp[i][j][b[j]], dp[i-1][j-1][k]+1);
}

int main()
{
	while(scanf("%s",s+1),s[1]!='#')
	{
		scanf("%s",p+1);
		init();
		for(i = 1; i <= la; i++)	dp[0][i][52] = dp[i][0][52] = i;
		for(i = 1; i <= la; i++)
		{
			for(j = 1; j <= lb; j++)
			{
				for(k = 0; k < 52; k++)
				{
					u = inf;
					if(b[j]==k)	u = dp[i-1][j-1][k];	else dp_update();
					dp[i][j][k] = min(u, dp[i][j][k]);
				}
				
				u = inf;
				if(a[i]==b[j])	u = dp[i-1][j-1][52];	else dp_update();
				dp[i][j][52] = min(dp[i][j][52], u);
			}
		}

		int ans = 1000000000;
		for(i = 0; i <= 52; i++)ans = min(ans, dp[la][lb][i]);
		cout<<ans<<endl;
    }
	return 0;
}
