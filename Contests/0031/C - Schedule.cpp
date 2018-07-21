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
    int x, y, z;
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vector <Data> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
    }

    sort(a.begin(), a.end(), [&](Data x, Data y) {
        return x.x != y.x ? x.x < y.x : x.y != y.y ? x.y < y.y : x.z < y.z;
    });

    vi ans;

    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < n - 1; j++) {
            if(i == j) continue;
            if(j + 1 == i) {
                if(j + 2 < n && a[j + 2].x < a[j].y) {
                    flag = false;
                    break;
                }
                continue;
            }
            if(a[j + 1].x < a[j].y) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans.push_back(a[i].z + 1);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto el: ans) cout << el << " "; cout << "\n";

}