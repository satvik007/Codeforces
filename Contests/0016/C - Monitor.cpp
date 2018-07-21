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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    ll d = __gcd(x, y);
    x /= d; y /= d;

    if(a < x || b < y) {
        cout << "0 0\n"; return 0;
    }

    if(1.0 * a / b <= 1.0 * x / y) {
        a = (a / x) * x;
        b = a * y / x;
    } else {
        b = (b / y) * y;
        a = b * x / y;
    }

    cout << a << " " << b << "\n";

}