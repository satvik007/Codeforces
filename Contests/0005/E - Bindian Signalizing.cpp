// lose small or win big.
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

    int n;
    cin >> n;

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    rotate(a.begin(), max_element(a.begin(), a.end()), a.end());
    a.push_back(a[0]);

    vi l(n + 1), r(n + 1), c(n + 1);

    c[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        r[i] = i + 1;
        while(r[i] < n and a[i] > a[r[i]]) r[i] = r[r[i]];
        if(r[i] < n and a[i] == a[r[i]]) {
            c[i] = c[r[i]] + 1;
            r[i] = r[r[i]];
        }
    }

    for(int i = 0; i < n; i++) {
        l[i] = i - 1;
        while(l[i] >= 0 and a[i] >= a[l[i]]) l[i] = l[l[i]];
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += c[i];
        if (a[i] != a[0]) {
            ans += 2;
            if(l[i] == 0 and r[i] == n) ans--;
        }

    }
    cout << ans << "\n";

}