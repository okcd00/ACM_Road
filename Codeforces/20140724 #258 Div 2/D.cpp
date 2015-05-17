#include <queue>
#include <cmath> 
#include <memory> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;

string s;
char str[maxn];
int len,f[2][2];
long long ans[2];

int main()
{
    while(scanf("%s",str)==1)
	{
        len=strlen(str);
        memset(f,0,sizeof f);
        memset(ans,0,sizeof ans);
        for(int i=0;i<len;i++)
		{
            f[str[i]-'a'][i%2]++;	 
            ans[0]+=f[str[i]-'a'][1-i%2];
            ans[1]+=f[str[i]-'a'][i%2];
        }
        cout<<ans[0]<<' '<<ans[1]<<endl;
    }
    return 0;
}
