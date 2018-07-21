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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n;
    cin >> n;

    vi a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == i) cnt++;
        if(a[a[i]] == i) cnt++;
        if(a[a[a[i]]] == i) cnt++;
    }

    if(1.0 * cnt / n > 0.005) cout << "Petr" << "\n";
    else cout << "Um_nik\n";


}