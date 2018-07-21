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

    int ans = 0;

    multiset <int> set1;

    for(int i = 0; i < n; i++) {
        if(a[i] % 2) {
            set1.insert(a[i]);
        } else {
            ans += a[i];
        }
    }


    if(set1.size() == 0) {
        cout << 0 << "\n"; return 0;
    }

    if(set1.size() % 2) {
        for(auto it = set1.begin(); it != set1.end(); ++it) {
            ans += *it;
        }
    } else {
        for(auto it = next(set1.begin()); it != set1.end(); ++it) {
            ans += *it;
        }
    }

    cout << ans << "\n";

}