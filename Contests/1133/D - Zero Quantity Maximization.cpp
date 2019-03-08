#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

    int n;
    cin >> n;

    vi a (n), b (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector <ii> c (n);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) {
                cnt++;
            }
            c[i] = {INF, 1};
        } else {
            if (b[i] == 0) {
                c[i] = {0, 0};
            } else {
                int g = __gcd (a[i], b[i]);
                a[i] /= g;
                b[i] /= g;
                c[i] = {a[i], b[i]};
            }
        }
    }

    sort (c.begin(), c.end());

    //for (auto el: c) cout << "(" << el.first << ", " << el.second << ") "; cout << "\n";

    int ans = 0;
    int val = 0;
    ii last = c[0];

    for (int i = 0; i < n; i++) {
        if (c[i].first == INF) {
            break;
        }
        if (c[i] == last) {
            val++;
        } else {
            ans = max (ans, val);
            val = 1;
            last = c[i];
        }
    }
    ans = max (ans, val);

    ans += cnt;

    cout << ans << "\n";

}