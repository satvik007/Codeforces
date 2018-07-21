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

struct Data {
    int a, b, c;
    bool operator < (const Data &x) {
        if(a != x.a) return a < x.a;
        if(b != x.b) return b > x.b;
        return c < x.c;
    }
};

int n;
Data a[500010];
map <int, int> p;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i].a;
    for(int i = 0; i < n; i++) cin >> a[i].b;
    for(int i = 0; i < n; i++) cin >> a[i].c;

    sort(a, a + n);
    p[INF] = -INF;
    p[-INF] = INF;

    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        auto it = p.upper_bound(a[i].b);
        if(it -> second > a[i].c) ans++;
        else if(p[a[i].b] < a[i].c) {
            p[a[i].b] = a[i].c;
            for(it = --p.lower_bound(a[i].b); it -> second < a[i].c;)
                p.erase(it--);
        }
    }

    cout << ans << "\n";

}