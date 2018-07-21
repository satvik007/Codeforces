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

    vi a(3 * n);

    map <int, int> map1;

    for(int i = 0; i < 3 * n; i++) {
        cin >> a[i];
        map1[a[i]] = i;
    }

    vector <vi> b(n, vi (3));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
        sort(b[i].begin(), b[i].end(), [&](int u, int v) {
            return map1[u] < map1[v];
        });
    }

    int k;
    cin >> k;

    for(int i = 0; i < n; i++) {
        if(b[i][0] == k) {
            int f = max(b[i][1], b[i][2]);
            int s = min(b[i][1], b[i][2]);
            vi a1, a2;
            for(int p = 0; p < i; p++) {
                for(int q = 0; q < 3; q++) {
                    if(b[p][q] < f) a1.push_back(b[p][q]);
                    else a2.push_back(b[p][q]);
                }
            }
            a1.push_back(f); a1.push_back(s);
            for(int p = i + 1; p < n; p++) {
                for(int q = 0; q < 3; q++) {
                    a2.push_back(b[p][q]);
                }
            }
            sort(a1.begin(), a1.end());
            sort(a2.begin(), a2.end());
            for(auto el: a1) if(el != k) cout << el << " ";
            for(auto el: a2) if(el != k) cout << el << " ";
            cout << "\n";
            return 0;
        }
    }

    for(int i = 1; i <= 3 * n; i++) {
        if(i != k) cout << i << " ";
    }
    cout << "\n";


}