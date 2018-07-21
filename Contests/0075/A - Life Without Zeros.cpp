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

    string a, b;
    cin >> a >> b;

    int n = stoi(a), m = stoi(b);

    int v = n + m;
    string vs = to_string(v);

    string na, nb;
    for(auto el: a) {
        if(el != '0') na += el;
    }
    if(na.empty()) na = '0';

    for(auto el: b) {
        if(el != '0') nb += el;
    }
    if(nb.empty()) nb = '0';

    string nv;
    for(auto el: vs) {
        if(el != '0') nv += el;
    }
    if(nv.empty()) nb = '0';

    if(stoi(na) + stoi(nb) == stoi(nv)) cout << "YES\n";
    else cout << "NO\n";


}