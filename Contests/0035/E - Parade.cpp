#define BZ
/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

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

struct Data {
    int h, l, r;
    bool operator < (Data &a) {
        return h < a.h;
    }
};

Data a[maxn];

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].h >> a[i].l >> a[i].r;
        a[i].r;
    }

    sort(a, a + n);

    map <int, int> map1;
    map1[-INF] = 0;
    map1[INF] = 0;

    for(int i = 0; i < n; i++) {
        auto it1 = map1.upper_bound(a[i].l);
        auto it2 = map1.lower_bound(a[i].r);

        if(it2 -> first != a[i].r) {
            it2 = map1.insert({a[i].r, prev(it2) -> second}).first;
        }

        int cnt = 0;
        while(it1 -> first < it2 -> first) {
            cnt++;
            it1 = map1.erase(it1);
            assert(cnt < maxn);
        }
        map1[a[i].l] = a[i].h;

//        cout << "Step  " << i << "\n";
//        for(auto el: map1) {
//            cout << el.first << " " << el.second << "\n";
//        } cout << "\n\n";
    }

//    for(auto el: map1) {
//        cout << el.first << " " << el.second << "\n";
//    } cout << "\n";

    vector <ii> ans;

    for(auto el: map1) {
        if(el.first == -INF) continue;
        ans.push_back({el.first, el.second});
    }
    int last;

    vector <ii> final;

    for(int i = 0; i < ans.size() - 1; i++) {
        if(i && ans[i].second == ans[i - 1].second) {
            continue;
        }

        if(i) final.push_back({ans[i].first, last});
        else final.push_back({ans[i].first, 0});
        final.push_back(ans[i]);
        last = ans[i].second;
    }

    cout << final.size() << "\n";
    for(int i = 0; i < final.size(); i++) {
        cout << final[i].first << " " << final[i].second << "\n";
    }

}