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

    vector <ii> a(n);
    multiset <int> set1;

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
        set1.insert(a[i].second);
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    vi ans;
    for(int i = 0; i < n; i++) {
        int c = *set1.begin();
        ans.push_back(c);
        for(; i < n; i++) {
            if(a[i].first <= c) {
                set1.erase(set1.find(a[i].second));
            } else break;
        }
        i--;
    }

    cout << (int) ans.size() << "\n";
    for(auto el: ans) cout << el << " "; cout << "\n";

}