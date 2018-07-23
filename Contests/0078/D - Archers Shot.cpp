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

const int INF = (int)1e9;

#define maxn 100010



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    ll n;
    cin >> n;

    function <bool(ll, ll)> f = [&](ll u, ll v) {
        //cout << "func = " << u << " " << v << "\n";
        return (u * u + 3 * v * v <= 4 * n * n + 1e-9);
    };

    ll ans = 0;
    for(int i = 1, j = 0; (i + 1) / 2 <= n; i += 3, j++) {

        ll lo = 1, hi = n, c = 0, mid;

        if (j % 2) {
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (f(i, 2 * mid) and f(i + 1, 2 * mid - 1)) {
                    lo = mid + 1;
                    c = max(c, mid);
                } else {
                    hi = mid - 1;
                }
            }
            ans += 2 * c;
            if(j) ans += 2 * c;
        } else {
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (f(i, 2 * mid - 1) and f(i + 1, 2 * mid - 2)) {
                    lo = mid + 1;
                    c = max(c, mid);
                } else {
                    hi = mid - 1;
                }
            }
            ans += max(2 * c - 1, 0LL);
            if(j) ans += max(2 * c - 1, 0LL);
        }
        //cout << j << " " << c << "\n";
    }

    cout << ans << "\n";

}