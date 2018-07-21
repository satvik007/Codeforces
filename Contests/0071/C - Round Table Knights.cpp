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

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ans = false;
    for(int i = n / 3; i >= 1; i--) {
        if(n % i == 0) {
            for(int k = 0; k < i && !ans; k++) {
                bool flag = true;
                for(int j = 0; j + k < n; j += i) {
                    if(!a[j + k]) {
                        flag = false;
                        break;
                    }
                }
                ans |= flag;
            }
        }
    }

    cout << (ans ? "YES\n": "NO\n");

}