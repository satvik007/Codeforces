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

/*
 * the Power Gem of purple color,
the Time Gem of  color,
the Space Gem of  color,
the Soul Gem of  color,
the Reality Gem of  color,
the Mind Gem of  color.
 */

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    set <string> set1;
    set1.insert("Power");
    set1.insert("Time");
    set1.insert("Space");
    set1.insert("Soul");
    set1.insert("Reality");
    set1.insert("Mind");

    map <string, string> map1;

    map1["purple"] = "Power";
    map1["green"] = "Time";
    map1["blue"] = "Space";
    map1["orange"] = "Soul";
    map1["red"] = "Reality";
    map1["yellow"] = "Mind";


    int n;
    cin >> n;

    string u;
    for(int i = 0; i < n; i++) {
        cin >> u;
        set1.erase(map1[u]);
    }

    cout << set1.size() << "\n";
    for(auto el: set1) cout << el << "\n";

}