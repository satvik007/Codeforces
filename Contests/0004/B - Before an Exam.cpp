// lose small or win big.
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

    int n, sum;
    cin >> n >> sum;

    vector <ii> a(n + 1);

    for(int i = 1; i < n + 1; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vi b(n + 1), c(n + 1);

    for(int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i].first;
        c[i] = c[i - 1] + a[i].second;
    }

    vi ans;

    if(sum < b[n] or sum > c[n]) {
        cout << "NO\n";
    } else {
        for(int i = n; i >= 1; i--) {
            if(sum - a[i].second >= b[i - 1]) {
                sum -= a[i].second;
                ans.push_back(a[i].second);
            } else {
                int v = sum - b[i - 1];
                ans.push_back(v);
                sum = b[i - 1];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for(auto el: ans) {
            cout << el << " ";
        }
        cout << "\n";
    }

}