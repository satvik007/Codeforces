/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;

#define EPS 1e-9
#define maxn 100010

struct Data {
    double x, v, m;
};

double tim = 0;

Data a[11];

void collide(int i, int j) {
    double vn1 = ((a[i].m - a[j].m) * a[i].v + 2 * a[j].m * a[j].v) / (a[i].m + a[j].m);
    double vn2 = ((a[j].m - a[i].m) * a[j].v + 2 * a[i].m * a[i].v) / (a[i].m + a[j].m);
    a[i].v = vn1;
    a[j].v = vn2;
};


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, t;
    cin >> n >> t;

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].v >> a[i].m;
    }

    while(tim < t) {
        double left = t - tim;
        double cur = INF;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double dist = a[j].x - a[i].x;
                double relv = a[j].v - a[i].v;
                if(abs(relv) < EPS) continue;
                if(dist / relv < 0 && cur > abs(dist / relv)) {
                    cur = abs(dist/ relv);
                }
            }
        }

        if(cur > left) {
            for(int i = 0; i < n; i++) {
                a[i].x += a[i].v * left;
            }
            break;
        } else {
            for(int i = 0; i < n; i++) {
                a[i].x += a[i].v * cur;
            }
            tim += cur;

            bitset <20> vis;

            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(abs(a[i].x - a[j].x) < EPS && !vis[i]) {
                        collide(i, j);
                        vis[i] = 1;
                        vis[j] = 1;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i].x << "\n";
    }



}