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

    int n, m;
    cin >> n >> m;

    for(int i = n + 1; ; i++) {
        bool flag = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(i == m) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return 0;
        }
    }


}