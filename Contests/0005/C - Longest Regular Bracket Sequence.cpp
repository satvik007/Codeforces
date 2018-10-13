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

    string a;
    cin >> a;

    stack <int> s;
    int ans = 0, cnt = 1;

    map <int, int> mp;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '(') {
            s.push(i);
        } else {
            if(!s.empty()) {
                int v = s.top(); s.pop();
                int c = i - v + 1 + (mp.count(v - 1) ? mp[v - 1] : 0);
                if(c > ans) {
                    ans = c;
                    cnt = 1;
                } else if(c == ans) {
                    cnt++;
                }
                mp[i] = c;
            }
        }
    }

    cout << ans << " " << cnt << "\n";

}