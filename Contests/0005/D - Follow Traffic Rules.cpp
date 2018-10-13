// lose small or win big.
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

double f(double sv, double ev, double mv, double dist, double a) {
    double min_dist = (ev * ev - sv * sv) / (2 * a);
    if(dist > min_dist) {
        double vp = sqrt((2 * a * dist + sv * sv + ev * ev) / 2);
        if(vp > mv) {
            double d1 = (mv * mv - sv * sv) / (2 * a);
            double d2 = (mv * mv - ev * ev) / (2 * a);
            double d = dist - d1 - d2;
            return (mv - sv) / a + (mv - ev) / a + d / mv;
        } else {
            return (vp - sv) / a + (vp - ev) / a;
        }
    } else {
        return (ev - sv) / a;
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(8);

    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;

    double mid = min(min(w, v), sqrt(2 * a * d));
    double end = min(v, sqrt(mid * mid + 2 * (l - d) * a));
    double ans1 = f(0, mid, v, d, a);
    double ans2 = f(mid, end, v, l - d, a);
    double ans = ans1 + ans2;
    cout << ans << "\n";

}