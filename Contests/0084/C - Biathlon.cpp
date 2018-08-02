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
#define sq(x) ((x) * (x))

struct Data {
    ll x, r, id;
    int ans;
    bool operator < (Data a) {
        return x < a.x;
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vector <Data> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].r;
        a[i].id = i;
        a[i].ans = INF;
    }

    sort(a.begin(), a.end());

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;

        int lo = 0, mid, hi = n - 1, v = -1;

        while(lo <= hi) {
            mid = (lo + hi) / 2;
            if(a[mid].x < x) {
                lo = mid + 1;
                v = max(v, mid);
            } else {
                hi = mid - 1;
            }
        }

        if(v != -1) {
            if(sq(a[v].x - x) + sq(y) <= sq(a[v].r))
                a[a[v].id].ans = min(a[a[v].id].ans, i + 1);
        }
        v++;
        if(v <= n - 1 and sq(a[v].x - x) + sq(y) <= sq(a[v].r)) {
            a[a[v].id].ans = min(a[a[v].id].ans, i + 1);
        }

    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].ans != INF) cnt++;
    }

    cout << cnt << "\n";

    for(int i = 0; i < n; i++) {
        if(a[i].ans == INF) cout << -1 << " ";
        else cout << a[i].ans << " ";
    }

}