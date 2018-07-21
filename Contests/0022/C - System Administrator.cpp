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

    int n, m, v;
    cin >> n >> m >> v; v--;

    if((n - 1) * (n - 2) / 2 + 2 <= m || m < n - 1) {
        cout << "-1\n"; return 0;
    }

    set <ii> set1;

    for(int i = 0; i < n && m; i++) {
        if(i == v) continue;
        set1.insert({v, i});
        m--;
    }

    for(int i = 0; i < n && m; i++) {
        if(v == i || v == 0 && i == 1 || v != 0 && i == 0) continue;
        for(int j = 0; j < n && m; j++) {
            if(v == j || v == 0 && j == 1 || v != 0 && j == 0) continue;
            if(j == i || set1.count({j, i})) continue;
            set1.insert({i, j});
            m--;
        }
    }

    for(auto el: set1) {
        cout << el.first + 1 << " " << el.second + 1 << "\n";
    }



}