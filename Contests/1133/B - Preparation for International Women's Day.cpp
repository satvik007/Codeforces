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

    int n, k;
    cin >> n >> k;

    vi a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <vi> b (k);
    for (int i = 0; i < n; i++) {
        b[a[i] % k].push_back (a[i]);
    }

    int ans = 0;
    for (int i = 0; i <= k / 2; i++) {
        if (!i or 2 * i == k) {
            ans += 2 * (b[i].size() / 2);
        } else {
            ans += 2 * min (b[i].size(), b[k - i].size());
        }
    }

    cout << ans << "\n";

}