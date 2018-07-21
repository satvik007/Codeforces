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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n;
    cin >> n;

    vi a(n);
    vector <ll> b(n);
    vector <ll> dp(n, (1LL << 60));

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll min1 = (1LL << 60);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j] && b[i] < dp[j]) {
                dp[j] = b[i];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                min1 = min(min1, dp[i] + b[i] + b[j]);
            }
        }
    }

    if(min1 == (1LL << 60)) cout << -1 << "\n";
    else cout << min1 << "\n";


}