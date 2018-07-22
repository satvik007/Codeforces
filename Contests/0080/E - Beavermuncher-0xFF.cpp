#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <ll, ll> ii;

const int INF = (int)1e9;

#define maxn 100010
int n, st;
vector <vi> a;
vi b;

ii dfs(int u, int v) {
    vector <ii> cur;
    for(auto e: a[u]) {
        if(e == v) continue;
        cur.push_back(dfs(e, u));
    }
    sort(cur.begin(), cur.end(), greater <ii> ());

    ll f = 0, s = b[u] - 1;
    if(u == st) s++;
    for(int i = 0; i < cur.size(); i++) {
        if(s) {
            f += cur[i].first + 2;
            s--;
        } else break;
    }
    for(int i = 0; i < cur.size(); i++) {
        if(s) {
            if(cur[i].second) {
                int val = min(cur[i].second, s);
                s -= val;
                f += val * 2;
            }
        } else break;
    }
    return {f, s};
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n;

    b.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    //for(int i = 1; i <= n; i++) cout << b[i] << " "; cout << "\n";

    a.resize(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cin >> st;

    ii ans = dfs(st, 0);

    cout << ans.first << "\n";

}