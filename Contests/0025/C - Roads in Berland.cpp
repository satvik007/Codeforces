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

int dist[310][310];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int q; cin >> q;

    while(q--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if(w < dist[u][v]) {
            dist[u][v] = dist[v][u] = w;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][u] + dist[v][j] + w < dist[i][j]) {
                        dist[i][j] = dist[i][u] + dist[v][j] + w;
                        dist[j][i] = dist[i][j];
                    }
                }
            }
        }
        ll cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                cnt += dist[i][j];
            }
        }

        cout << cnt << " ";
    }
}