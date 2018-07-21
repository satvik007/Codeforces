#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <ll> vi;
typedef pair <int, int> ii;

const int INF = (int)1e9;

#define maxn 100010



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;
    cin >> n >> m;

    vector <vi> a(n);
    vi left(n, -INF), right(n, -INF), center(n, -INF), total(n);

    for(int i = 0; i < n; i++) {
        ll u, v;
        cin >> u;
        ll sum = 0;
        ll val = 0;
        for(int j = 0; j < u; j++) {
            cin >> v;
            sum += v;
            val += v;
            center[i] = max(center[i], val);
            if(val < 0) val = 0;
            left[i] = max(sum, left[i]);
            a[i].push_back(v);
        }
        total[i] = sum;
        sum = 0;
        for(int j = u - 1; j >= 0; j--) {
            sum += a[i][j];
            right[i] = max(right[i], sum);
        }
    }

    vector <int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i]; b[i]--;
    }

//    for(int i = 0; i < n; i++) {
//        cout << left[i] << " " << center[i] << " " << right[i] << " " << total[i] << "\n";
//    }

    ll ans = center[b[0]];
    ll c = (right[b[0]] > 0 ? right[b[0]] : 0);

    for(int j = 1; j < m; j++) {
        int i = b[j];
        ans = max(ans, c + left[i]);
        ans = max(ans, center[i]);
        //cout << i << " " << ans << "\n";
        c = max(0LL, max(c + total[i], right[i]));
    }

    cout << ans << "\n";

}