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

    int n;
    cin >> n;

    vi a(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll m1 = LONG_LONG_MAX;
    ll v = 0;
    for(int i = 0; i < n; i++) {
        v += a[i] - b[i];
        m1 = min(m1, v);
    }
    set <int> ans;
    for(int i = 0; i < n; i++) {
        m1 -= (a[i] - b[i]);
        if(m1 >= 0) ans.insert((i + 1) % n);
    }

    reverse(a.begin(), a.end());

    rotate(b.begin(), b.end() - 1, b.end());

    reverse(b.begin(), b.end());

    m1 = LONG_LONG_MAX;
    v = 0;
    for(int i = 0; i < n; i++) {
        v += a[i] - b[i];
        m1 = min(m1, v);
    }

    for(int i = 0; i < n; i++) {
        m1 -= (a[i] - b[i]);
        if(m1 >= 0) ans.insert((n - i - 2 + n) % n);
    }

    cout << ans.size() << "\n";
    for(auto el: ans) cout << el + 1 << " "; cout << "\n";


}