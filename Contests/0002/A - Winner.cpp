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

    map <string, int> map1;
    vector <string> names;
    int k = 0;
    vector <vector <ii>> b;

    for(int i = 0; i < n; i++) {
        string u;
        int v;
        cin >> u >> v;
        if(!map1.count(u)) {
            map1[u] = k++;
            names.push_back(u);
            b.push_back(vector <ii> ());
        }
        int id = map1[u];
        if(b[id].size()) b[id].push_back({b[id].back().first + v, i});
        else b[id].push_back({v, i});
    }

    int ans = -INF;
    for(int i = 0; i < k; i++) {
        ans = max(ans, b[i].back().first);
    }

    int v = INF;
    int aid = -1;

    for(int i = 0; i < k; i++) {
        if(b[i].back().first == ans) {
            for(int j = 0; j < b[i].size(); j++) {
                if(b[i][j].first >= ans and b[i][j].second < v) {
                    v = b[i][j].second;
                    aid = i;
                }
            }
        }
    }

    cout << names[aid] << "\n";





}