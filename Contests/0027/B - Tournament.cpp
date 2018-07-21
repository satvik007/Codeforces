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

int a[60][60];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    memset(a, 0, sizeof a);

    int m = n * (n - 1) / 2;

    for(int i = 0; i < m - 1; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        a[u][v] = 1;
    }
    int u, v;
    bool flag = true;
    for(int i = 0; i < n && flag; i++) {
        for(int j = i + 1; j < n; j++) {
            if((a[i][j] | a[j][i]) == 0) {
                u = i, v = j;
                flag = false;
                break;
            }
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] |= (a[i][k] & a[k][j]);
            }
        }
    }

    if(a[u][v]) {
        cout << u + 1 << " " << v + 1 << "\n";
    } else {
        cout << v + 1 << " " << u + 1 << "\n";
    }


}