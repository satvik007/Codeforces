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

    ll n, d, m, l;

    cin >> n >> d >> m >> l;

    ll f = 0;
    ll s = 0;

    while(s <= (n - 1) * m + l) {
        ll v = s - f;
        if(v > l) break;
        v += ((l - v) / d + 1) * d;
        s = f + v;
        f = s / m * m;
    }

    cout << s << "\n";


}