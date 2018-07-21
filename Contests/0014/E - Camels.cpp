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

int n, m;
ll dp[30][30][5][3];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m;

    memset(dp, 0, sizeof dp);

    for(int i = 0; i < 3; i++) {
        dp[0][0][i][0] = 1;
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < 4; k++) {
                //cout << i << " " << j << " " << k << "\n";
                //cout << dp[i][j][k][0] << " " << dp[i][j][k][1] << "\n\n";
                if(i == 0) {
                    for(int l = 1; k + l < 4; l++) {
                        dp[i + 1][j][k + l][1] += dp[i][j][k][0];
                    }
                } else {
                    for(int l = 1; l < 4; l++) {
                        if(k + l < 4) {
                            dp[i + 1][j][k + l][1] += dp[i][j][k][0];
                            dp[i + 1][j][k + l][1] += dp[i][j][k][1];
                        }
                        if(k - l >= 0) {
                            dp[i + 1][j + 1][k - l][0] += dp[i][j][k][1];
                            dp[i + 1][j][k - l][0] += dp[i][j][k][0];
                        }
                    }
                }
            }
        }
    }

//    for(int j = 0; j <= m; j++) {
//        cout << "humps = " << j << "\n";
//        cout << "0\n";
//        for(int k = 3; k >= 0; k--) {
//            for(int i = 0; i <= n; i++) {
//                cout << dp[i][j][k][0] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "1\n";
//        for(int k = 3; k >= 0; k--) {
//            for(int i = 0; i <= n; i++) {
//                cout << dp[i][j][k][1] << " ";
//            }
//            cout << "\n";
//        }
//    }

    ll ans = 0;
    for(int i = 0; i < 4; i++) {
        ans += dp[n - 1][m][i][0];
    }

    cout << ans << "\n";


}