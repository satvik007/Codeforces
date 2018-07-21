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

ll dp[30][30];
ll p[20];
ii path[30][30];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 30; j++) {
            dp[i][j] = -INF;
        }
    }

    dp[0][0] = 0;

    ll base = 1;
    for(int i = 0; i <= n; i++) {
        p[i] = base;
        base *= 10;
    }

    memset(path, -1, sizeof path);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            ll c = dp[i][j] + (s[i + j] - '0') * p[n - i - 1];
            if(dp[i + 1][j] < c) {
                path[i + 1][j] = {i, j};
                dp[i + 1][j] = c;
            }
            c = dp[i][j] + (s[i + j] - '0') * p[n - j - 1];
            if(dp[i][j + 1] < c) {
                path[i][j + 1] = {i, j};
                dp[i][j + 1] = c;
            }
        }
    }

    int f = n, m = n;

    string ans;
    while(!(f == 0 && m == 0)) {
        ii c = path[f][m];
        if(c.first == f) {
            ans += 'H';
            m--;
        } else {
            ans += 'M';
            f--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    //cout << dp[n][n] << "\n";

}