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

struct Doom {
    int x, y, id;
    Doom(int x, int y, int id) : x(x), y(y), id(id) {}
    Doom () {}
};

bool operator < (Doom a, Doom b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vector <Doom> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a.begin(), a.end());

//    for(int i = 0; i < n; i++) {
//        cout << a[i].x << " " << a[i].y << "\n";
//    } cout << "\n";

    vi dp(n, 0);

    map <int, int> map1;

    dp[n - 1] = 1;
    map1[a[n - 1].x] = n - 1;

    for(int i = n - 2; i >= 0; i--) {
//        for(auto el: map1) {
//            cout << el.first << " " << el.second << "\n";
//        } cout << "\n";
        auto it = map1.upper_bound(a[i].x + a[i].y - 1);
        if(it == map1.begin()) {
            dp[i] = 1;
            map1[a[i].x] = i;
            continue;
        }
        --it;
        dp[i] = it -> second - i + dp[it -> second];
        auto j = map1.begin();
        while(*j != *it) {
            j = map1.erase(j);
        }
        map1.erase(it);
        map1[a[i].x] = i;
    }

    //for(int i = 0; i < n; i++) cout << dp[i] << " "; cout << "\n";

    vi ans(n);

    for(int i = 0; i < n; i++) {
        ans[a[i].id] = dp[i];
    }

    for(auto el: ans) cout << el << " "; cout << "\n";



}