// Warten auf das Licht, das nie kommt.
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

    vector <ii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }

    int mi = -INF;
    int ma = INF;

    for(int i = 0; i < n; i++) {
        mi = max(a[i].first, mi);
        ma = min(a[i].second, ma);
    }
    
    if(mi > ma) {
        cout << "-1\n";
    } else if(m >= mi && m <= ma) {
        cout << 0 << "\n";
    } else {
        cout << min(abs(m - ma), abs(m - mi)) << "\n";
    }




}