#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll p, x, m;
    int ans;
    bool flag;
    while(scanf("%I64d", &p) != EOF)
    {
        ans = 0;
        for(x = 1; x < p; x++)
        {
            m = 1;
            flag = true;
            for(int i = 1; i < p - 1; i++)
            {
                m *= x;
                m %= p;
                if((m - 1) % p == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag && ((m * x) - 1) % p == 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
