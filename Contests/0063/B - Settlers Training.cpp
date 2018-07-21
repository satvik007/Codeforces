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

    int n, k;
    cin >> n >> k;

    map <int, int> map1, map2;

    for(int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if(map1.count(u)) map1[u]++;
        else map1[u] = 1;
    }

    int ans = 0;
    map2 = map1;

    while(map2.begin() -> first < k) {
        map1 = map2;
        auto iter = map1.begin();
        while(iter != map1.end()) {
            if(iter -> first >= k) break;
            map2[iter->first]--;
            map2[iter->first + 1]++;
            ++iter;
        }

        iter = map2.begin();
        while(iter != map2.end()) {
            if(iter -> first >= k) break;
            if(iter -> second == 0) iter = map2.erase(iter);
            else ++iter;
        }
        ans++;
    }


    cout << ans << "\n";

}