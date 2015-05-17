#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

const int size = 2 * 1000 * 1000 + 10;
const int ssize = 21;

char buf[size];
char nbuf[size];

int n=0, m=0;
int pwr[ssize][size];

void combine(int* tg, int* a, int* b, int shift) 
{
    for (int i = 0; i < n; i++) 
	{
        if (a[i] < shift) tg[i] = a[i];
        else tg[i] = b[a[i] - shift] + shift;
    }
}

int main() 
{
    scanf("%s", buf); n = strlen(buf);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) 
	{
        int k, d;
        scanf("%d%d", &k, &d);
        int num = n - k + 1, cur = 0;
        for (int j = 0; j < d; j++) 
		{
            int p = j;
            while (p < k) 
			{
                pwr[0][p] = cur++;
                p += d;
            }
        }
        for (int j = k; j < n; j++)	pwr[0][j] = j;
        int lim = 0, vl = 1;
        while (vl <= num) 
		{
            vl *= 2;
            lim++;
        }
        for (int j = 1; j < lim; j++) 
            combine(pwr[j], pwr[j - 1], pwr[j - 1], (1 << (j - 1)));
        for (int j = 0; j < n; j++) 
		{
            int ps = j;
            int vl = num;
            int sh = 0;
            for (int h = lim - 1; h >= 0; h--)
                if (vl >= (1 << h)) 
				{
                    if (ps >= sh)	ps = pwr[h][ps - sh] + sh;
                    vl -= (1 << h);
                    sh += (1 << h);
                }
            nbuf[ps] = buf[j]; 
        }
        for (int j = 0; j < n; j++)	buf[j] = nbuf[j];
        printf("%s\n", buf);
    }

    return 0;
}
