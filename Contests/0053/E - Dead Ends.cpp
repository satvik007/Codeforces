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

int n, m, t, x, y, z;
int a[20][20], f[1050][1050];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m >> t;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        a[x][y] = a[y][x] = f[1 << x | 1 << y][1 << x | 1 << y] = 1;
    }

    for(int i = 0; i < (1 << n); i++) {
        for(int j = i; j; --j &= i) {
            if(f[i][j])
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < n; y++) {
                        if(i >> x & 1 && ~i >> y & 1 && a[x][y]) {
                            int u = j & ~(1 << x) | (1 << y);
                            if(!(u >> y + 1))
                                f[i | 1 << y][u] += f[i][j];
                        }
                    }
                }
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        if(__builtin_popcount(i) == t)
            z += f[(1 << n) - 1][i];
    }

    cout << z << "\n";

}