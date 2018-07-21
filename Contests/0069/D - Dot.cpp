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

const int INF = (int)1e9;

#define maxn 100010

int dx[30], dy[30];
int n, d;
int dp[420][420];

int win(int x, int y, int a, int b) {
    if(dp[x + 210][y + 210]) return dp[x + 210][y + 210];
    int ans = -1;
    for(int i = 0; i < n; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx * tx + ty * ty <= d * d and win(tx, ty, b, a) == -1) ans = 1;
    }
    return dp[x + 210][y + 210] = ans;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int x, y;
    cin >> x >> y >> n >> d;

    for(int i = 0; i < n; i++) {
        cin >> dx[i] >> dy[i];
    }

    int ans = win(x, y, 0, 0);

    cout << ((ans == 1) ? "Anton": "Dasha") << "\n";

}