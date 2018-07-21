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

int dp[30][30];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;
    cin >> n >> m;

    vector <string> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = a[i - 1][j - 1] - '0' + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int p = i; p <= n; p++) {
                for(int q = j; q <= m; q++) {
                    int cur = dp[p][q] - dp[p][j - 1] - dp[i - 1][q] + dp[i - 1][j - 1];
                    //cout << i << " " << j << " " << p << " " << q << " " << cur << "\n";
                    if(cur == 0) {
                        ans = max(ans, 2 * (p - i + 1 + q - j + 1));
                    }
                }
            }
        }
    }

    cout << ans << "\n";

}