#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 500000 + 100;

int n;
int a[maxn], b[maxn], bs[maxn];
vector<int> c[maxn];
int id[maxn];
set<int> s;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	copy(a, a+n, b);
	copy(a, a+n, bs);
	sort(bs, bs+n);
	int nn = unique(bs, bs+n) - bs;
	rep(i, n) b[i] = lower_bound(bs, bs+nn, b[i]) - bs;

	rep(i, n) id[i] = sz(c[b[i]]), c[b[i]].pb(i);

	int e = n, op = -1;
	rep(i, n) {
		if(i == e) {
			ans.pb(a[op]);
			ans.pb(a[i]);
			ans.pb(a[op]);
			ans.pb(a[i]);
			s.clear();
			e = n;
			continue;
		}
		vector<int> &v = c[b[i]];
		if(id[i]+1 == sz(v)) continue;
		while(sz(s) && *s.begin() <= i) {
			int t = *s.begin();
			s.erase(s.begin());
			if(id[t]+1 < sz(c[b[t]]))
				s.insert(c[b[t]][id[t]+1]);
		}
		int p = -1;
		if(sz(s)) p = *s.begin();
		s.insert(v[id[i]+1]);
		if(p == -1) continue;
		int ed = upper_bound(all(v), p) - v.begin();
		if(ed != sz(v)) {
			ed = v[ed];
			smin(e, ed);
			if(e == ed) op = p;
		}
	}

	cout << sz(ans) << endl;
	rep(i, sz(ans)) cout << ans[i] << ' ';
	cout << endl;

	return 0;
}