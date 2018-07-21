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

    int n, m;
    cin >> m >> n;

    vector <ii> a(n);

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = {v, u};
    }

    sort(a.begin(), a.end(), greater <ii> ());

    ll cnt = 0;

    for(int i = 0; i < n && m; i++) {
        if(a[i].second >= m) {
            cnt += a[i].first * (ll)m;
            m = 0;
        } else {
            cnt += a[i].first * (ll) a[i].second;
            m -= a[i].second;
        }
    }

    cout << cnt << "\n";



}