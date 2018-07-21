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

    int a, b;
    cin >> a >> b;
    int d = __gcd(a, b);

    int n;
    cin >> n;

    vi fac;

    for(int i = 1; i * i <= d; i++) {
        if(d % i == 0) {
            fac.push_back(i);
            fac.push_back(d / i);
        }
    }

    sort(fac.begin(), fac.end());
    fac.resize(unique(fac.begin(), fac.end()) - fac.begin());

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        auto iter = --upper_bound(fac.begin(), fac.end(), v);
        if(*iter >= u) {
            cout << *iter << "\n";
        } else {
            cout << "-1\n";
        }
    }

}