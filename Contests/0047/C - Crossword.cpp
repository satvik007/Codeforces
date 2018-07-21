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

//bool operator < (const vector <string> &a, const vector <string> &b) {
//    for(int i = 0; i < a.size(); i++) {
//        if(a[i] < b[i]) return true;
//        else if(a[i] > b[i]) return false;
//    }
//    return a.size() < b.size();
//};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    vector <string> a(6);

    for(int i = 0; i < 6; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector <string> ans;
    vector <string> cur;

    do {
        if(a[0].back() != a[4].front() || a[0][0] != a[3][0] || a[3].back() != a[1].front() || a[2].front() != a[4].back()
           || a[2].back() != a[5].back() || a[1].back() != a[5].front() || a[1][a[0].size() - 1] != a[4][a[3].size() - 1]) continue;
        if(a[0].size() + a[2].size() != a[1].size() + 1 ||
                a[3].size() + a[5].size() != a[4].size() + 1) continue;

        cur.assign(a[4].size(), string(a[1].size(), '.'));
        copy(a[0].begin(), a[0].end(), cur[0].begin());
        copy(a[1].begin(), a[1].end(), cur[a[3].size() - 1].begin());
        copy(a[2].begin(), a[2].end(), cur[cur.size() - 1].begin() + a[0].size() - 1);

        for(int i = 0; i < a[3].size(); i++) {
            cur[i][0] = a[3][i];
        }
        for(int i = 0; i < a[4].size(); i++) {
            cur[i][a[0].size() - 1] = a[4][i];
        }
        for(int i = 0; i < a[5].size(); i++) {
            cur[i + a[3].size() - 1][cur[0].size() - 1] = a[5][i];
        }
        //for(auto row: cur) {
        //    for(auto el: row) cout << el << " "; cout << "\n";
        //}
        if(ans.empty() || cur < ans) {
            ans = cur;
        }
    } while(next_permutation(a.begin(), a.end()));

    for(auto row: ans) {
        cout << row << "\n";
    }

    if(ans.empty()) cout << "Impossible\n";

}