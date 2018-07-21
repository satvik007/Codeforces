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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vi a(n);
    vi dp(n, 0);
    vi vis(n, 0);
    vi d(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        d[a[i]]++;
    }

    vector <ii> ans;

    function <int(int)> dfs = [&](int u) {
        if(vis[u]) return dp[u];
        vis[u] = 1;
        dp[u] = u;
        return dp[u] = dfs(a[u]);
    };

    for(int i = 0; i < n; i++) {
        if(d[i] == 0) {
            ans.push_back({dfs(i) + 1, i + 1});
        }
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]) {
            dfs(i);
            ans.push_back({i + 1, i + 1});
        }
    }

    int m = (int) ans.size();

    if(m == 1 && ans[0].first == ans[0].second) {
        cout << "0\n";
    }  else {
        cout << m << "\n";

        for(int i = 0; i < m; i++) {
            cout << ans[i].first << " " << ans[(i + 1) % m].second << "\n";
        }
    }




}