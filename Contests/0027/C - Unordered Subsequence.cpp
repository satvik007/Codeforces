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

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(is_sorted(a.begin(), a.end()) || is_sorted(a.begin(), a.end(), greater <int> ())) {
        cout << "0\n";
    } else {
        int i = 0;
        for(; i < n - 1; i++) {
            if(a[i] != a[i + 1])
                break;
        }
        int u = i, v = i + 1, w;
        if(a[i] < a[i + 1]) {
            i += 2;
            for(; i < n; i++) {
                if(a[i] > a[v]) v = i;
                else if(a[i] < a[v]) {
                    w = i;
                    break;
                }
            }
        } else {
            i += 2;
            for(; i < n; i++) {
                if(a[i] < a[v]) v = i;
                else if(a[i] > a[v]) {
                    w = i;
                    break;
                }
            }
        }
        cout << 3 << "\n";
        cout << u + 1 << " " << v + 1 << " " << w + 1 << "\n";

    }

}