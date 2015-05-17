#include <iostream>
#include <algorithm>
using namespace std;

int i, n, d, a[100009], b[100009], c[100009], aPoz[100009];
long long x;

long long getNextX() 
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() 
{
    for(i = 0; i < n; i = i + 1)
        a[i] = i + 1;
    for(i = 0; i < n; i = i + 1)
        swap(a[i], a[getNextX() % (i + 1)]);
    for(i = 0; i < n; i = i + 1)
        if (i < d)      b[i] = 1;
        else            b[i] = 0;
    for(i = 0; i < n; i = i + 1)
        swap(b[i], b[getNextX() % (i + 1)]);
}

int main()
{
    cin >> n >> d >> x;
    initAB();
    
    for (int i = 0; i < n; ++i)
        aPoz[a[i]] = i + 1;
    int bcnt = -1;
    for (int i = 0; i < n; ++i)
        if (b[i])
            b[++bcnt] = i;
        
    int n2 = n; 
    for (int i = 100000; i > 0; --i)
        if (aPoz[i])
        {
            for (int j = 0; j <= bcnt; ++j)
            {
                if (aPoz[i] + b[j] > n2) break;
                if (!c[aPoz[i] + b[j]])
                    c[aPoz[i] + b[j]] = i;
            }
            while (c[n2]) --n2;
        }
    for (int i = 1; i <= n; ++i)
        cout << c[i] << endl;   
        
return 0;
}
