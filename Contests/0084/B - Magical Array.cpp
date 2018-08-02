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

    vi a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0;

    ll ans = 0;

    int last = a[0];
    ll cnt = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != last) {
            ans += (cnt + 1) * cnt / 2;
            last = a[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }

    ans += (cnt + 1) * cnt / 2;

    cout << ans << "\n";


}