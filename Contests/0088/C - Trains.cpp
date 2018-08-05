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

    ll a, b;
    cin >> a >> b;

    ll lcm = a * b / __gcd(a, b);

    ll cur = 0, v = 0;
    ll f = (lcm - 1) / a;
    ll s = (lcm - 1) / b;

    if(a < b) s++;
    else if(a > b) f++;
    
    if(f > s) {
        cout << "Dasha\n";
    } else if(f == s) {
        cout << "Equal\n";
    } else {
        cout << "Masha\n";
    }


}