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

int n, m;
map <string, int> map1;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m;

    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++) {
        string u; cin >> u;
        if(map1.count(u)) map1[u]++;
        else map1[u] = 1;
    }

    vi b;
    for(auto el: map1) {
        b.push_back(el.second);
    }

    sort(b.begin(), b.end());

    ll c1 = 0, c2 = 0;
    for(int i = b.size() - 1; i >= 0; i--) {
        c1 += b[i] * a[b.size() - i - 1];
        c2 += b[i] * a[n - (b.size() - i - 1) - 1];
    }

    cout << c1 << " " << c2 << "\n";

}