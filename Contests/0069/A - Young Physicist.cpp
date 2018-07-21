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

const int INF = (int)1e9;

#define maxn 100010



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vi a(3, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            int u;
            cin >> u;
            a[j] += u;
        }
    }

    for(int i = 0; i < 3; i++) {
        if(a[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

}