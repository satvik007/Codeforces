// lose small or win big.
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

    string a;
    int k = 0;
    int res = 0;

    while(getline(cin, a)) {
        if(a[0] == '+') {
            k++;
        } else if(a[0] == '-') {
            k--;
        } else {
            int v = a.length() - a.find(':') - 1;
            res += k * v;
        }
    }

    cout << res << "\n";

}