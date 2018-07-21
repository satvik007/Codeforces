/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

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

struct Data {
    int x, y, z;
};

int dp[105][105][12];
Data path[105][105][12];
int a[105][105];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m, k;
    cin >> n >> m >> k; k++;

    vector <string> b(n);

    for(int i = n - 1; i >= 0; i--) {
        cin >> b[i];
        for(int j = 0; j < m; j++) {
            a[i][j] = b[i][j] - '0';
        }
    }

    memset(dp, -1, sizeof dp);
    memset(path, -1, sizeof path);

    for(int i = 0; i < m; i++) {
        dp[0][i][a[0][i] % k] = a[0][i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int p = 0; p < k; p++) {
                if(dp[i][j][p] == -1) continue;
                if(j) {
                    if(dp[i + 1][j - 1][(p + a[i + 1][j - 1]) % k] < dp[i][j][p] + a[i + 1][j - 1]) {
                        dp[i + 1][j - 1][(p + a[i + 1][j - 1]) % k] = dp[i][j][p] + a[i + 1][j - 1];
                        path[i + 1][j - 1][(p + a[i + 1][j - 1]) % k] = {i, j, p};
                    }
                }
                if(j < m - 1) {
                    if(dp[i + 1][j + 1][(p + a[i + 1][j + 1]) % k] < dp[i][j][p] + a[i + 1][j + 1]) {
                        dp[i + 1][j + 1][(p + a[i + 1][j + 1]) % k] = dp[i][j][p] + a[i + 1][j + 1];
                        path[i + 1][j + 1][(p + a[i + 1][j + 1]) % k] = {i, j, p};
                    }
                }
            }
        }
    }

    int ans = -1;
    int ind;

    Data f, s;

    for(int i = 0; i < m; i++) {
        if(dp[n - 1][i][0] > ans) {
            ans = dp[n - 1][i][0];
            f.x = n - 1, f.y = i, f.z = 0;
        }
    }

#ifdef BZ
    for(int q = 0; q < k; q++) {
        cout << "Case " << q << "\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << dp[i][j][q] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
#endif

    if(ans == -1) {
        cout << "-1\n"; return 0;
    }
    cout << ans << "\n";
    string final;

    while(path[f.x][f.y][f.z].x != -1) {
        s = path[f.x][f.y][f.z];
        if(s.y < f.y) {
            final += 'R';
        } else {
            final += 'L';
        }
        f = s;
    }

    cout << s.y + 1 << "\n";

    reverse(final.begin(), final.end());

    cout << final << "\n";

}