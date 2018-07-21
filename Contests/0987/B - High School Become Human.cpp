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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int x, y;
    cin >> x >> y;

    if(x == y) cout << "=";
    else if(x <= 5 && y <= 5) {
        if(pow(x, y) < pow(y, x)) cout << "<";
        else if(pow(x, y) == pow(y, x)) cout << "=";
        else cout << ">";
    } else {
        if(x == 1) cout << "<";
        else if(y == 1) cout << ">";
        else if(x < y) cout << ">";
        else cout << "<";
    }


}