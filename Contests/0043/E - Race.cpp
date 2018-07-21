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
    int v, t;
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, s;
    cin >> n >> s;

    vector <Data> a[110];

    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        for(int j = 0; j < q; j++) {
            int u, v; cin >> u >> v;
            a[i].push_back({u, v});
        }
        for(int j = 0; j < q - 1; j++) {
            a[i][j + 1].t += a[i][j].t;
        }
    }

    ll ans = 0;

    function <void(int, int)> overtakings = [&](int x, int y) {
        int l = 0, r = 0;
        int win = 0;
        int f = 0, s = 0;
        int last = 0;
        while(l < a[x].size() && r < a[y].size()) {
            if(a[x][l].t < a[y][r].t) {
                ll time = a[x][l].t - last;
                f += a[x][l].v * time;
                s += a[y][r].v * time;
                if(s > f) {
                    if(win == 1) ans++;
                    win = 2;
                }
                if(f > s) {
                    if(win == 2) ans++;
                    win = 1;
                }
                last = a[x][l].t;
                l++;
            } else {
                ll time = a[y][r].t - last;
                f += a[x][l].v * time;
                s += a[y][r].v * time;
                if(s > f) {
                    if(win == 1) ans++;
                    win = 2;
                }
                if(f > s) {
                    if(win == 2) ans++;
                    win = 1;
                }
                last = a[y][r].t;
                r++;
            }

        }
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            overtakings(i, j);
        }
    }

    ans /= 2;
    
    cout << ans << "\n";

}