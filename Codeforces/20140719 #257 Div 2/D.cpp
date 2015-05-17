#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 1e18
using namespace std;
typedef long long ll;

int a[100000];
ll  d[100000];
vector <pair<int, int> > v[100000];

int main()
{
    int n, m, k, ans = 0, i;
    cin>>n>>m>>k;
    priority_queue <pair<ll, int> > q;	//Priority_queue can make it a big-root heap
    									//priority_queue<int, vector<int>, greater<int> > q; is small-root heap
    for (i = 0; i < n; i++) d[i] = INF;
    for (i = 0; i < m; i++) 
	{
        int x, y, z;    
        cin>>x>>y>>z;
        x--,y--;

        v[x].push_back(make_pair(y, z));//vector for saving routes	
        v[y].push_back(make_pair(x, z));//double_direction
    }
    
    for (i = 0; i < k; i++) 
	{
        int x, y;    
        cin>>x>>y;
        x--;
        
        d[x] = min(d[x], (ll)y);
        q.push(make_pair(-y, -x));
    }
    
    d[0] = 0;
    q.push(make_pair(0, 0));
    
    while (!q.empty()) 
	{
        ll x = -q.top().first;
        int y = q.top().second;
        q.pop();
    
        if (y < 0) 
		{
            y = -y;    
            if (a[y] == 1) ans++;
        }
        
        if (a[y] == 1) continue;
        
        a[y] = 1;
        
        for (i = 0; i < v[y].size(); i++) 
		{
            if (d[v[y][i].first] >= x + v[y][i].second) 
			{
                d[v[y][i].first] = x + v[y][i].second;
                q.push(make_pair(-d[v[y][i].first], v[y][i].first) );
            }
        }
    }
    cout<<ans;
    return 0;
}
