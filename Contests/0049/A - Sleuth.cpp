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
    getline(cin, s);

    char last;

    for(auto el: s) {
        if(el >= 'a' && el <= 'z' || el >= 'A' && el <= 'Z') last = el;
    }

    char vow[] = {'a', 'e', 'i', 'o', 'u', 'y'};

    last = tolower(last);

    if(find(vow, vow + 6, last) != vow + 6) cout << "YES\n";
    else cout << "NO\n";


}