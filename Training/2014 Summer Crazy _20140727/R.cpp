#include <list>
#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

struct Node 
{
    int in, out;
    int dout;	//diameter
    Node ()	{in = -1, out = -1;}
};

pii pr;
int n, p;
int a, b, d;
Node v[1001];
vector <int> from, to, vol;

int cmp(const void *a, const void *b)
{
	return (*(int *)b-*(int *)a);
}

pii dfs(int i, int w) 
{
    if (v[i].out == -1)
        return make_pair(i, w);
    return dfs(v[i].out, min(w, v[i].dout));
}

int main() 
{
    cin>>n>>p;
    for(int i = 0; i < p; i++) 
	{
        cin>>a>>b>>d;
        v[b].in = a;
        v[a].out = b;
        v[a].dout = d;
    }

    for (int i = 1; i <= n; i++)
    if (v[i].in == -1 && v[i].out != -1) 
	{
        from.push_back(i);
        pr=dfs(i, v[i].dout);
        to.push_back(pr.first);
        vol.push_back(pr.second);
    }
	int vols=(int)vol.size();    cout<<vols<<endl;
    for (int i = 0; i < vols; i++)    cout<<from[i]<<" "<<to[i]<<" "<<vol[i]<<endl;

    return 0;

} 
