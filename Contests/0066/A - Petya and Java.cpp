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

    string s;
    cin >> s;

    string by = "127";
    string sh = "32767";
    string in = "2147483647";
    string lo = "9223372036854775807";

    if(s.size() > lo.size() || s.size() == lo.size() && s > lo) {
        cout << "BigInteger\n";
    } else if(s.size() > in.size() || s.size() == in.size() && s > in) {
        cout << "long\n";
    } else if(s.size() > sh.size() || s.size() == sh.size() && s > sh) {
        cout << "int\n";
    } else if(s.size() > by.size() || s.size() == by.size() && s > by) {
        cout << "short\n";
    } else {
        cout << "byte\n";
    }

}