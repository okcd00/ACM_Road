#include<bits/stdc++.h>
using namespace std;

#define SPEED_UP iostream::sync_with_stdio(false);
#define FIXED_FLOAT cout.setf(ios::fixed, ios::floatfield);
#define rep(i, s, t) for(int (i)=(s);(i)<=(t);++(i))
#define urep(i, s, t) for(int (i)=(s);(i)>=(t);--(i))
#define in_bound(l, r, i) (l)<=(i)&&(i)<(r)
#define PB push_back

typedef long long LL;

const int inf = INT_MAX/2;
const int Maxn = 100000;

int w, h, n;

struct node{
    int x, y, z;
    node(){}
    node(int x, int y, int z):x(x), y(y), z(z){}
};

bool operator < (const node &lhs, const node &rhs) {
    return lhs.z < rhs.z;
}

void solve() {
    priority_queue<node> q1, q2;

    q1.push(node(0, w, w));q2.push(node(0, h, h));
    //vector<int> W, H;
    set<int> V, H;
    char ch;int pos;
    rep(r, 1, n) {
        cin >> ch >> pos;
        node _w = q1.top(), _h = q2.top();
        if (ch == 'H') {
            if (_h.x < pos && pos < _h.y) {
                //cout << 'H' << _h.x << ' ' << pos <<' '<< _h.y << endl;
                q2.pop();
                q2.push(node(_h.x, pos, pos-_h.x));
                q2.push(node(pos, _h.y, _h.y-pos));
            }
            else {
                H.insert(pos);
                //H.PB(pos);
            }
        }
        else {
            if (_w.x < pos && pos < _w.y) {
                //cout << 'V' << _w.x << ' ' << pos << ' ' << _w.y << endl;
                q1.pop();
                q1.push(node(_w.x, pos, pos-_w.x));
                q1.push(node(pos, _w.y, _w.y-pos));
            }
            else {
                V.insert(pos);
                //W.PB(pos);
            }
        }
        while (true) {
            node _w = q1.top();
            set<int>::iterator it = V.lower_bound(_w.x);
            if (it == V.end()) break;
            int tmp = *it;
            if (tmp < _w.y) {
                //cout << 'V' << ' ' << _w.x << ' ' << tmp << ' ' << _w.y << endl;
                q1.pop();
                q1.push(node(_w.x, tmp, tmp-_w.x));
                q1.push(node(tmp, _w.y, _w.y-tmp));
                V.erase(it);
            }
            else
                break;
        }

        while (true) {
            node _h = q2.top();
            set<int>::iterator it = H.lower_bound(_h.x);
            if (it == H.end()) break;
            int tmp = *it;
            if (tmp < _h.y) {
                //cout << 'H' << ' ' << _h.x << ' ' << tmp << ' ' << _h.y << endl;
                q2.pop();
                q2.push(node(_h.x, tmp, tmp-_h.x));
                q2.push(node(tmp, _h.y, _h.y-tmp));
                H.erase(it);
            }
            else
                break;
        }
        LL ans = q1.top().z *1ll * q2.top().z;
        cout << ans << endl;
    }
}

int main() {
    SPEED_UP
    cin >> w >> h >> n;
    solve();
    return 0;
}
