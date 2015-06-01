#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct testBag
{

}test[1024];

int cmp(const void *_a, const void *_b)
{
    struct testBag *a =(testBag *)_a;
    struct testBag *b =(testBag *)_b;
    return a->e > b->e;
}

int main()
{
    cout<<"Hello World"<<endl;
    return 0;
}
