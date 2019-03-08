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

    vi a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort (a.begin(), a.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cnt = upper_bound (a.begin(), a.end(), a[i] + 5) - a.begin() - i;
        ans = max (ans, cnt);
    }


    cout << ans << "\n";


}