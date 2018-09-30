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
    cin >> a;

    set <ii> s;

    int v = 0;
    ll res = 0;
    int x, y;

    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '(') v++;
        else if(a[i] == ')') v--;
        else {
            a[i] = ')';
            v--;
            cin >> x >> y;
            res += y;
            s.insert({x - y, i});
        }
        if(v < 0) {
            if(s.empty()) {
                cout << "-1";
                return 0;
            }
            auto t = *s.begin();
            s.erase(s.begin());
            a[t.second] = '(';
            v += 2;
            res += t.first;
        }
    }

    if(v) {
        cout << -1 << "\n";
        return 0;
    }

    cout << res << "\n";
    cout << a << "\n";



}