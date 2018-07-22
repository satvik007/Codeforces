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
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(8);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        if(a == 0 and b == 0) {
            cout << 1.0 << "\n";
        } else if(a == 0) {
            cout << 0.5 << "\n";
        } else if(b == 0) {
            cout << 1.0 << "\n";
        } else {
            double p;
            if(a >= 4 * b) {
                p = 2 * a * b - 2 * b * b;
            } else {
                p = a * b + a * a / 8;
            }
            p /= (2 * a * b);
            cout << p << "\n";
        }
    }

}