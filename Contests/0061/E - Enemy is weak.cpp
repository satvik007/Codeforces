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
#define LSone(a) ((a) & -(a))


class Fenwick {
public:
    vector <ll> ft;
    int n;
    Fenwick(int _n) {
        n = _n + 1;
        ft.assign(n, 0);
    }
    ll query(int p) {
        ll res = 0;
        for(; p; p -= LSone(p)) {
            res += ft[p];
        }
        return res;
    }
    ll query(int p, int q) {
        return query(q) - query(p - 1);
    }
    void modify(int u, ll v){
        for(; u < n; u += LSone(u)) {
            ft[u] += v;
        }
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vi a(n + 1);

    map <int, int> map1;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        map1[a[i]] = 1;
    }

    reverse(a.begin() + 1, a.end());

    int k = 1;
    for(auto iter = map1.begin(); iter != map1.end(); ++iter) {
        iter -> second = k++;
    }

    for(int i = 1; i <= n; i++) {
        a[i] = map1[a[i]];
    }

    Fenwick f(n), s(n), t(n);

    for(int i = 1; i <= n; i++) {
        t.modify(a[i], s.query(a[i]));
        s.modify(a[i], f.query(a[i]));
        f.modify(a[i], 1);
    }

//    for(int i = 1; i <= n; i++) {
//        cout << a[i] << " ";
//    } cout << "\n";
//
//    for(int i = 1; i <= n; i++) {
//        cout << i << " - (" << f.query(i) << ", " << s.query(i) << ", " << t.query(i) << ")\n";
//    }

    cout << t.query(n) << "\n";

}