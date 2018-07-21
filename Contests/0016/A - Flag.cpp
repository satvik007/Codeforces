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

    int n, m;
    cin >> n >> m;

    vector <string> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = true;

    char last = -1;
    for(int i = 0; i < n; i++) {
        if(last == a[i][0]) flag = false;
        last = a[i][0];
        for(int j = 0; j < m; j++) {
            if(a[i][j] < '0' || a[i][j] > '9') flag = false;
            if(last != a[i][j]) flag = false;
        }
    }

    cout << (flag ? "YES\n": "NO\n");
}