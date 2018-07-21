/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

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

    int n, r1, r2;
    cin >> n >> r1 >> r2;
    r1--; r2--;

    vector <vi> a(n);

    for(int i = 0; i < n; i++) {
        if(i == r1) continue;
        int u; cin >> u;
        u--;
        a[i].push_back(u);
        a[u].push_back(i);
    }
    vi ans(n, -2);

    function <void(int, int)> dfs = [&](int u, int v) {
        for(auto el: a[u]) {
            if(el != v) {
                ans[el] = u;
                dfs(el, u);
            }
        }
    };

    dfs(r2, -1);

    for(int i = 0; i < n; i++) {
        if(i == r2) continue;
        cout << ans[i] + 1 << " ";
    }

    cout << "\n";


}