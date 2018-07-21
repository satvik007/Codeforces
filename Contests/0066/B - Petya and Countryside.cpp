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

    vi l(n, 1);
    vi r(n, 1);

    for(int i = 1; i < n; i++) {
        if(a[i - 1] <= a[i]) l[i] += l[i - 1];
    }
    for(int i = n - 2; i >= 0; i--) {
        if(a[i + 1] <= a[i]) r[i] += r[i + 1];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, l[i] + r[i] - 1);
    }

    cout << ans << "\n";
}