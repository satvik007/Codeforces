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

    int n, m;
    cin >> n >> m;

    vi l(m), r(m), t(m), c(m);

    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> t[i] >> c[i];
    }

    vi ar(n + 1, -1);
    vi ti(n + 1, INF);

    for(int i = 0; i < m; i++) {
        for(int j = l[i]; j <= r[i]; j++) {
            if(ti[j] > t[i]) {
                ti[j] = t[i];
                ar[j] = i;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ar[i] != -1) {
            ans += c[ar[i]];
        }
    }

    cout << ans << "\n";


}