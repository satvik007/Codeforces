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

    vi a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector <ii> ans;

    for(int i = 0; i < n; i++) {
        int j = i;
        for(; j < n; j++) {
            if(a[i] == b[j]) break;
        }
        for(; j > i; j--){
            ans.push_back({j - 1, j});
            swap(b[j - 1], b[j]);
        }
    }

    cout << ans.size() << "\n";
    for(auto el: ans) {
        cout << el.first + 1 << " " << el.second + 1 << "\n";
    }



}