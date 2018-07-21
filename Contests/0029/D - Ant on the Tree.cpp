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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vector <vi> a(n);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }

    vi leaf;
    leaf.push_back(0);
    int edg;
    while(cin >> edg) {
        leaf.push_back(edg - 1);
    }
    leaf.push_back(0);

    vi ans;
    function <void(int, int, vi)> dfs = [&](int u, int v, vi path) {
        if(u == v) {
            ans = path;
            return;
        }
        path.push_back(u);
        for(auto el: a[u]) {
            if(path.size() == 1 || el != path[path.size() - 2]) {
                dfs(el, v, path);
            }
        }
    };

    vi final;

    for(int i = 0; i < leaf.size() - 1; i++) {
        //cout << leaf[i] << " " << leaf[i + 1] << "\n";
        ans.clear();
        dfs(leaf[i], leaf[i + 1], ans);
        //for(auto el: ans) cout << el << " "; cout << "\n";
        copy(ans.begin(), ans.end(), back_inserter(final));
    }

    final.push_back(0);

    map <ii, int> map1;

    bool flag = true;

    for(int i = 0; i < final.size() - 1; i++) {
        ii cur = {final[i], final[i + 1]};
        if(cur.second < cur.first) swap(cur.first, cur.second);
        if(map1.count(cur)) {
            map1[cur]++;
            if(map1[cur] > 2) flag = false;
        } else {
            map1[cur] = 1;
        }
    }

    if(flag) {
        for(auto el: final) {
            cout << el + 1 << " ";
        }
    } else {
        cout << "-1\n";
    }


}