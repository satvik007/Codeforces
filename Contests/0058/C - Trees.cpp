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

    map <int, int> map1;

    for(int i = 0; i < n / 2; i++) {
        map1[a[i] - i]++;
        map1[a[n - i - 1] - i]++;
    }
    if(n % 2) map1[a[n / 2] - n / 2]++;

    int ans = n;

    for(auto el: map1) {
        if(el.first > 0) {
            ans = min(ans, n - el.second);
        }
    }

    cout << ans << "\n";

}