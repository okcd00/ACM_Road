#include <bits/stdc++.h>
using namespace std;
int gem[99999] = {}, dp[35000][500], d, x;

int dfs(int a, int b) {
	if(dp[a][b] + 1) return dp[a][b];
	int res = 0, i, v;
	for(i = -1; i < 2; i++) 
	{
		v = a + d + b + i;
		if(v > 30001 | v <= a) continue;
		res = max(res, dfs(v, b + i));
	}
	return dp[a][b] = res + gem[a];
}

int main() {
	cin >> x >> d;
	while(cin >> x)	gem[x]++;
	memset(dp, -1, sizeof dp);
	cout << dfs(d, 0);
	return 0;
}