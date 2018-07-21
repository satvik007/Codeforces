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

int n, m, k, s;
int g[maxn];
vi a[maxn];
int dist[maxn][101];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    cin >> n >> m >> k >> s;

    for(int i = 1; i <= n; i++)
        cin >> g[i];


    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    queue <int> q;

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dist[j][i] = INF;
            if(g[j] == i) {
                q.push(j);
                dist[j][i] = 0;
            }
        }
        int cur;
        while(!q.empty()) {
            cur = q.front(); q.pop();
            for(auto v: a[cur]) {
                if(dist[v][i] == INF) {
                    dist[v][i] = dist[cur][i] + 1;
                    q.push(v);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        sort(dist[i] + 1, dist[i] + k + 1);
        ll cur = 0;
        for(int j = 1; j <= s; j++) {
            cur += dist[i][j];
        }
        cout << cur << " ";
    }

    cout << "\n";





}