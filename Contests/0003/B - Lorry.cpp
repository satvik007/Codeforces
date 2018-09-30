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

    int n, v;
    cin >> n >> v;

    vector <ii> a, b;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 1)
            a.push_back({y, i});
        else
            b.push_back({y, i});
    }

    sort(a.begin(), a.end(), greater <ii> ());
    sort(b.begin(), b.end(), greater <ii> ());

    vi ans;
    ll res = 0;
    if ((v % 2) and a.size()) {
        res += a[0].first;
        ans.push_back(a[0].second);
        v--;
        a.erase(a.begin());
    }

    int l = 0, r = 0;
    while(v and (l < a.size() or r < b.size())) {
        int f = 0, s = 0;
        if(l < a.size()) f += a[l].first;
        if(l < a.size() - 1 and v >= 2) f += a[l + 1].first;
        if(r < b.size() and v >= 2) s += b[r].first;
        
        if(f == 0 and s == 0) break;

        if (f > s) {
            if(l < a.size() - 1 and v >= 2) {
                ans.push_back(a[l].second);
                ans.push_back(a[l + 1].second);
                l += 2;
                v -= 2;
            } else if (l < a.size()) {
                ans.push_back(a[l].second);
                l++;
                v--;
            }
            res += f;
        } else {
            if (r < b.size() and v >= 2) {
                ans.push_back(b[r].second);
                r++;
                v -= 2;
            }
            res += s;
        }
    }

    cout << res << "\n";
    for(auto el: ans) {
        cout << el + 1 << " ";
    } cout << "\n";


}