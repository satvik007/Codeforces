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

    int n;
    cin >> n;

    vi a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    b[0] = a[0];
    for(int i = 1; i < n; i++) {
        b[i] = b[i - 1] + a[i];
    }

    int cnt = b[n - 1];

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(cnt - b[i] == b[i]) ans++;
    }

    cout << ans << "\n";

}