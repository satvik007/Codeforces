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

    string a, cur;
    stack <string> s;
    map <string, int> map1;

    cin >> a;

    int ans = 0;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= 'A' and a[i] <= 'Z') {
            cur += a[i];
        } else {
            if(cur.size()) {
                ans += map1[cur];
                s.push(cur);
                map1[cur]++;
            }
            cur.clear();
            if(a[i] == '.') {
                map1[s.top()]--; s.pop();
            }
        }
    }

    cout << ans << "\n";

}