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

vector <vector <ii>> a;
int n;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n;

    a.resize(n + 1);
    ll total = 0;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        total += 2 * w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    queue <int> q;
    q.push(1);

    vector <ll> dist(n + 1, INF);
    vi vis(n + 1, 0);

    dist[1] = 0;
    vis[1] = 1;

    while(!q.empty()) {
        int t = q.front(); q.pop();
        for(auto e: a[t]) {
            if(!vis[e.first]) {
                vis[e.first] = 1;
                dist[e.first] = dist[t] + e.second;
                q.push(e.first);
            }
        }
    }

    int id = 1;
    for(int i = 1; i <= n; i++) {
        if(dist[i] > dist[id]) id = i;
    }

    ll ans;

    function <void(int, int, ll)> dfs = [&](int u, int v, ll sum) {
        if(u == id) {
            ans = sum;
            return;
        }
        for(auto e: a[u]) {
            if(e.first != v) {
                dfs(e.first, u, sum + e.second);
            }
        }
    };

    dfs(1, 0, 0);

    total -= ans;

    cout << total << "\n";

}