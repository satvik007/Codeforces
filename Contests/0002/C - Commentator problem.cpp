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
#define p(x) ((x) * (x))
#define maxn 100010

double x[3], y[3], r[3];
double t[3];

double f (double tx, double ty) {
    for(int i = 0; i < 3; i++) {
        t[i] = sqrt(p(tx - x[i]) + p(ty - y[i])) / r[i];
    }
    double res = 0;
    for(int i = 0; i < 3; i++) {
        res += p(t[i] - t[(i + 1) % 3]);
    }
    return res;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    double tx = 0, ty = 0;

    for(int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i] >> r[i];
        tx += x[i];
        ty += y[i];
    }

    tx /= 3;
    ty /= 3;

    for(double dr = 1; dr > 1e-4; ) {
        if(f (tx + dr, ty) < f (tx, ty)) {
            tx += dr;
        } else if(f (tx - dr, ty) < f (tx, ty)) {
            tx -= dr;
        } else if(f (tx, ty + dr) < f (tx, ty)) {
            ty += dr;
        } else if(f (tx, ty - dr) < f (tx, ty)) {
            ty -= dr;
        } else {
            dr *= 0.7;
        }
    }

    if(f(tx, ty) < 1e-3) {
        cout << tx << " " << ty << "\n";
    }


}