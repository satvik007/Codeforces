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

#define maxn ((1 << 22) + 5)

int n, m;
int vis[maxn], used[maxn];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(int i = 0; i < n; i++) {
        if((1 << i) & u)
            dfs(u ^ (1 << i));
    }
    if(used[u])
        dfs((1 << n) - u - 1);
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    cin >> n >> m;

    int u;
    for(int i = 0; i < m; i++) {
        cin >> u; used[u] = 1;
    }

    int ans = 0;
    const int val = 1 << n;

    for(int i = 0; i < (1 << n); i++) {
        if(!used[i] || vis[i]) continue;
        ans++;
        dfs(val - i - 1);
    }

    cout << ans << "\n";

}