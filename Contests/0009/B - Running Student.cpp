// Warten auf das Licht, das nie kommt.
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

int n, x, y;
double vb, vs;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2));
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> vb >> vs;

    vi a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    cin >> x >> y;

    double ans = INF;
    int ind = 0;

    for(int i = 1; i < n; i++) {
        double dis = dist(a[i], 0, x, y);
        double cur = a[i] / vb + dis / vs;
        if(cur < ans + 1e-9) {
            ans = cur;
            ind = i;
        }
    }

    cout << ind + 1 << "\n";

}