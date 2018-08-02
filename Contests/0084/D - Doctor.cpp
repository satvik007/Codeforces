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

    ll n, k;
    cin >> n >> k;

    vi a(n);

    ll cnt = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
    }

    if(cnt == k) {
        return 0;
    } else if(cnt < k) {
        cout << -1 << "\n";
        return 0;
    }

    ll lo = 0, mid, hi = 1e9, v = -1;

    function <bool(int)> solve = [&](int m) {
        ll c = 0;
        for(int i = 0; i < n; i++) {
            c += a[i] <= m ? a[i]: m;
        }
        return c <= k;
    };

    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(solve(mid)) {
            lo = mid + 1;
            v = max(v, mid);
        } else {
            hi = mid - 1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] <= v) {
            k -= a[i];
            a[i] = 0;
        } else {
            a[i] -= v;
            k -= v;
        }
    }

//    cout << k << "\n";
//    for(int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    } cout << "\n";

    vi b;

    v = 0;

    for(int i = 0; i < n; i++) {
        if(!k) {
            v = i;
            break;
        }
        if(a[i]) {
            a[i]--;
            k--;
        }
    }

    for(int i = v; i < n; i++) {
        if(a[i]) b.push_back(i + 1);
    }

    for(int i = 0; i < v; i++) {
        if(a[i]) b.push_back(i + 1);
    }

    n = b.size();

    for(auto el: b) cout << el << " "; cout << "\n";


}