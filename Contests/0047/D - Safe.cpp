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

    int n, m;
    cin >> n >> m;

    vector <ll> a(m);
    vi b(m);

    for(int i = 0; i < m; i++) {
        string s; int u;
        cin >> s >> u;
        a[i] = stoll(s, nullptr, 2);
        b[i] = u;
    }

    set <ll> cur, temp, ans;

    function <void(int, ll, int)> solve = [&](int id, ll val, int used) {
        if(used == 0) {
            cur.insert(val);
            return;
        }
        if(id >= n) return;
        solve(id + 1, val ^ (1LL << id), used - 1);
        solve(id + 1, val, used);
    };

    solve(0, a[0], b[0]);
    ans = cur;

    for(int i = 1; i < m; i++) {
        cur.clear();
        temp.clear();
        solve(0, a[i], b[i]);
        for(auto el: ans) {
            if(cur.count(el)) {
                temp.insert(el);
            }
        }
        ans = temp;
    }

    cout << ans.size() << "\n";

}