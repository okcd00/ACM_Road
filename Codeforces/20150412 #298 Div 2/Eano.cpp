#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
bool cmp(const int a, const int b)
{
	return a > b;
}
#define rep(i, s, e) for(int i = s; i < e; i ++)

const ll maxN = 200*1000 + 5;
const ll mod = 1000*1000*1000 + 7;

ll a[maxN];
ll b[maxN * 4];
ll c[maxN * 30];

ll cnt[2 * maxN];

main()
{
    ios::sync_with_stdio(0); cin.tie();
    ll n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    ll m; cin >> m;
    rep(i, 0, m) cin >> b[i], b[i] --, cnt[b[i]] ++;
    
    ll x = 0;
    while(x < 4 * m)
    {
	  if(x) x --;
	  rep(i, (x ? 1 : 0), n) c[i + x] = i;
	  rep(i, n, 2 * n - 1) c[i + x] = n - (i - n + 2);
	  x += 2 * n - 1;
    }
    
    ll st = 0, te = n, sum = 0;
    rep(i, 0, n) if(cnt[i] == 0) te --;
    
    ll ans = -1;

    rep(i, 0, x)
    {
	  cnt[c[i]] --;
	  if(st < i) sum += abs(a[c[i]] - a[c[i - 1]]);
	  if(cnt[c[i]] < 0)
	  {
		te ++;
		while(cnt[c[i]] < 0)
		{
		    ll tmp = cnt[c[st]];
		    cnt[c[st]] ++;
		    if(tmp == 0) te ++;
		    else if(cnt[c[st]] == 0) te --;
		    st ++; 
		    if(st <= i) sum -= abs(a[c[st]] - a[c[st - 1]]);
		}
	  }
	  else if(cnt[c[i]] == 0) te --;
	  if(te == 0)
	  {
		if(ans == -1) ans = sum;
		else if(ans != sum) { cout << "-1" << endl; return 0; }
	  }
    }
    cout << ans << endl;	  
    return 0;
}
