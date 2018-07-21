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

#define maxn 100010

const double g = 9.8;
#define PI acos(-1)

struct Wall {
    double x, y;
};

bool operator < (Wall e, Wall f) {
    return e.x < f.x;
}

int n;
double v;
vector <double> al;
int m;
vector <Wall> wa;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> v;
    al.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> al[i];
    }

    cin >> m;
    wa.resize(m);

    for(int i = 0; i < m; i++) {
        cin >> wa[i].x >> wa[i].y;
    }

    // sorting on the basis of x coordinates.
    sort(wa.begin(), wa.end());

    vector <double> l(m); // minimum angle needed for the walls bottom.
    vector <double> h(m); // max angle needed for the walls top. will be pi / 4 if wall is too hi.

    double maxd = v * v / g; // max horizontal distance.
    double maxa = PI / 4; // max allowed angle.

    for(int i = 0; i < m; i++) {
        if(wa[i].x > maxd - 1e-9) { // wall is too far away.
            l[i] = INF;
            h[i] = INF;
            continue;
        }
        // solving the y vs x equation y = x tan (th) - g * x * x / (2 * u ^ 2 cos (th) ^ 2) for theta.
        double k = g * wa[i].x * wa[i].x / (2 * v * v);
        l[i] = asin(g * wa[i].x / (v * v)) / 2;
        double maxh = wa[i].x - g * wa[i].x * wa[i].x / (v * v); // got this expression by diff the y - x equation wrt theta.
        double d = wa[i].x * wa[i].x - 4 * k * (k + wa[i].y);
        if(wa[i].y >= maxh) { // if wall is too hi using the max allowed angle.
            h[i] = PI / 4;
        } else {
            assert(d > 0);
            h[i] = atan((2 * (k + wa[i].y)) / (wa[i].x + sqrt(d)));
            assert(l[i] <= h[i] + 1e-9);
        }
    }

    for(int i = 1; i < m; i++) {
        h[i] = max(h[i], h[i - 1]);
    }
    // doing this so that if a previous wall was hit it will come in binary search.

    for(int i = 0; i < n; i++) {
        int lo = 0, mid, hi = m - 1, j = hi;
        while(hi >= lo) {
            mid = (lo + hi) / 2;
            if(h[mid] >= al[i]) {
                j = min(j, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if(l[j] <= al[i] && h[j] >= al[i]) {
            // y - x equation.
            double dist = wa[j].x * tan(al[i]) - g * wa[j].x * wa[j].x / (2 * pow(v * cos(al[i]), 2));
            cout << wa[j].x << " " << dist << "\n";
        } else {
            // range equation.
            double dist = v * v * sin(2 * al[i]) / g;
            cout << dist << " " << 0.0 << "\n";
        }
    }

}