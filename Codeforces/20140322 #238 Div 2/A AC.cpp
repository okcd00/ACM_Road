#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int blk[101];
    for(int i=0;i<n;i++)    scanf("%d",&blk[i]);
    sort(blk,blk+n);
    printf("%d",blk[0]);
    for(int i=1;i<n;i++)    printf(" %d",blk[i]);
    return 0;
}
