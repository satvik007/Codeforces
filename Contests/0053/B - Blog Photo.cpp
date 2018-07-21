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

    ll n, m;
    cin >> n >> m;

    ll f1, s1;
    ll f2, s2;

    ll ans1 = 0, ans2 = 0;

    for(int i = 0; i < 32; i++) {
        ll f = (1LL << i), s;
        if(f > n) break;
        if(m > 1.25 * f) {
            s = f * 1.25;
        } else if(1.0 * m / f < 0.8) {
            break;
        } else {
            s = m;
        }
        if(f * s > ans1) {
            f1 = f, s1 = s;
            ans1 = f * s;
        }
    }

    for(int i = 0; i < 32; i++) {
        ll s = (1LL << i), f;
        if(s > m) break;
        if(n > 1.25 * s) {
            f = s * 1.25;
        } else if(1.0 * n / s < 0.8) {
            break;
        } else {
            f = n;
        }
        if(f * s > ans2) {
            f2 = f, s2 = s;
            ans2 = f * s;
        }
    }

    if(ans1 <= ans2) {
        cout << f2 << " " << s2 << "\n";
    } else {
        cout << f1 << " " << s1 << "\n";
    }

}