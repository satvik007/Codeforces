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

const int INF = (int) 1e9;

#define maxn 100010

int dp[510][30][30];
int memo[510][30][30];
ii path[510][30][30];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;
    cin >> n >> m;

    vector <string> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int p = 0; p < 26; p++) {
            for(int q = 0; q < 26; q++ ){
                if(p != q) {
                    int cnt = 0;
                    for(int j = 0; j < m; j++) {
                        if(j % 2 && a[i][j] != 'a' + p) cnt++;
                        else if(!(j % 2) && a[i][j] != 'a' + q) cnt++;
                    }
                    dp[i][p][q] = cnt;
                } else {
                    dp[i][p][q] = INF;
                }
            }
        }
//        cout << "i -- " << i << "\n";
//        for(int j = 0; j < 5; j++) {
//            for(int k = 0; k < 5; k++) {
//                cout << dp[i][j][k] << " ";
//            }
//            cout << "\n";
//        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++) {
                memo[i][j][k] = INF;
                path[i][j][k] = {-1, -1};
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            memo[0][i][j] = dp[0][i][j];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++) {
                for(int p = 0; p < 26; p++) {
                    for(int q = 0; q < 26; q++) {
                        if(p != j && q != k) {
                            if(memo[i][p][q] > memo[i - 1][j][k] + dp[i][p][q]) {
                                memo[i][p][q] = memo[i - 1][j][k] + dp[i][p][q];
                                path[i][p][q] = {j, k};
                            }
                        }
                    }
                }
            }
        }
//        cout << "i -- " << i << "\n";
//        for(int j = 0; j < 26; j++) {
//            for(int k = 0; k < 26; k++) {
//                cout << memo[i][j][k] << " ";
//            }
//            cout << "\n";
//        }
    }

    int ans = INF;
    int x, y;

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(memo[n - 1][i][j] < ans) {
                ans = memo[n - 1][i][j];
                x = i, y = j;
            }
        }
    }

    cout << ans << "\n";

    vector <ii> res;

    for(int i = n - 1; i >= 0; i--) {
        res.push_back({x, y});
        int tx = path[i][x][y].first;
        int ty = path[i][x][y].second;
        x = tx, y = ty;
    }

    reverse(res.begin(), res.end());

    for(int i = 0; i < n; i++) {
        x = res[i].first, y = res[i].second;
        if(x == -1 || y == -1) break;
        for(int j = 0; j < m; j++) {
            if(j % 2) cout << (char)('a' + x);
            else cout << (char)('a' + y);
        }
        cout << "\n";
    }


}