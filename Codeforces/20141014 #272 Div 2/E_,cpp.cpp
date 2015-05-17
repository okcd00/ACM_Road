#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>

#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <string>

using namespace std;

const int MAX_SIZE = 2100;

string s, t;
int a [MAX_SIZE];
int d [MAX_SIZE][MAX_SIZE];

int main () {
    cin >> s >> t;
    int n = (int) s.size (), m = (int) t.size ();
    for (int i = 0; i < n; ++ i) {
        int size = 0;
        int j = i;
        while (j < n && size < m) {
            if (s [j] != t [size]) {
                ++ j;
            } else {
                ++ j;
                ++ size;
            }
        }
        if (size == m) {
            a [i] = j - i + 1;
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            d [i + 1][j] = max (d [i + 1][j], d [i][j]);
            d [i + 1][j + 1] = max (d [i + 1][j + 1], d[i][j]);
            if (a [i]) {
                d [i + a [i] - 1][j + a [i] - m - 1] = max (d [i][j] + 1, d [i + a [i] - 1][j + a [i] - m - 1]);
            }
        }
    }
    for (int i = 0; i <= n; ++ i) {
        cout << d [n][i] << " ";
    }
    cout << endl;
    return 0;
}
