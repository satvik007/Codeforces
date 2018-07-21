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

int n, h;
ull dp[50][50];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> h;

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            int v = i - j - 1;
            for(int p = 0; p <= j; p++) {
                for(int q = 0; q <= v; q++) {
                    //cout << i << " " << j << " " << p << " " << v << " " << q << " " << dp[j][p] << " " << dp[v][q] << "\n";
                    dp[i][max(p, q) + 1] += dp[j][p] * dp[v][q];
                }
            }
        }
    }
//    cout << "\n";
//    for(int i = 0; i <= 5; i++) {
//        for(int j = 0; j <= 5; j++) cout << dp[i][j] << " "; cout << "\n";
//    }
//    cout << "\n";

    ull cnt = 0;
    for(int i = h; i <= n; i++) {
        cnt += dp[n][i];
    }

    cout << cnt << "\n";

}