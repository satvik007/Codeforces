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

    int k = 1;

    vi a(n);

    for(int i = 0; i < n; i += 2) {
        a[i] = k++;
    }
    int i;
    for(i = n - 1; i >= 0; i--) {
        if(a[i] == 0) break;
    }

    for(; i >= 0; i -= 2) {
        a[i] = k++;
    }

    for(auto el: a) cout << el << " "; cout << "\n";

}