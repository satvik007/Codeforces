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

    vi a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0;

    for(; i < n; i++) {
        if(a[i] != i + 1) break;
    }

    if(i == n) {
        cout << "0 0\n"; return 0;
    }

    int j;
    for(j = n - 1; j >= 0; j--) {
        if(a[j] != j + 1) break;
    }

    reverse(a.begin() + i, a.begin() + j + 1);

    for(int k = 0; k < n; k++) {
        if(a[k] != k + 1) {
            cout << "0 0\n";
            return 0;
        }
    }

    cout << i + 1 << " " << j + 1 << "\n";

}