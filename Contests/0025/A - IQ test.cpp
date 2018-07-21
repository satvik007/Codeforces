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

    int n;
    cin >> n;

    vi a(n);

    int odd, even;
    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2) odd = i + 1, cnt1++;
        else even = i + 1, cnt2++;
    }

    if(cnt1 < cnt2) cout << odd << "\n";
    else cout << even << "\n";


}