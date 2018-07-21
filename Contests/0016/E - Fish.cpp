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

double a[20][20];
double dp[(1 << 18) + 5];

int n;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);


    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    dp[(1 << n) - 1] = 1;

    for(int mask = (1 << n) - 1; mask >= 0; mask--) {
        int cnt = __builtin_popcount(mask);
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                for(int j = 0; j < n; j++) {
                    if(mask & (1 << j) && i != j) {
                         dp[mask ^ (1 << j)] += 2 * dp[mask] * a[i][j] / (cnt * (cnt - 1));
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << dp[(1 << i)] << " ";
    }



}